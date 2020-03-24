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

void UFO::SetDirectionOfRotation(bool isRight)
{
	direction = isRight;
}

POINT UFO::GetCenterRotation()
{
	return CenterOfRotation;
}

void UFO::Jump()
{
	double shag = speed;
	distance += shag+5;
	position = GetNewPosition(angle, distance);
}

void UFO::RotationMotion()
{
	double shag = speed;
	if (direction)
	{
		angle += shag;
		if (angle > 360)
			angle -= 360;
	}
	else
	{
		angle -= shag;
		if (angle < 0)
			angle += 360;
	}
	position = GetNewPosition(angle, distance);
}

POINT UFO::GetNewPosition(double h, double dist)
{
	POINT p;
	p.x = CenterOfRotation.x + int(dist * cos(h*3.14159265 / 180));
	p.y = CenterOfRotation.y + int(dist * sin(h*3.14159265 / 180));
	return p;
}

