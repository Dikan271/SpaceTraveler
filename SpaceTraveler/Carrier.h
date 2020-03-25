#pragma once
#include <Windows.h>
#include <vector>
#include "Planet.h"
#include "LinearPath.h"

typedef std::vector<Planet>::iterator iterPlanet;



class Carrier
{
public:
	Carrier(iterPlanet client, POINT destination);
	bool IsEmptyPath();
	void Move();
private:
	iterPlanet client;
	POINT destination;
	//std::vector<POINT> points;
	void Initialize();
};

