#include "MoveObj.h"

MoveObj::MoveObj()
{
}

MoveObj::~MoveObj()
{
}

iterPlanet MoveObj::GetPlanetIfCollision(UFO ufo, std::list<Planet> *planet)
{
	iterPlanet it = planet->begin();
	for (it++; it != planet->end(); ++it)
	{
		if (IsCollision(ufo, it))
			return it;
	}
	return planet->begin();
}

bool MoveObj::IsCollision(UFO ufo, iterPlanet itPlanet)
{
	POINT posPlayer = ufo.GetPosition();
	POINT posPlanet = itPlanet->GetPosition();
	int dist = GetDistance(posPlayer, posPlanet) - ufo.GetRadius();
	return dist <= itPlanet->GetGravity();
}

int MoveObj::GetDistance(POINT a, POINT b)
{
	double c = pow((b.x - a.x), 2) + pow((b.y - a.y), 2);
	return int(sqrt(c));
}

POINT MoveObj::SetNewPlanetRotate(UFO *ufo, iterPlanet itPlanet)
{
	POINT newCenter = SetNewCenterRotate(ufo, itPlanet);
	SetNewAngle(ufo, newCenter);
	return newCenter;
}

POINT MoveObj::SetNewCenterRotate(UFO *ufo, iterPlanet itPlanet)
{
	POINT newCenterRotat = itPlanet->GetPosition();
	ufo->SetCenterOfRorarion(newCenterRotat);
	ufo->SetDistanse(itPlanet->GetGravity());
	return newCenterRotat;
}

void MoveObj::SetNewAngle(UFO *ufo, POINT point)
{
	double newAngle = ufo->CaltulateAngle(point);
	ufo->SetAngle(newAngle);
}
