/**
* @file Dialog.cpp
* Implementation of all functions of Dialog class.
* @author Klishchov Bohdan
* @version 1.0
* @date 2019.09.06
*/

#include "Dialog.h"

bool comp(int x, int y) {
	return x < y;
}

bool comp2(int x, int y) {
	return x > y;
}

void Dialog::menu() {

	CountryArr world;
	Republic country;
	int option = 0;

	bool (*p)(int, int);

	do {
		std::cout << "Choose option:" << std::endl << "0 - Exit " << std::endl << "1 - Add element" << std::endl << "2 - Delete element" << std::endl << "3 - Get by index"  << std::endl << "4 - Sort by area" << std::endl << "5 - Get all population" << std::endl << "6 - Print";
		std::cout << std::endl;
		std::cin >> option;

		switch (option) {
		case 1: {
			int area, population, revenue;
			string name, president;
			std::ifstream fin("data.txt");
			fin >> area >> population >> revenue >> name >> president;
			country.setData(name, area, population, revenue);
			country.setPresident(president);
			world.addEl(country);
			fin >> area >> population >> revenue >> name >> president;
			country.setData(name, area, population, revenue);
			country.setPresident(president);
			world.addEl(country);
			fin >> area >> population >> revenue >> name >> president;
			country.setData(name, area, population, revenue);
			country.setPresident(president);
			world.addEl(country);
			system("cls");
			world.print();
			break;
		}
		case 2: {
			auto id = 0;
			cout << std::endl << "Enter index: ";
			cin >> id;
			cout << endl;
			world.deleteEl(id);
			system("cls");
			world.print();
			break;
		}
		case 3: {
			auto index = 0;
			std::cout << std::endl << "Enter index : ";
			std::cin >> index;
			std::cout << std::endl;
			system("cls");
			world.getByIndex(index);
			break;
		}
		case 4: {
			int ch;
			std::cout << "Please, enter the type of sort" << std::endl << "1 - up, 0 - down: ";
			std::cin >> ch;
			std::cout << std::endl;
			if (ch == 1) {
				p = comp;
			}
			else if (ch == 0) {
				p = comp2;
			}
			else {
				std::cout << "You enter false variant" << std::endl;
				break;
			}
			world.sortArea(p);
			break;
		}
		case 5: {
			world.CalculatePopulation();
			break;
		}
		case 6: {
			world.print();
		}
		default: {
			break;
		}
		}
	} while (option != 0);
}