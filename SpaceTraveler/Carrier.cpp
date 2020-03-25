#include "Carrier.h"

std::vector<POINT> points;

Carrier::Carrier(iterPlanet client, POINT destination)
{
	this->client = client;
	this->destination = destination;
	if (IsEmptyPath())
		Initialize();
}

bool Carrier::IsEmptyPath()
{
	return points.size() == 0;
}

void Carrier::Move()
{
	if (points.size() != 1)
	{
		client->SetPosition(*points.begin());
		points.erase(points.begin());
	}
	else
	{
		client->SetPosition(destination);
		points.clear();
	}
}

void Carrier::Initialize()
{
	LinearPath path(client->GetPosition(), destination);
	points = path.GetPath();
}
