#include "Functions.h"

int Functions::getSize()
{
	return size;
}
void Functions::setSize(int size)
{
	this->size = size;
}
void Functions::newElements(string *gover, string *monarchy)
{
	int tempGOV;
	int tempMON;
	string name;
	int population;
	int area;
	countries = new CountriesInfo[size];
	for (int i = 0; i < size; i++) {
		cout << "Please, enter the name of country: ";
		cin >> name;
		population = rand() % 5467338 + 36729;
		area = rand() % 463782 + 57468;

		tempGOV = rand() % 2 + 0;

		tempMON = rand() % 3 + 0;

		countries[i].setData(name, population, area, gover[tempGOV], monarchy[tempMON]);
	}
}
void Functions::addElement(string *gover, string *monarchy)
{
	int tempGOV;
	int tempMON;
	string name;
	int population;
	int area;

	CountriesInfo *temp = new CountriesInfo[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = countries[i];
	}
	size++;
	cout << "Please, enter the name of country: ";
	cin >> name;
	population = rand() % 5467338 + 36729;
	area = rand() % 463782 + 57468;

	tempGOV = rand() % 2 + 0;

	tempMON = rand() % 3 + 0;


	temp[size - 1].setData(name, population, area, gover[tempGOV], monarchy[tempMON]);
	delete[]countries;
	countries = temp;
}
void Functions::printCountries()
{
	for (int i = 0; i < size; i++)
	{
		countries[i].printInfo();
		cout << endl;
	}
}
void Functions::freeCountries() {
	delete[]countries;
}
void Functions::deleteElement(int index) {
	size--;
	CountriesInfo *temp = new CountriesInfo[size];

	int j = 0;
	for (int i = 0; i < index - 1; i++) {
		temp[i] = Functions::countries[j];
		j++;
	}
	j++;
	for (int i = index - 1; i < size; i++) {
		temp[i] = Functions::countries[j];
		j++;
	}
	delete[]countries;
	countries = temp;
}
void Functions::getByIndex(int index) {
	countries[index - 1].printInfo();
}