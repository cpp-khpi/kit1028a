#include "CountriesInfo.h"

void CountriesInfo::setData(string NAME, int POPULATION, int AREA, string GOVER, string MONARCHY) {

	name.setName(NAME);
	information.Info(&name);

	population.setPopul(POPULATION);
	information.Info(&population);

	area.setArea(AREA);
	information.Info(&area);

	government.setGover(GOVER);
	information.Info(&government);

	monarchy.setMonarchy(MONARCHY);

	if (GOVER == "Monarchy") {
		information.Info(&monarchy);
		if (MONARCHY == "Absolute")
			information.Info(&absolute);
		else if (MONARCHY == "Constitutional")
			information.Info(&constitutional);
		else if (MONARCHY == "Theocracy")
			information.Info(&theocracy);
	}
	else if (GOVER == "Democracy")
		information.Info(&democracy);
	
	cout << endl;
}

void CountriesInfo::printInfo() {
	information.Info(&name);
	information.Info(&population);
	information.Info(&area);
	information.Info(&government);
	if (government.getGover() == "Monarchy") {
		information.Info(&monarchy);
		if (monarchy.getMonarchy() == "Absolute")
			information.Info(&absolute);
		else if (monarchy.getMonarchy() == "Constitutional")
			information.Info(&constitutional);
		else
			information.Info(&theocracy);
	}
	else
		information.Info(&democracy);
}