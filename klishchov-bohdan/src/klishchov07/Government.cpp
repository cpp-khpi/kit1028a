#include "Government.h"

void Government::setGover(string gover)
{
	this->gover = gover;
}
void Government::Info()
{
	cout << "The government of country is: " << gover << endl;
}
string Government::getGover()
{
	return gover;
}