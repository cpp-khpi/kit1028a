#include "Population.h"

void Population::setPopul(int popul)
{
	this->popul = popul;
}
void Population::Info()
{
	cout << "The population of country is: " << popul << endl;
}
int Population::getPopul() 
{
	return popul;
}