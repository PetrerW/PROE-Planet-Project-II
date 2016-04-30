#include "Planet.h"

using namespace std;

Planet::Planet()
{
	planetary_system = "solar system";
	name = "DefaultPlanet";
}

Planet::Planet(string name)
{
	this->name = name;
	planetary_system = "solar system";
}

Planet::~Planet()
{
}

void Planet::save(ostream & s)
{
	s << (*this);
}

string Planet::getName()
{
	return this->name;
}

ostream & operator<<(ostream& out, const Planet & p)
{
	out << p.planetary_system << endl << p.name << endl;
	return out;
}
