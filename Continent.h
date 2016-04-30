#pragma once
#include "Country.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Continent
{
public:
	Continent();
	Continent(string name);
	Continent(const Continent& c);
	~Continent();

	static void showContinentsNumber();
	void showCountriesNumber();
	void showCountries();
	void show();
	void isCountry();

	string name;
	int area; //Sum of the countries' areas. Thousands of km^2.
	int population; //Sum of the countries' populations. Millions of people
	Country *GreatestCountries;
	vector <Country*> GreatestCountriesVector; ///A vector of Greatest Countries instead of dynamically allocated table of pointers

	operator int(); //Return continents_number;
	void operator[](Country* newCountry);
	void deleteCountry(); ///Delete a country from a continent

private:
	static int continents_number;
};