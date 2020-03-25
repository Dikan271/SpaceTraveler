#include "LinearPath.h"

std::vector<POINT> LinearPath::GetPath()
{
	std::vector<POINT> points;
	const float N = 35;
	float t;
	for (int step = 0; step < N; step++)
	{
		t = (float)step / N;
		Lerp_point(t);
		points.push_back(Lerp_point(t));
	}
	return points;
}

POINT LinearPath::Lerp_point(float t)
{
	return { Lerp(beginLine.x, endLine.x, t),
			 Lerp(beginLine.y, endLine.y, t) };
}

int LinearPath::Lerp(int start, int end, float t)
{
	return start + t * (end - start);
}

float LinearPath::GetLen()
{
	return sqrt(pow(endLine.x - beginLine.x, 2) + pow(endLine.y - beginLine.y, 2));
}
