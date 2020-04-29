#pragma once
#include <Windows.h>

class SpaceObject
{
public:
	SpaceObject();
	SpaceObject(int, COLORREF);
	SpaceObject(int);
	SpaceObject(POINT);
	SpaceObject(POINT, int, COLORREF);
	void Show(HDC);
	void Hide(HDC);
	void SetColor(COLORREF);
	void SetPosition(POINT);
	void SetRedius(int);
	int GetRadius();
	POINT GetPosition();
	bool operator== (const SpaceObject &right);
	void Reset();
protected:
	POINT firstPosition;
	POINT position;
	COLORREF color;
	int radiusObject;
};

