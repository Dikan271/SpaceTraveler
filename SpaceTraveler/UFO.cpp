#include "UFO.h"


void UFO::SetCenterOfRorarion(POINT p)
{
	CenterOfRotation.x = p.x;
	CenterOfRotation.y = p.y;
}

void UFO::SetCenterOfRorarion(int x, int y)
{
	CenterOfRotation.x = x;
	CenterOfRotation.y = y;
}

void UFO::SetDistanse(int dist)
{
	distance = radiusObject + dist;
}

void UFO::SetSpeed(int speed)
{
	this->speed = speed;
}

void UFO::SetAngle(int fi)
{
	angle = fi;
}

int UFO::CaltulateAngle(POINT a)
{
	POINT vect;
	vect.x = position.x - a.x;
	vect.y = position.y - a.y;
	return atan(vect.x / vect.x) * 180 / 3.14159265;
}

void UFO::Jump()
{
	double shag = speed;
	distance += shag;
	position = GetNewPosition(angle, distance);
}

void UFO::RotationMotion(bool isJump)
{
	double shag = speed;
	angle += shag;
	position = GetNewPosition(angle, distance);
}

POINT UFO::GetNewPosition(double h, int dist)
{
	POINT p;
	p.x = CenterOfRotation.x + int(dist * cos(h*3.14159265 / 180));
	p.y = CenterOfRotation.y + int(dist * sin(h*3.14159265 / 180));
	return p;
}

