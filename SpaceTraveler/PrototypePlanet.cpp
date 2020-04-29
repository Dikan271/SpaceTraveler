#include "PrototypePlanet.h"

PrototypePlanet::PrototypePlanet()
{
}

Planet* PrototypePlanet::createSmallPLanet()
{
	return new Planet(20, RGB(92, 33, 10));
}
Planet* PrototypePlanet::createMiddlePLanet()
{
	return new Planet(50, RGB(30, 140, 160));
}
Planet* PrototypePlanet::createBigPLanet()
{
	return new Planet(80, RGB(170, 165, 50));
}