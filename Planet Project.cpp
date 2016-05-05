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
vector <Planet*> PlanetsVector;
PopulatedPlanet PopulatedEarth("PopulatedEarth");
GasPlanet GasJupiter("GasJupiter");
LivingPlanet LivingMars("LivingMars");
PopulatedPlanet PP;
GasPlanet GP;
LivingPlanet LP;
vector <Satellite*> SatellitesVetor; ///All of the Satellites will be held in a vector.
Satellite *Orbiter, *Spy, *TV, *KampfSatellit, *Satellite1, *Satellite2;
vector <Country*> CountriesVector; 	 ///All of the Countries will be held in a vector too.
Country *Poland, *Germany, *Canada, *USA, *France;
void displayMain();
void switch1();
void switch2();
void switch3();
void switch4();

int main()
{	
	///Satellites:
	Orbiter = new Satellite("Orbiter", "orbiting", "", 40, 14, 1994);
	Spy = new Satellite("Spy", "spying", "", 30, 12, 1987);
	TV = new Satellite("TV Satellite", "streaming TV", "", 50, 15, 2006);
	KampfSatellit = new Satellite("KampfSatellit", "guarding the peace", "", 35, 13, 2009);
	Satellite1 = new Satellite("Satellite1", "probes", "", 40, 14, 2010);
	Satellite2 = new Satellite("Satellite2", "probes", "", 60, 16, 2014);
	///Adding Satellites to vector:
	SatellitesVetor.push_back(Orbiter);
	SatellitesVetor.push_back(Spy);
	SatellitesVetor.push_back(TV);
	SatellitesVetor.push_back(KampfSatellit);
	SatellitesVetor.push_back(Satellite1);
	SatellitesVetor.push_back(Satellite2);
	///Countries:
	Poland = new Country(38, 313, "Rzeczpospolita Polska", "Warszawa", nullptr);
	Germany = new Country(83, 423, "Bundesrepublik Deutschland", "Berlin", nullptr);
	Canada = new Country(143, 985, "Canada", "Ottawa", nullptr);
	USA = new Country(318, 937, "United States of America", "Washington", nullptr);
	France = new Country(67, 643, "French Republic", "Paris", nullptr);
	///Adding a Satellite to the Countries:
	*Poland += *Orbiter; 
	*Germany += *KampfSatellit;
	*France += *Satellite1;
	*USA += *TV;
	*Canada += *Satellite2;
	///CountriesVector:
	CountriesVector.push_back(Poland);
	CountriesVector.push_back(Germany);
	CountriesVector.push_back(Canada);
	CountriesVector.push_back(USA);
	CountriesVector.push_back(France);
	///Planets:
	PlanetsVector.push_back(&PopulatedEarth);
	PlanetsVector.push_back(&GasJupiter);
	PlanetsVector.push_back(&LivingMars);
	PlanetsVector.push_back(&PP);
	PlanetsVector.push_back(&GP);
	PlanetsVector.push_back(&LP);

	PopulatedEarth.Continents[0].name = "Europe";
	PopulatedEarth.Continents[1].name = "North America";
	PopulatedEarth.Continents[0].GreatestCountriesVector.push_back(*Poland); ///Adding Countries to Continents
	PopulatedEarth.Continents[0].GreatestCountriesVector.push_back(*Germany);
	PopulatedEarth.Continents[0].GreatestCountriesVector.push_back(*France);
	PopulatedEarth.Continents[0].sumProperties(); ///Summing populations and areas
	PopulatedEarth.Continents[1].GreatestCountriesVector.push_back(*USA);
	PopulatedEarth.Continents[1].GreatestCountriesVector.push_back(*Canada);
	PopulatedEarth.Continents[1].sumProperties();

	PopulatedEarth.sumProperties(); ///Sum properties of the Continents to the Planet

	while (1)
	{
		displayMain();
		int choice;
		cin.exceptions(ifstream::failbit | ifstream::badbit);
		try
		{
			cin >> choice;
		}
		catch(ifstream::failure)
		{
			cout << "Bad input data!" << endl;
		}
		switch (choice)
		{
			case 0: exit(0);
			case 1: switch1(); break;
			case 2: switch2(); break;
			case 3: switch3(); break;
			case 4: switch4(); break;
			default: cout << "Invalid input data" << endl;
		}
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

	getchar();
	getchar();

    return 0;
}


void displayMain()
{
	system("cls");
	cout << "MAIN MENU" << endl
		<< "0 Exit" << endl
		<< "1 See preloaded Planet objects" << endl
		<< "2 See polymorphism" << endl
		<< "3 Save planet to a file" << endl
		<< "4 Retrieve Planet from file" << endl;
}

void switch1()
{
	system("cls");
	for (int i = 0; i < PlanetsVector.size(); i++)
	{
		cout << PlanetsVector[i]->getName() << endl;
	}
	getchar();
	getchar();
}

void switch2()
{
	system("cls");
	Planet *Planets[3];
	Planets[0] = new PopulatedPlanet;
	Planets[1] = new LivingPlanet;
	Planets[2] = new GasPlanet;
	Planets[0] = &PopulatedEarth;
	Planets[1] = &LivingMars;
	Planets[2] = &GasJupiter;
	system("cls");
	cout << "There is a table of 3 pointers. One of them points to PopulatedPlanet, second - LivingPlanet, and the third - GasPlanet." << endl
		<< "Here you can see beAlive() function of each class: " << endl;
	for (int i = 0; i < 3; i++)
	{
		(Planets[i])->beAlive();
	}
	getchar();
	getchar();
}

void switch3()
{
	system("cls");
	ofstream of;
	int choice;
	cout << "Choose the planet: " << endl;
	for (int i = 0; i < PlanetsVector.size(); i++)
	{
		cout << i << " " << PlanetsVector[i]->getName() << endl;
	}
	cin >> choice;
	of.open(PlanetsVector[choice]->getName() + ".txt", ios::out);
	PlanetsVector[choice]->save(of);
	of.close();
	cout << "Saved! " << endl;
	getchar();
	getchar();
}

void switch4()
{
	system("cls");
	ifstream ifs;
	int choice;
	Planet* P;
	cout << "Choose the planet you want to retrieve: " << endl;
	for (int i = 0; i < PlanetsVector.size(); i++)
	{
		cout << i << " " << PlanetsVector[i]->getName() << endl;
	}
	cin >> choice;
	switch (choice)
	{
		case 0:
		case 3:
			P = new PopulatedPlanet(); break;
		case 1:
		case 4:
			P = new GasPlanet(); break;
		case 2:
		case 5:
			P = new LivingPlanet(); break;
		defalt:
			cout << "Invalid input data" << endl;
	}
	P->retrieve(ifs, PlanetsVector[choice]->getName() + ".txt");
	P->save(cout); ///Display retrieved Planet
	ifs.close();

	getchar();
	getchar();
}

