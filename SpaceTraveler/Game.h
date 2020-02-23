#pragma once
#include <Windows.h>
#include <cmath>
#include "SpaceObject.h"
#include "UFO.h"
#include "Planet.h"

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
	Planet *planet[5];
	POINT startPos;
	POINT GetStPos(HWND);
	void Move();
	void Jump();
	void DrawScene(HWND);
	bool Collision();
	int GetDistance(POINT a, POINT b);
};