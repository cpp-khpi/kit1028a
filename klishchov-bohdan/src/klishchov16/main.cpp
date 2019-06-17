/**
* @file main.cpp
* Implementation of all functions of Information class.
* @author Klishchov Bohdan
* @version 1.0
* @date 2019.09.06
*/

#include "Parlament.h"

int main() {
	int size;
	cout << "Please, enter size: ";
	cin >> size;
	string name;
	string president;
	Parlament *parl = new Parlament[size];
	for (int i = 0; i < size; i++) {
		cout << "Please, enter name: ";
		cin >> name;
		parl[i].setRand(name);
		cout << "Please, enter president: ";
		cin >> president;
		parl[i].setPresident(president);
		cout << "_______________________________________________________" << endl;
		cout << "The name is: " << parl[i].getName() << endl;
		cout << "The president is: " << parl[i].getPresident() << endl;
		cout << "The area is: " << parl[i].getArea() << endl;
		cout << "The population is: " << parl[i].getPopulation() << endl;
		cout << "The revenue is: " << parl[i].getRevenue() << endl;
		cout << "_______________________________________________________" << endl;
	}
	delete[] parl;
	return 0;
}