#pragma once
#include <string>

class River
{
public: 
	River();
	River(int length, std::string name);
	bool operator>(const River &R);
	int length; //In kilometers
	std::string name;
};