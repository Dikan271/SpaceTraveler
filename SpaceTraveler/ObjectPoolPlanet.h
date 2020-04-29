#pragma once
#include "SpaceObject.h"
#include "Planet.h"
#include "PrototypePlanet.h"
#include <list>

class ObjectPoolPlanet
{
public:
	static ObjectPoolPlanet* GetInstance();
	Planet* GetPlanet();
	void ReturnPlanet(Planet* planet);
private:
	std::list<Planet*> planets;
	int count;
	static ObjectPoolPlanet* instance;
	ObjectPoolPlanet();
	~ObjectPoolPlanet();
	Planet* CreatePlanet(int id_planet);
};

