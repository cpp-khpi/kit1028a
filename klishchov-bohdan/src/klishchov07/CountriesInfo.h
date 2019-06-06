#pragma once
#include "Country.h"
#include "Absolute.h"
#include "Area.h"
#include "Constitutional.h"
#include "Democracy.h"
#include "Government.h"
#include "Information.h"
#include "Monarchy.h"
#include "Name.h"
#include "Population.h"
#include "Theocracy.h"

class CountriesInfo
{
private:
	Information information;
	Name name;
	Population population;
	Area area;
	Government government;
	Monarchy monarchy;
	Democracy democracy;
	Absolute absolute;
	Constitutional constitutional;
	Theocracy theocracy;
public:
	void setData(string NAME, int POPULATION, int AREA, string GOVER, string MONARCHY);
	void printInfo(); 
};