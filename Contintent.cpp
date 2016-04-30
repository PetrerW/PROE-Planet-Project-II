#include "Continent.h"

int Continent::continents_number = 0;
void Continent::showContinentsNumber()
{
	cout << "There are " << continents_number  << " Continents" << endl;
}

Continent::Continent()
{
#ifdef _DEBUG
	std::cout << "Creating a default Continent object... " << endl;
#endif
	name = "Noname";
	area = 0;
	population = 0;
	continents_number++;
	GreatestCountries = NULL;
}

Continent::Continent(string name) :
	name(name)
{
#ifdef _DEBUG
	std::cout << "Creating a non-default Continent object... " << endl;
#endif
	area = 0;
	population = 0;
	continents_number++;
	GreatestCountries = NULL;
}

Continent::Continent(const Continent & c):
	area(area), population(population)
{
	GreatestCountriesVector = c.GreatestCountriesVector; ///Copy of the Country object vector
}

Continent::~Continent()
{
#ifdef _DEBUG
	std::cout << "Destroing a Continent object... " << endl;
#endif
	GreatestCountriesVector.clear();
}

void Continent::showCountriesNumber()
{
	cout << "There are " << GreatestCountriesVector.size() << " countries in " << name << endl << endl;
}

void Continent::showCountries()
{
	cout << "Countries in " << name << endl;
	vector<Country*>::iterator i;
	int iteration = 0;
	for (int i = 0;  i != GreatestCountriesVector.size(); i++)
	{
		cout << iteration++ << ". " << GreatestCountriesVector[i]->name << endl;
	}
}

void Continent::show()
{
	cout << name << endl;
	showCountries();
	cout << "Area: " << area << endl;
	cout << "Population: " << population << endl;
	showCountriesNumber();
}

void Continent::isCountry()
{
	if (GreatestCountriesVector.size() != 0 )
		cout << "There are countries in " << name << endl;
	else
		cout << "No countries in " << name << endl;
}

Continent::operator int()
{
	return continents_number;
}

void Continent::operator[](Country *NewCountry) ///Adding a Country to the Continent
{
	bool is_here = false;

	for (int i = 0; i < GreatestCountriesVector.size(); i++) ///Checking if the Country is already in the Continent
		if (NewCountry  == GreatestCountriesVector[i])
			is_here = true;

	if (!is_here)
	{
		GreatestCountriesVector.push_back(NewCountry);
		this->population += NewCountry->population; ///Adding the population of the added Country to the Continent
		this->area += NewCountry->area;
	}
	else
		cout << "This country is already in" << name << "!" << endl;
}

void Continent::deleteCountry()
{
	int index;
	vector<Country>::iterator it;
	showCountries();

	cout << "Enter the index of the country you want to delete." << endl;
	cin >> index;

	GreatestCountriesVector.erase(GreatestCountriesVector.begin() + index);
	cout << "deleting succesful!" << endl;
}
