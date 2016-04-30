#include "Country.h"
#include "Satellite.h"
#include <iostream>

using namespace std; 

int Country::countries_number = 0;
void Country::ShowCountriesNumber()
{
	cout << "There are " << Country::countries_number << " Country objects." << endl;
}

Country::Country():
	area(0), population(0), capital("No capital"), name("No name"), MainSatellite(nullptr)
{
#ifdef _DEBUG
	std::cout << "Creating a default Country object... " << name <<  endl;
#endif
	countries_number++;
}

Country::~Country()
{
#ifdef _DEBUG
	std::cout << "Destroying a Country object... " << endl;
#endif
	if(this->MainSatellite != nullptr)
		delete this->MainSatellite;
	countries_number--;
}

Country::Country(int population, int area, string name, string capital, Satellite * MainSatellite) :
	population(population), area(area), name(name), capital(capital), MainSatellite(MainSatellite)
{
#ifdef _DEBUG
	cout << "Creating a default Country object..." << name << endl;
#endif
	if (this->MainSatellite != nullptr)
	{
		/*if (this->MainSatellite->owner.length() == 0)
			this->MainSatellite->owner += name;
		else
			this->MainSatellite->owner += (" and " + name); */
		this->MainSatellite->owner = this->name;
	}
	countries_number++;
}

Country& Country::operator=(const Country & c)
{
	if (this != &c)
	{
		if (c.MainSatellite != MainSatellite)
		{
			delete MainSatellite;
		}
		if (c.MainSatellite == nullptr)
			MainSatellite == nullptr;
		else
		{
			MainSatellite = new Satellite();
			*MainSatellite = *(c.MainSatellite);
		}
		name = c.name;
		population = c.population;
		area = c.area;
		capital = c.capital;
	}
	return *this;
}

Country::Country(const Country & c) :
	area(c.area), population(c.population), name(c.name), capital(c.capital)
{
#ifdef _DEBUG
	cout << "Creating a Country object with a copying constructor..." << name << endl;
#endif
	if (c.MainSatellite != nullptr)
	{
		MainSatellite = new Satellite;
		*MainSatellite = *(c.MainSatellite);
	}
	else
		MainSatellite = nullptr;
	countries_number++;
}

void Country::show()
{
	cout << name << endl << "The capital city: " << capital << endl
		<< "population: " << population << " million people" << endl
		<< "area: " << area << " thousands km^2" << endl;
	if (MainSatellite != nullptr)
		cout << "Satellite name: " << (MainSatellite->name) <<  endl << endl;
	else
		cout << "No Satellite assigned" << endl << endl;
}

void Country::ShowSatellite()
{
	if (MainSatellite != nullptr)
		MainSatellite->show();
	else
		cout << "MainSatellite of " << name << " is NULL!" << endl << endl;
}

Country Country::operator+(Satellite & s)
{
	Country Copy(*this);
	if (Copy.MainSatellite != nullptr)
	{
		if (	 !(		*(Copy.MainSatellite) == s	)		 )
			delete Copy.MainSatellite;
	}
	Copy.MainSatellite = new Satellite(s);
	s.owner = Copy.name;
	/*if (s.owner.length() == 0)
		s.owner = Copy.name;
	else if (pos1 == string::npos)  //If name is not found in s.owner
		s.owner += (" and " + Copy.name); */

	return Copy;
}

Country Country::operator-=(Satellite & s)
{
	if (s == *MainSatellite && MainSatellite != NULL)	
	{
		delete this->MainSatellite;
		this->MainSatellite = NULL;
		s.owner = "";
	}
	return *this;
}

Country Country::operator+=(Satellite & s)
{
	*this = *this + s;
	this->MainSatellite->owner = this->name;
	return *this;
}

bool Country::operator==(const Country & c)
{
	bool satellites_are_equal = false;

	if (MainSatellite == nullptr && c.MainSatellite == nullptr)
		satellites_are_equal = true;
	else
	{
		satellites_are_equal = false;
		return false;
	}
		if (area == c.area && capital == c.capital && satellites_are_equal && name == c.name && population == c.population)
			return true;
		else
			return false;
}

void Country::ThereIsSatellite()
{
	if (MainSatellite != nullptr)
		cout << "There is a satellite in " << name << "." << endl;
	else
		cout << "No Satellites in " << name << "." << endl;
}
