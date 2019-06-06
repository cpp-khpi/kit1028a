#include "Monarchy.h"

void Monarchy::setMonarchy(string monarchy)
{
	this->monarchy = monarchy;
}
void Monarchy::Info()
{
	cout << "The type of monarchy is: " << monarchy << endl;
}
string Monarchy::getMonarchy()
{
	return monarchy;
}