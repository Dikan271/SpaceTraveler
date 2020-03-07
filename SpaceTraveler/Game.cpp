#include "Game.h"

Game::Game()
{
	player = new UFO();
}

Game::~Game()
{
	delete player;
}

void Game::StartGame(HWND hWnd)
{
	startPos = GetStPos(hWnd);
	planet.push_back(Planet(startPos, 50, 10));
	planet.push_back(Planet());
	iterPlanet it = --planet.end();
	it->SetGravity(15);
	player->SetCenterOfRorarion(startPos);
	player->SetRedius(12);
	it = planet.begin();
	player->SetSpeed(10);
	int dist = it->GetGravity();
	player->SetDistanse(dist);
	player->RotationMotion(0);
	moveMode = rotation;

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
	iterPlanet collisionObj = MoveObj::GetPlanetIfCollision(*player, &planet);
	iterPlanet begin = planet.begin();
	if (*collisionObj == *begin)
		player->Jump();
	else
	{
		moveMode = rotation;
		MoveObj::SetNewPlanetRotate(player, collisionObj);
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
