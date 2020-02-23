#pragma once
#include "SpaceObject.h"
#include <stdlib.h>
#include <time.h>

class Planet :
	public SpaceObject
{
public:
	Planet();
	Planet(int r, COLORREF col);
	Planet(POINT pos, int radius, int gravity);
	Planet(POINT pos, int radius, int gravity, COLORREF col);
	~Planet();
	void SetGravity(int);
	int GetGravity();
private:
	int gravity = radiusObject;
	POINT GetRandomPos();
};

