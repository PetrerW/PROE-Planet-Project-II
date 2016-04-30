#include "LivingPlanet.h"
#include <iostream>
LivingPlanet::LivingPlanet() : Planet()
{
	beAlive();
}

LivingPlanet::LivingPlanet(string name) : Planet()
{
	this->name = name;
	beAlive();
	this->name = "DefaultLivingPlanet";
}

void LivingPlanet::beAlive()
{
	std::cout << "beAlive virtual function of " << this->name << endl;
	alive = true;
}

ostream & operator<<(ostream & out, const LivingPlanet & LP)
{
	out << *((Planet*)&LP); ///Casting << operator of the base class.
	out << "alive? " << LP.alive << endl;
	return out;
}
