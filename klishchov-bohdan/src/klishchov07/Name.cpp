#include "Name.h"

void Name::setName(string name)
{
	this->name = name;
}
void Name::Info()
{
	cout << "The name of country is: " << name << endl;
}
string Name::getName()
{
	return name;
}