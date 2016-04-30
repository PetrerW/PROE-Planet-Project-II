#include "PopulatedPlanet.h"
#include "Satellite.h"

using namespace std;

PopulatedPlanet::PopulatedPlanet() : LivingPlanet()
{
	Continents[0].name = "Europe";
	Continents[1].name = "North America";
	area = 0;
	population = 0;
	beAlive();
	this->name = "DefaultPopulatedPlanet";
}

PopulatedPlanet::PopulatedPlanet(string name) : LivingPlanet()
{
	this->name = name;
	beAlive();
}

void PopulatedPlanet::beAlive()
{
	cout << "beAlive virtual function of " << this->name << endl;
	alive = true;
}

ostream & operator<<(ostream & out, const PopulatedPlanet & PP)
{
	out << (*(LivingPlanet*)&PP); ///We use << operator of the base class LivinPlanet.
	out << "area: " << PP.area << endl << "population: " << PP.population << endl;
	return out;
}
