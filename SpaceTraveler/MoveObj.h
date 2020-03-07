#pragma once
#include "Planet.h"
#include "UFO.h"
#include <list>

typedef std::list<Planet>::iterator iterPlanet;

class MoveObj
{
public:
	MoveObj();
	~MoveObj();
	static iterPlanet GetPlanetIfCollision(UFO, std::list<Planet>*);
	static POINT SetNewPlanetRotate(UFO*, iterPlanet);
private:
	static bool IsCollision(UFO, iterPlanet);
	static int GetDistance(POINT, POINT);
	static POINT SetNewCenterRotate(UFO*, iterPlanet);
	static void SetNewAngle(UFO*, POINT);
};

