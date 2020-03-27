#pragma once
#include <stdlib.h>
#include <time.h>
#include "SpaceObject.h"
#include "Planet.h"

class GeneratorObject
{
public:
	GeneratorObject();
	~GeneratorObject();
	Planet GetPlanet();
private:
	enum{ left, middle, right} direction;
	void SetPosition(SpaceObject *planet);
	POINT GetLeftPosition();
	POINT GetMiddlePosition();
	POINT GetRightPosition();
	void SetRadius(SpaceObject *planet);
	void SetGravity(Planet *planet);
};

