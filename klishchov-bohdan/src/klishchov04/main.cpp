/**
* @author Klishchov B.
* @date 07-03-2019
* @version 1.78634594783
*/
#include"Country.h"
#include"CountryArr.h"

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

	Countr.newArray(name);
	Countr.print();

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