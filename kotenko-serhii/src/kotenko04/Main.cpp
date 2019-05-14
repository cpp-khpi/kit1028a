/*
 * @ mainpage
 * @ author - Kotenko Sergey
 * @ date - 24.03.19
 * @ version - 2.0
 */

#include "InfoIndependentsWork.h"
#include "IndependentsWork.h"

int main() {
	system("color A");

	IndependentsWork Work;

	std::regex regex_spaces("[\\s]{2,}");
	std::regex regex_firstSymbol("^[A-Z]");

	int i = 0;
	std::cout << "Enter size : ";
	std::cin >> i;

	Work.setSize(i);
	system("cls");

	std::string *person = new std::string[i];
	Work.readFromFile(person);

	Work.newArray(person);
	delete[] person;
	system("cls");
	Work.print();

	int option = 0;
	do {
		std::cout << "Choose option:" << std::endl << "0 - Exit " << std::endl << "1 - Add element" << std::endl << "2 - Delete element" << std::endl << "3 - Search by index" << std::endl << "4 - Search by Surname" << std::endl;
		std::cout << std::endl;
		std::cin >> option;

		switch (option) {
		case 1: {
			int amount, written, mark;
			std::string person;
			std::cout << "Enter student person: ";
			std::cin.ignore();
			getline(std::cin, person);
			if (!(regex_search(person, regex_firstSymbol)) || regex_search(person, regex_spaces)) {
				std::cout << "Incorrect entry, writing with large letters(A - Z) and without double spaces : " << std::endl;
				std::cin.ignore();
				getline(std::cin, person);
			}
			std::cout << "Enter amount of independent works:  ";
			std::cin >> amount;
			std::cout << "Enter amount of written independent works :  ";
			std::cin >> written;
			std::cout << "Enter student mark (average) :  ";
			std::cin >> mark;
			std::cout << std::endl;

			Work.addElem(amount, written, mark, person);
			system("cls");
			Work.print();
			break;
		}
		case 2: {
			int j = 0;
			std::cout << std::endl << "Enter index by delete element : ";
			std::cin >> j;
			std::cout << std::endl;
			Work.deleteElem(j);
			system("cls");
			Work.print();
			break;
		}
		case 3: {
			int z = 0;
			std::cout << std::endl << "Enter index : ";
			std::cin >> z;
			std::cout << std::endl;
			system("cls");
			Work.print();
			Work.getByIndex(z);
			break;
		}
		case 4: {
			system("cls");
			std::string search_surname;
			std::cout << "Enter searches person : ";
			std::cin.ignore();
			getline(std::cin, search_surname);

			Work.searchBySurname(search_surname);
			break;
		}
		default: {
			break;
		}
		}
	} while (option != 0);

	Work.writeToFile();
	system("cls");
	Work.deleteArray();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();
	system("pause");
	return _CrtDumpMemoryLeaks();
}
