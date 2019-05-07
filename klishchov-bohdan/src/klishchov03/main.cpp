/**
* @author Klishchov B.
* @date 07-03-2019
* @version 1.2
*/
#include"Country.h"
#include"CountryArr.h"
#include <regex>

int main() {

	/*CountryArr country ;
	Country Max;
	
	country.setSize(1);
	
	std::ifstream fin("data.txt");

	int population;
	int area;
	int revenue;
	
	std::string name;
	
	std::cout << "Enter name:  ";
	std::cin >> name;

	country.newArray(name);
	fin >> population >> area >> revenue >> name;
	country.addElem(population, area, revenue, name);
	
	fin >> population >> area >> revenue >> name;
	country.addElem(population, area, revenue, name);
	
	fin >> population >> area >> revenue >> name;
	country.addElem(population, area, revenue, name);
	
	country.deleteElem(0);
	country.getByIndex(1);
	country.print();
	Max = country.maxPop();
	country.printMax(Max);
	country.deleteArray();
	
	fin.close();*/

	CountryArr Countr;

	int size = 0;
	std::cout << "Enter size : ";
	std::cin >> size;
	Countr.setSize(size);

	std::string *tempName = new std::string[size];
	
	for (int i = 0; i < size; i++) {
		std::cout << "Enter name of " << i + 1 << " element: ";
		std::cin >> tempName[i];
	}

	Countr.newArray(tempName);
	Countr.print();

	delete[] tempName;

	int option = 0;
	do {
		std::cout << "Choose option:" << std::endl << "0 - Exit " << std::endl << "1 - Add element" << std::endl << "2 - Delete element" << std::endl << "3 - Get by index" << std::endl << "4 - Search by max population" << std::endl;
		std::cout << std::endl;
		std::cin >> option;

		switch (option) {
		case 1: {
			int population, area, revenue;
			std::string name;
			std::ifstream fin("data.txt");
			fin >> population >> area >> revenue >> name;
			Countr.addEl(population, area, revenue, name);
			fin >> population >> area >> revenue >> name;
			Countr.addEl(population, area, revenue, name);
			fin >> population >> area >> revenue >> name;
			Countr.addEl(population, area, revenue, name);
			system("cls");
			Countr.print();
			break;
		}
		case 2: {
			int id = 0;
			std::cout << std::endl << "Enter index: ";
			std::cin >> id;
			std::cout << std::endl;
			Countr.deleteEl(id);
			system("cls");
			Countr.print();
			break;
		}
		case 3: {
			int index = 0;
			std::cout << std::endl << "Enter index : ";
			std::cin >> index;
			std::cout << std::endl;
			system("cls");
			Countr.print();
			Countr.getByIndex(index);
			break;
		}
		case 4: {
			Country Max = Countr.maxPop();
			Countr.printMax(Max);
			break;
		}
		default: {
			break;
		}
		}
	} while (option != 0);

	Countr.deleteArray();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	
	_CrtDumpMemoryLeaks();
	return 0;
}