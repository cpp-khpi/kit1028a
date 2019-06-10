/**
* @file StudentArr.cpp
* Implementation of all functions of CountryArr class.
* @author Klishchov Bohdan
* @version 1.0
* @date 2019.09.06
*/

#include "CountryArr.h"


void CountryArr::sortArea(bool(*comp)(int x, int y)) {
	Republic temp;
	for (int i = 0; i < republic.size(); i++) {
		for (int j = 0; j < republic.size(); j++) {
			if (comp(republic[i].getArea(), republic[j].getArea())) {
				temp = republic[i];
				republic[i] = republic[j];
				republic[j] = temp;
			}
		}
	}
}

void CountryArr::print() {
	std::ofstream fout("result.txt");
	for (int i = 0; i < republic.size(); i++) {
		fout << "The name of country: " << republic[i].getName() << std::endl;
		fout << "Area: " << republic[i].getArea() << std::endl;
		fout << "Population: " << republic[i].getPopulation() << std::endl;
		fout << "Revenue: " << republic[i].getRevenue() << std::endl;
		fout << "The president is: " << republic[i].getPresident() << std::endl;
	}
	fout.close();
	for (int i = 0; i < republic.size(); i++) {
		cout << "The name of country: " << republic[i].getName() << std::endl;
		cout << "Area: " << republic[i].getArea() << std::endl;
		cout << "Population: " << republic[i].getPopulation() << std::endl;
		cout << "Revenue: " << republic[i].getRevenue() << std::endl;
		info.Info(&republic[i]);
		cout << std::endl << std::endl;
	}
}
void CountryArr::addEl(Republic republic) {
	this->republic.push_back(republic);
}
void CountryArr::deleteEl(int index) {
	republic.erase(republic.begin() + index);
}

void CountryArr::getByIndex(int index) { //change function name!!!
	std::ofstream fout("resultID.txt");
	fout << "The name of country: " << republic[index - 1].getName() << std::endl;
	fout << "Area: " << republic[index - 1].getArea() << std::endl;
	fout << "Population: " << republic[index - 1].getPopulation() << std::endl;
	fout << "Revenue: " << republic[index - 1].getRevenue() << std::endl;
	fout.close();

	cout << "The name of country: " << republic[index - 1].getName() << std::endl;
	cout << "Area: " << republic[index - 1].getArea() << std::endl;
	cout << "Population: " << republic[index - 1].getPopulation() << std::endl;
	cout << "Revenue: " << republic[index - 1].getRevenue() << std::endl;
	info.Info(&republic[index - 1]);
	cout << std::endl << std::endl;
}

void CountryArr::CalculatePopulation() {
	auto popul = 0;
	for (int i = 0; i < republic.size(); i++) {
		popul += republic[i].getPopulation();
	}

	cout << "Total population:" << popul << endl;
}
