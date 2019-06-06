#pragma once
#include "CountriesInfo.h"

class Functions
{
private:
	CountriesInfo *countries;
	int size;
public:
	int getSize();
	void setSize(int size);
	void newElements(string *gover, string *monarchy);
	void addElement(string *gover, string *monarchy);
	void printCountries();
	void freeCountries();
	void deleteElement(int index);
	void getByIndex(int index);
};