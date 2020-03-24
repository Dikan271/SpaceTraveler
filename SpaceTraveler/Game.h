#pragma once
#include <Windows.h>
#include <cmath>
#include <list>
#include "SpaceObject.h"
#include "UFO.h"
#include "Planet.h"
#include "MoveObj.h"

typedef std::list<Planet>::iterator iterPlanet;

class Game
{
public:
	Game();
	~Game();
	void StartGame(HWND);
	LRESULT CALLBACK GameProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
	enum {rotation, jump} gameMode;
	UFO *player;
	std::list<Planet> planets;
	POINT startPos;
	POINT GetStPos(HWND);
	void Move();
	void Jump();
	void DeleteLostPlanets(iterPlanet);
	bool PlayerIsDead(HWND);
	void DrawScene(HWND);
	void GameOver(HWND hWnd, WPARAM wParam, LPARAM lParam);
};