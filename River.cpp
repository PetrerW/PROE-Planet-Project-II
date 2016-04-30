#include "River.h"
#include <iostream>

using namespace std;
River::River()
{
#ifdef _DEBUG
	cout << "Constructing a default River object... " << endl;
#endif
	length = 300;
	name = "River1";
}

River::River(int length, std::string name) :
	length(length), name(name)
{
#ifdef _DEBUG
	cout << "Constructing a non-default River object... " << endl;
#endif
}

bool River::operator>(const River & R)
{
	if (this->length > R.length)
		return true;
	else
		return false;
}