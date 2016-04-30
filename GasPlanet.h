#pragma once
#include "Planet.h"

class GasPlanet : public Planet
{
public:
	GasPlanet();
	GasPlanet(string name);
	void beAlive();
	friend ostream& operator<<(ostream& out, const GasPlanet &GP);
private:
	int gas_concentration;
};