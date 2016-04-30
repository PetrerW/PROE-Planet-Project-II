#pragma once
#include "Planet.h"

class LivingPlanet : public Planet
{
public:
	LivingPlanet();
	LivingPlanet::LivingPlanet(string name);
	void beAlive();
	friend ostream& operator<<(ostream& out, const LivingPlanet &LP);
};