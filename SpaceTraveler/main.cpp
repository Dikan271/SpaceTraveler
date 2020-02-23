#include <windows.h>
#include <string>
#include "KWnd.h"
#include "Game.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

Game game;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	KWnd mainWnd("spase traveler", hInstance, nCmdShow, WndProc);
	HWND hwnd = mainWnd.GetHWnd();
	game.StartGame(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return game.GameProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}
