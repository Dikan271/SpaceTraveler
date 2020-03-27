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
	startPos = GetStartPos(hWnd);
	planets.push_back(Planet(startPos, 60, 10));
	AddPlanet(1);

	player->SetCenterOfRorarion(startPos);
	player->SetRedius(12);
	player->SetSpeed(10);

	int dist = planets[0].GetGravity();
	player->SetDistanse(dist);

	gameMode = rotation;
}


void Game::ReStart(HWND hWnd)
{
	planets.clear();
	StartGame(hWnd);
}


POINT Game::GetStartPos(HWND hWnd)
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
		if(gameMode != update) 
			gameMode = jump;
		break;
	case WM_RBUTTONUP: //for test
		ReStart(hWnd);
					   //DestroyWindow(hWnd);
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
	else if (gameMode == update)
		UpdateLevel();
	else
		RorationPlayer(false);
}

void Game::Jump()
{
	iterPlanet collisionObj = JumpUtility::GetPlanetIfCollision(*player, &planets);
	iterPlanet begin = planets.begin();
	if (*collisionObj == *begin)
		player->Jump();
	else
	{
		gameMode = update;
		JumpUtility::SetNewPlanetRotate(player, collisionObj);
	}
}

void Game::UpdateLevel()
{
	DeletePastPlanets();
	MovingPlanet();
	if(gameMode == rotation)
		AddPlanet(1);
}

void Game::RorationPlayer(bool ifNeedResetPosition)
{
	if(ifNeedResetPosition)
		player->SetCenterOfRorarion(planets.begin()->GetPosition());
	player->RotationMotion();
}

void Game::DeletePastPlanets()
{
	SpaceObject plan(player->GetCenterRotation());
	while (!(*planets.begin() == plan))
	{
		planets.erase(planets.begin());
	}
}

void Game::MovingPlanet()
{
	Carrier carrier(planets.begin(), startPos);
	carrier.Move();
	RorationPlayer(true);
	bool isFinishedMove = carrier.IsEmptyPath();
	if(isFinishedMove)
		gameMode = rotation;
}

void Game::AddPlanet(int count)
{
	GeneratorObject generator;
	for (int i = 0; i < count; i++)
	{
		planets.push_back(generator.GetPlanet());
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
