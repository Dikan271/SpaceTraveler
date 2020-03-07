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

void UFO::SetDistanse(double dist)
{
	distance = radiusObject + dist;
}

void UFO::SetSpeed(double speed)
{
	this->speed = speed;
}

void UFO::SetAngle(double fi)
{
	angle = fi;
}

double UFO::CaltulateAngle(POINT a)
{
	POINT vect;
	vect.x = (a.x - position.x);
	vect.y = (a.y - position.y);
	double at = atan((double)vect.y / (double)vect.x);
	double pi = (180.0 / 3.1415926535);
	double res = at * pi;
	if (position.x < a.x)
		res += 180;
	return  res;
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
	if (angle > 360)
		angle -= 360;
	position = GetNewPosition(angle, distance);
}

POINT UFO::GetNewPosition(double h, double dist)
{
	POINT p;
	p.x = CenterOfRotation.x + int(dist * cos(h*3.14159265 / 180));
	p.y = CenterOfRotation.y + int(dist * sin(h*3.14159265 / 180));
	return p;
}

