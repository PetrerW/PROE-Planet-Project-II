#include "Satellite.h"
#include <iostream>
using namespace std;

int Satellite::satellites_number = 0;
void Satellite::showNumberOfSatellites()
{
	cout << "There are " << Satellite::satellites_number << " Satellite objects." << endl;
}

Satellite::Satellite()
{
#ifdef _DEBUG
	cout << "Creating a default Satellite object... " << name << endl;
#endif
	satellites_number++;
	name = "Orbiter";
	role = "TV Satellite";
	owner = "USA";
	radius = 50;
	velocity = 10;
	initiation_year = 1996;
}

Satellite::Satellite(string name, string role, string owner)
{
#ifdef _DEBUG
	cout << "Creating a non-default (1) Satellite object... " << name << endl;
#endif
	satellites_number++;

	this->name = name;
	this->role = role;
	this->owner = owner; 
	radius = 50;
	velocity = 10;
	initiation_year = 1996;
}

Satellite::Satellite(string name, string role, string owner, int radius, int velocity, int initiation_year) :
	name(name), role(role), owner(owner), radius(radius), velocity(velocity), initiation_year(initiation_year)
{
#ifdef _DEBUG
	std::cout << "Creating a non-default (2) Satellite object... " << name << endl;
#endif
	satellites_number++;
}

Satellite::Satellite(const Satellite & s)
{
	name = s.name;
	role = s.role;
	owner = s.owner;
	radius = s.radius;
	velocity = s.velocity;
	initiation_year = s.initiation_year;

	satellites_number++;
}

Satellite::~Satellite()
{
#ifdef _DEBUG
	std::cout << "Destroying a Satellite object... " << endl;
#endif
	satellites_number--;
}

void Satellite::show()
{
	if (this != NULL)
	{
		cout << "name: " << name << endl;
		cout << "role: " << role << endl;
		cout << "owner: " << owner << endl;
		cout << "radius: " << radius << endl;
		cout << "velocity: " << velocity << endl;
		cout << "initiation year: " << initiation_year << endl << endl;
	}
	else
		cout << "The Satellite object is a nullptr" << endl << endl;
}

int Satellite::findMin(int radius1, int radius2)
{
	if (radius1 < radius2)
		return radius1;
	else
		return radius2;
}

Satellite Satellite::operator-(const Satellite & s)
{
	return Satellite(name, owner, role, 5 + abs(radius - s.radius), 5 + abs(velocity - s.velocity), 2016);
}

Satellite& Satellite::operator=(const Satellite & s)
{
	if (&s != NULL)
	{
		name = s.name;
		role = s.role;
		owner = s.owner;
		radius = s.radius;
		velocity = s.velocity;
		initiation_year = s.initiation_year;
	}
	return *this;
}

bool Satellite::operator==(const Satellite &s)
{
	if (this->name == s.name)
		return true;
	else
		return false;
}

Satellite Satellite::operator-=(const Satellite & s)
{
	*this = *this - s;
	return *this;
}