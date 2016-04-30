// Planet Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Satellite.h"
#include "Country.h"
#include "Continent.h"
#include "Planet.h"
#include "LivingPlanet.h"
#include "PopulatedPlanet.h"
#include "GasPlanet.h"
#include <iostream>
#include <fstream>

using namespace std;

void test();

int main()
{	
		test();

	getchar();
	getchar();

    return 0;
}

void test()
{
	//Planets:
	PopulatedPlanet PopulatedEarth("PopulatedEarth");
	LivingPlanet LivingEarth("LivingEarth");
	GasPlanet GasEarth("GasEarth");
	Planet* Planets[3];
	Planets[0] = &PopulatedEarth;
	Planets[1] = &LivingEarth;
	Planets[2] = &GasEarth;
	//Satellites:
	vector <Satellite*> SatellitesVetor; ///All of the Satellites will be held in a vector.
	Satellite *Orbiter;
	Orbiter = new Satellite("Orbiter", "orbiting", "", 40, 14, 1994);
	Satellite *Spy;
	Spy = new Satellite("Spy", "spying", "", 30, 12, 1987);
	Satellite *TV;
	TV = new Satellite("TV Satellite", "streaming TV", "", 50, 15, 2006);
	Satellite *KampfSatellit;
	KampfSatellit = new Satellite("KampfSatellit", "guarding the peace", "", 35, 13, 2009);
	Satellite *Satellite1;
	Satellite1 = new Satellite("Satellite1", "probes", "", 40, 14, 2010);
	Satellite *Satellite2;
	Satellite2 = new Satellite("Satellite2", "probes", "", 60, 16, 2014);
	SatellitesVetor.push_back(Orbiter);
	SatellitesVetor.push_back(Spy);
	SatellitesVetor.push_back(TV);
	SatellitesVetor.push_back(KampfSatellit);
	SatellitesVetor.push_back(Satellite1);
	SatellitesVetor.push_back(Satellite2);
	//Countries:
	vector <Country*> CountriesVector; ///All of the Countries will be held in a vector too.
	Country *Poland;
	Poland = new Country(38, 313, "Rzeczpospolita Polska", "Warszawa", nullptr);
	Country *Germany;
	Germany = new Country(83, 423, "Bundesrepublik Deutschland", "Berlin", nullptr);
	Country *Canada;
	Canada = new Country(143, 985, "Canada", "Ottawa", nullptr);
	Country *USA;
	USA = new Country(318, 937, "United States of America", "Washington", nullptr);
	Country *France;
	France = new Country(67, 643, "French Republic", "Paris", nullptr);
	CountriesVector.push_back(Poland);
	CountriesVector.push_back(Germany);
	CountriesVector.push_back(Canada);
	CountriesVector.push_back(USA);
	CountriesVector.push_back(France);
	//Continents:
	PopulatedEarth.Continents[0].name = "Europe";
	PopulatedEarth.Continents[1].name = "North America";
	PopulatedEarth.Continents[0][Poland];
	PopulatedEarth.Continents[0][Germany];
	PopulatedEarth.Continents[1][USA];
	PopulatedEarth.Continents[1][Canada];
	PopulatedEarth.Continents[0][France];

	ofstream f[3];
	for (int i = 0; i < 3; i++)
	{
		f[i].open(Planets[i]->getName() + ".txt", ios::out);
		f[i] << *(Planets[i]);
		f[i].close();
	}
		
	delete Spy;
	delete Orbiter;
	delete TV;
	delete Satellite1;
	delete Satellite2;
	delete KampfSatellit;

	delete Poland;
	delete Germany;
	delete Canada;
	delete USA;
}