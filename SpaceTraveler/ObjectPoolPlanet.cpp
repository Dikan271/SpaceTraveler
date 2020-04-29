#include "ObjectPoolPlanet.h"

ObjectPoolPlanet * ObjectPoolPlanet::GetInstance()
{
	if (instance == 0)
	{
		instance = new ObjectPoolPlanet;
	}
	return instance;
}

Planet * ObjectPoolPlanet::GetPlanet()
{
	if (count < 50)
	{
		int planet_id = rand() % 3;
		Planet* temp = CreatePlanet(planet_id);
		planets.push_back(temp);
		count++;
	}
	Planet* planet = planets.front();
	planets.pop_front();
	return planet;
}

void ObjectPoolPlanet::ReturnPlanet(Planet * planet)
{
	planet->Reset();
	planets.push_back(planet);
}

ObjectPoolPlanet::ObjectPoolPlanet()
{
	count = 0;
}


ObjectPoolPlanet::~ObjectPoolPlanet()
{
}

Planet * ObjectPoolPlanet::CreatePlanet(int id_planet)
{
	PrototypePlanet prototype;
	Planet* planet;
	switch (id_planet)
	{
	case 0:
		planet = prototype.createSmallPLanet();
		break;
	case 1:
		planet = prototype.createMiddlePLanet();
		break;
	default:
		planet = prototype.createBigPLanet();
		break;
	}
	return planet;
}

