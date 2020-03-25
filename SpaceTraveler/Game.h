#pragma once
#include <Windows.h>
#include <cmath>
#include <vector>
#include "SpaceObject.h"
#include "UFO.h"
#include "Planet.h"
#include "JumpUtility.h"
#include "Carrier.h"

typedef std::vector<Planet>::iterator iterPlanet;

class Game
{
public:
	Game();
	~Game();
	void StartGame(HWND);
	LRESULT CALLBACK GameProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
	enum {rotation, jump, update} gameMode;
	UFO *player;
	std::vector<Planet> planets;
	POINT startPos;
	POINT GetStartPos(HWND);
	void Move();
	void Jump();
	void UpdateLevel();
	void DeletePastPlanets(iterPlanet);
	void MovingPlanet();
	bool PlayerIsDead(HWND);
	void DrawScene(HWND);
	void GameOver(HWND hWnd, WPARAM wParam, LPARAM lParam);
};