#include "Game.h"

Game::Game()
{
	player = new UFO();
}

Game::~Game()
{
}

void Game::StartGame(HWND hWnd)
{
	startPos = GetStPos(hWnd);
	planet.push_back(Planet(startPos, 50, 10));
	planet.push_back(Planet());
	planet.end()->SetGravity(15);
	player->SetCenterOfRorarion(startPos);
	player->SetRedius(15);
	player->SetSpeed(10);
	int dist = planet.begin()->GetGravity();
	player->SetDistanse(dist);
}

POINT Game::GetStPos(HWND hWnd)
{
	RECT rt;
	GetClientRect(hWnd, &rt);
	POINT p;
	p.x = rt.right / 2;
	p.y = rt.bottom -100;
	return p;
}

LRESULT Game::GameProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		SetTimer(hWnd, 0, 100, NULL);
		break;
	case WM_LBUTTONDOWN:
		moveMode = jump;
		break;
	case WM_PAINT:
		DrawScene(hWnd);
		break;
	case WM_TIMER:
		Move();
		RECT rect;
		GetClientRect(hWnd, &rect);
		InvalidateRect(hWnd, &rect, 1);
		SetTimer(hWnd, 0, 50, NULL);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

void Game::Move()
{
	if (moveMode == jump)
		Jump();
	else player->RotationMotion(0);
}

void Game::Jump()
{
	iterPlanet collisionObj = GetPlanetIfCollision();
	if (collisionObj == planet.begin())
		player->Jump();
	else
	{
		moveMode = rotation;
		POINT newCenterRotat = SetNewCenterRotate(planet.end());
		double newAngle = player->CaltulateAngle(newCenterRotat);
		player->SetAngle(newAngle);
	}
}

void Game::DrawScene(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	player->Show(hdc);
	for (auto it = planet.begin(); it != planet.end(); ++it)
	{
		it->Show(hdc);
	}
	EndPaint(hWnd, &ps);
}

iterPlanet Game::GetPlanetIfCollision()
{
	iterPlanet it = planet.begin();
	for (it++; it != planet.end(); ++it)
	{
		if (IsCollision(it))
			return it;
	}
	return planet.begin();
}

bool Game::IsCollision(iterPlanet itPlanet)
{
	POINT posPlayer = player->GetPosition();
	POINT posPlanet = itPlanet->GetPosition();
	int dist = GetDistance(posPlayer, posPlanet);
	return dist <= itPlanet->GetGravity();
}

int Game::GetDistance(POINT a, POINT b)
{
	double c = pow((b.x - a.x), 2) + pow((b.y - a.y), 2);
	return int(sqrt(c)) - player->GetRadius();
}

POINT Game::SetNewCenterRotate(iterPlanet itPlanet)
{
	POINT newCenterRotat = itPlanet->GetPosition();
	player->SetCenterOfRorarion(newCenterRotat);
	player->SetDistanse(itPlanet->GetGravity());
	return newCenterRotat;
}
