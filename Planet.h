#pragma once
#include <string>
using namespace std;
class Planet
{
public:
	Planet();
	Planet(string name);
	virtual ~Planet();
	virtual void beAlive() = 0;
	void save(ostream& s); ///Saving whole object into a file.
	string getName();
	friend ostream& operator<<(ostream& s, const Planet& p);
protected:
	std::string planetary_system;
	std::string name;
	bool alive;
};