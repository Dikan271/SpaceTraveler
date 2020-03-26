#pragma once
#include <Windows.h>

class SpaceObject
{
public:
	SpaceObject();
	SpaceObject(int, COLORREF);
	SpaceObject(int);
	SpaceObject(POINT);
	void Show(HDC);
	void Hide(HDC);
	void SetColor(COLORREF);
	void SetPosition(POINT);
	void SetRedius(int);
	int GetRadius();
	POINT GetPosition();
	bool operator== (const SpaceObject &right);

protected:
	POINT position;
	COLORREF color;
	int radiusObject;
};

