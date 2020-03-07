#include "SpaceObject.h"

SpaceObject::SpaceObject()
{
	radiusObject = 50;
	color = RGB(60, 140, 212);
}

SpaceObject::SpaceObject(int radius, COLORREF col) :SpaceObject()
{
	radiusObject = radius;
	color = col;
}

SpaceObject::SpaceObject(int radius) :SpaceObject()
{
	radiusObject = radius;
}

void SpaceObject::Show(HDC hdc)
{
	HBRUSH MyPen, OldPen;
	MyPen = CreateSolidBrush(color);
	OldPen = (HBRUSH)SelectObject(hdc, MyPen);
	Ellipse(hdc, position.x - radiusObject, position.y - radiusObject, position.x + radiusObject, position.y + radiusObject);
	SelectObject(hdc, OldPen);
	DeleteObject(MyPen);
}

void SpaceObject::Hide(HDC hdc)
{
	HBRUSH MyPen, OldPen;
	MyPen = (HBRUSH)GetStockObject(BLACK_BRUSH);
	OldPen = (HBRUSH)SelectObject(hdc, MyPen);
	Ellipse(hdc, position.x - radiusObject, position.y - radiusObject, position.x + radiusObject, position.y + radiusObject);
	SelectObject(hdc, OldPen);
	DeleteObject(MyPen);
}

void SpaceObject::SetColor(COLORREF col)
{
	color = col;
}

void SpaceObject::SetPosition(POINT pos)
{
	position = pos;
}

void SpaceObject::SetRedius(int radius)
{
	radiusObject = radius;
}

int SpaceObject::GetRadius()
{
	return radiusObject;
}

POINT SpaceObject::GetPosition()
{
	return position;
}

bool SpaceObject::operator==(const SpaceObject & right)
{
	return(this->position.x == right.position.x
		&& this->position.y == right.position.y);
}
