#include "GasPlanet.h"
#include <iostream>

GasPlanet::GasPlanet() : Planet()
{
	gas_concentration = 100; ///Concantrations of average one of CO2 on Earth
	beAlive();
	this->name = "DefaultGasPlanet";
}

GasPlanet::GasPlanet(string name): Planet()	
{
	this->name = name;
	beAlive();
}

void GasPlanet::beAlive()
{
	cout << "beAlive virtual function of " << this->name << endl;
	alive = false;
}

ostream & operator<<(ostream & out, const GasPlanet & GP)
{
	out << *((Planet*)&GP); ///We cast << operator of the basic Planet class.
	out << "Gas concentration: " << GP.gas_concentration << endl;
	out << "alive? " << GP.alive << endl;
	return out;
}
