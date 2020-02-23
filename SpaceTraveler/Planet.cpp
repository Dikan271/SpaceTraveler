#include "Planet.h"

Planet::Planet()
{
	position = GetRandomPos();
}

Planet::Planet(int r, COLORREF col) : SpaceObject(r, col) 
{
	position = GetRandomPos();
}

Planet::Planet(POINT pos, int radius, int gravity)
	: SpaceObject(radius)
{
	position = pos;
	this->gravity = radius + gravity;
}

Planet::Planet(POINT pos, int radius, int gravity, COLORREF col)
	: Planet(pos, radius, gravity)
{
	color = col;
}

Planet::~Planet()
{
}

void Planet::SetGravity(int g)
{
	gravity = radiusObject + g;
}

int Planet::GetGravity()
{
	return gravity;
}

POINT Planet::GetRandomPos()
{
	POINT p;
	srand((unsigned)time(0));
	p.x = rand() % 370 + 100;
	p.y = rand() % 370 + 100;
	return p;
}
