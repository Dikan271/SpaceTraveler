#include "GeneratorObject.h"

GeneratorObject::GeneratorObject()
{
	srand((unsigned)time(0));
	int x = rand()%2;
	switch (x)
	{
	case 0:
		direction = left;
	case 1:
		direction = middle;
		break;
	case 2:
		direction = right;
		break;
	default:
		break;
	}
}

GeneratorObject::~GeneratorObject()
{
}

Planet GeneratorObject::GetPlanet()
{
	Planet planet;
	//SetPosition(&planet);
	SetRadius(&planet);
	SetGravity(&planet);
	return planet;
}

void GeneratorObject::SetPosition(SpaceObject *object)
{
	POINT position;
	switch (direction)
	{
	case GeneratorObject::left:
		position = GetLeftPosition();
		break;
	case GeneratorObject::middle:
		position = GetMiddlePosition();
		break;
	case GeneratorObject::right:
		position = GetRightPosition();
		break;
	}
	object->SetPosition(position);
}

POINT GeneratorObject::GetLeftPosition()
{
	srand((unsigned)time(0));
	POINT p;
	p.x = rand() % 100 + 50;
	p.y = rand() % 400 + 50;
	return p;
}

POINT GeneratorObject::GetMiddlePosition()
{
	srand((unsigned)time(0));
	POINT p;
	p.x = rand() % 100 + 250;
	p.y = rand() % 350 + 50;
	return p;
}

POINT GeneratorObject::GetRightPosition()
{
	srand((unsigned)time(0));
	POINT p;
	p.x = rand() % 350 + 200;
	p.y = rand() % 400 + 50;
	return p;
}

void GeneratorObject::SetRadius(SpaceObject *object)
{
	srand((unsigned)time(0));
	int radius = rand() % 50 + 30;
	object->SetRedius(radius);
}

void GeneratorObject::SetGravity(Planet *planet)
{
	srand((unsigned)time(0));
	int gravity = rand() % 10 + 20;
	planet->SetGravity(gravity);
}
