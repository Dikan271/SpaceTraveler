#pragma once
#include "Planet.h"
#include "UFO.h"
#include <vector>

typedef std::vector<Planet>::iterator iterPlanet;

class JumpUtility
{
public:
	JumpUtility();
	~JumpUtility();
	static iterPlanet GetPlanetIfCollision(UFO, std::vector<Planet>*);
	static POINT SetNewPlanetRotate(UFO*, iterPlanet);
private:
	static bool IsCollision(UFO, iterPlanet);
	static int GetDistance(POINT, POINT);
	static POINT SetNewCenterRotate(UFO*, iterPlanet);
	static double SetNewAngle(UFO*, POINT);
	static void SetRotation(UFO*, POINT lastP, POINT newP, double angle);
	static double CaltulateAngle(POINT a, POINT b);
};

