#pragma once
#include "Continent.h"
#include "LivingPlanet.h"
#include <string>

using namespace std; 

class PopulatedPlanet : public LivingPlanet
{
public:
	PopulatedPlanet();
	PopulatedPlanet(string name);
	void beAlive();
	Continent Continents[2];
	friend ostream& operator<<(ostream& out, const PopulatedPlanet &PP);
private:
	int area;
	int population;
};

