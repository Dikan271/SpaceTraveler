#include "Game.h"

Game::Game()
{
	player = new UFO();
}

Game::~Game()
{
	for (int i = 0; i < 5; i++)
	{
		delete planet[i];
	}
}

void Game::StartGame(HWND hWnd)
{
	startPos = GetStPos(hWnd);
	planet[0] = new Planet(startPos, 50, 10);
	planet[1] = new Planet();
	planet[1]->SetGravity(15);
	player->SetCenterOfRorarion(startPos);
	player->SetRedius(15);
	player->SetSpeed(10);
	int dist = planet[0]->GetGravity();
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
	if (!Collision())
		player->Jump();
	else
	{
		moveMode = rotation;
		POINT newCenterRotat = planet[1]->GetPosition();
		player->SetCenterOfRorarion(newCenterRotat);
		player->SetDistanse(planet[1]->GetGravity());
		int newangle = player->CaltulateAngle(newCenterRotat);
		player->SetAngle(newangle);
	}
}

void Game::DrawScene(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	player->Show(hdc);
	for (int i = 0; i < 5; i++)
	{
		if(planet[i]!= nullptr)
			planet[i]->Show(hdc);
	}
	EndPaint(hWnd, &ps);
}

bool Game::Collision()
{
	int dist = GetDistance( player->GetPosition(), planet[1]->GetPosition() );
	return dist - player->GetRadius() <= planet[1]->GetGravity();
}

int Game::GetDistance(POINT a, POINT b)
{
	int c = pow((b.x - a.x), 2) + pow((b.y - a.y), 2);
	return int(sqrt(c));
}