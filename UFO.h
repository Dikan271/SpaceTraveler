#pragma once
#include "SpaceObject.h"
#include <math.h>

class UFO :
	public SpaceObject
{
public:
	UFO() : SpaceObject(10) {};
	UFO(int r, COLORREF col) : SpaceObject(r, col) {};
	UFO(int r) : SpaceObject(r) {};
	void SetCenterOfRorarion(POINT);
	void SetCenterOfRorarion(int, int);
	void SetDistanse(double);
	void SetSpeed(double);
	void SetAngle(double);
	int CaltulateAngle(POINT);
	void RotationMotion	(bool);
	void Jump();

private:
	POINT CenterOfRotation;
	double distance = radiusObject;
	int angle;
	double speed = 5;
	POINT GetNewPosition(double, double);
};

