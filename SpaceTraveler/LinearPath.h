#pragma once
#include <Windows.h>
#include <cmath>
#include <vector>

class LinearPath
{
public:
	LinearPath(POINT a, POINT b)
		:beginLine(a), endLine(b) { };
	std::vector<POINT> GetPath();

private:
	POINT beginLine;
	POINT endLine;
	POINT Lerp_point(float t);
	int Lerp(int start, int end, float t);
	float GetLen();
};
