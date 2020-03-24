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
	planets.push_back(Planet(startPos, 50, 10));
	planets.push_back(Planet());
	iterPlanet it = --planets.end();
	it->SetGravity(15);
	player->SetCenterOfRorarion(startPos);
	player->SetRedius(12);
	it = planets.begin();
	player->SetSpeed(10);
	int dist = it->GetGravity();
	player->SetDistanse(dist);
	gameMode = rotation;
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
		gameMode = jump;
		break;
	case WM_RBUTTONUP: //for test
		DestroyWindow(hWnd);
		break;
	case WM_PAINT:
		DrawScene(hWnd);
		break;
	case WM_TIMER:
		Move();
		if (PlayerIsDead(hWnd))
			GameOver(hWnd, wParam, lParam);
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
	if (gameMode == jump)
		Jump();
	else player->RotationMotion();
}

void Game::Jump()
{
	iterPlanet collisionObj = MoveObj::GetPlanetIfCollision(*player, &planets);
	iterPlanet begin = planets.begin();
	if (*collisionObj == *begin)
		player->Jump();
	else
	{
		gameMode = rotation;
		MoveObj::SetNewPlanetRotate(player, collisionObj);
		DeletePastPlanets(collisionObj);
	}
}

void Game::DeletePastPlanets(iterPlanet itPlanet)
{
	while (planets.begin() != itPlanet)
	{
			planets.pop_front();
	}
}

bool Game::PlayerIsDead(HWND hWnd)
{
	POINT locationPlayer = player->GetPosition();
	RECT sizeWin;
	GetWindowRect(hWnd, &sizeWin);
	return (locationPlayer.x <= 0 || locationPlayer.x >= sizeWin.right)
		|| (locationPlayer.y <= 0 || locationPlayer.y >= sizeWin.bottom);
}

void Game::DrawScene(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	player->Show(hdc);
	for (auto it = planets.begin(); it != planets.end(); ++it)
	{
		it->Show(hdc);
	}
	EndPaint(hWnd, &ps);
}

void Game::GameOver(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
//	MessageBox(hWnd, "Game over\nYou are dead", "Game Over", MB_OK);
	SendMessage(hWnd, WM_CLOSE, wParam, lParam);
}
