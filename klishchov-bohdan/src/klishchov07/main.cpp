/**
* @author Klishchov B.
* @date 07-03-2019
* @version 1.78634594783
*/
#include"CountryArr.h"

bool comp(int x, int y) {
	return x < y;
}

bool comp2(int x, int y) {
	return x > y;
}

int main() {


	CountryArr Countr;

	std::regex regex_spaces("[\\s]{2,}");
	std::regex regex_firstSymbol("^[A-Z]");

	std::string name;
	std::cout << "Please, the name of country: ";
	getline(std::cin, name);
	if (!(regex_search(name, regex_firstSymbol)) || regex_search(name, regex_spaces)) {
		std::cout << "Incorrect entry, writing with large letters(A - Z) and without double spaces : " << std::endl;
		std::cout << "Please, the name of country: ";
		getline(std::cin, name);
	}

	std::string pres;
	std::cout << "Please, the president of country: ";
	getline(std::cin, pres);

	Countr.newArray(name, pres);
	Countr.print();

	bool(*p)(int a, int b);

	int option = 0;
	do {
		std::cout << "Choose option:" << std::endl << "0 - Exit " << std::endl << "1 - Add element" << std::endl << "2 - Delete element" << std::endl << "3 - Get by index" << std::endl << "4 - Search by max population" << std::endl << "5 - Sort by area" << std::endl;
		std::cout << std::endl;
		std::cin >> option;

		switch (option) {
		case 1: {
			int population, area, revenue;
			std::string name;
			std::ifstream fin("data.txt");
			fin >> population >> area >> revenue >> name;
			std::cout << "Please, the president of country: ";
			getline(std::cin, pres);
			Countr.addEl(population, area, revenue, name, pres);
			fin >> population >> area >> revenue >> name;
			std::cout << "Please, the president of country: ";
			getline(std::cin, pres);
			Countr.addEl(population, area, revenue, name, pres);

			fin >> population >> area >> revenue >> name;
			std::cout << "Please, the president of country: ";
			getline(std::cin, pres);
			Countr.addEl(population, area, revenue, name, pres);

			system("cls");
			Countr.print();
			break;
		}
		case 2: {
			auto id = 0;
			std::cout << std::endl << "Enter index: ";
			std::cin >> id;
			std::cout << std::endl;
			Countr.deleteEl(id);
			system("cls");
			Countr.print();
			break;
		}
		case 3: {
			auto index = 0;
			std::cout << std::endl << "Enter index : ";
			std::cin >> index;
			std::cout << std::endl;
			system("cls");
			Countr.getByIndex(index);
			break;
		}
		case 4: {
			Republic Max = Countr.maxPop();
			Countr.printMax(Max);
			break;
		}
		case 5: {
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
			Countr.sortArea(p);
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