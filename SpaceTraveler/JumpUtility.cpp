#include "JumpUtility.h"

JumpUtility::JumpUtility()
{
}

JumpUtility::~JumpUtility()
{
}

iterPlanet JumpUtility::GetPlanetIfCollision(UFO ufo, std::vector<Planet> *planet)
{
	iterPlanet it = planet->begin();
	for (it++; it != planet->end(); ++it)
	{
		if (IsCollision(ufo, it))
			return it;
	}
	return planet->begin();
}

bool JumpUtility::IsCollision(UFO ufo, iterPlanet itPlanet)
{
	POINT posPlayer = ufo.GetPosition();
	POINT posPlanet = itPlanet->GetPosition();
	int dist = GetDistance(posPlayer, posPlanet) - ufo.GetRadius();
	return dist <= itPlanet->GetGravity();
}

int JumpUtility::GetDistance(POINT a, POINT b)
{
	double c = pow((b.x - a.x), 2) + pow((b.y - a.y), 2);
	return int(sqrt(c));
}

POINT JumpUtility::SetNewPlanetRotate(UFO *ufo, iterPlanet itPlanet)
{
	POINT lastCenter = ufo->GetCenterRotation();
	POINT newCenter = SetNewCenterRotate(ufo, itPlanet);
	double angle = SetNewAngle(ufo, newCenter);
	SetRotation(ufo, lastCenter, newCenter, angle);
	return newCenter;
}

POINT JumpUtility::SetNewCenterRotate(UFO *ufo, iterPlanet itPlanet)
{
	POINT newCenterRotat = itPlanet->GetPosition();
	ufo->SetCenterOfRorarion(newCenterRotat);
	ufo->SetDistanse(itPlanet->GetGravity());
	return newCenterRotat;
}

double JumpUtility::SetNewAngle(UFO *ufo, POINT point)
{
	double newAngle = CaltulateAngle(ufo->GetPosition(), point);
	ufo->SetAngle(newAngle);
	return newAngle;
}

void JumpUtility::SetRotation(UFO* ufo, POINT lastP, POINT newP, double newAngle)
{
	double anglelastToNew = CaltulateAngle(lastP, newP);
	bool direction = (newAngle - anglelastToNew > 0);
	ufo->SetDirectionOfRotation(direction);
}

double JumpUtility::CaltulateAngle(POINT a, POINT b)
{
	POINT vect;
	vect.x = (b.x - a.x);
	vect.y = (b.y - a.y);
	double at = atan((double)vect.y / (double)vect.x);
	double pi = (180.0 / 3.1415926535);
	double res = at * pi;
	if (a.x < b.x)
		res += 180;
	return  res;
}
