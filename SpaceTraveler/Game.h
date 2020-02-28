#pragma once
#include <Windows.h>
#include <cmath>
#include <list>
#include "SpaceObject.h"
#include "UFO.h"
#include "Planet.h"

typedef std::list<Planet>::iterator iterPlanet;

class Game
{
public:
	Game();
	~Game();
	void StartGame(HWND);
	LRESULT CALLBACK GameProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
	enum {rotation, jump} moveMode;
	UFO *player;
	std::list<Planet> planet;
	POINT startPos;
	POINT GetStPos(HWND);
	void Move();
	void Jump();
	void DrawScene(HWND);
	iterPlanet GetPlanetIfCollision();
	bool IsCollision(iterPlanet);
	int GetDistance(POINT a, POINT b);
	POINT SetNewCenterRotate(iterPlanet);
};