/*
* @ mainpage
* @ author - Kotenko Sergey
* @ date - 19.05.19
* @ version - 2.0
*/

#include "InfoIndependentsWork.h"
#include "IndependentsWork.h"

bool sort(int a, int b) {
	return a < b;
}
bool sort2(int a, int b) {
	return a > b;
}


int main() {
	system("color A");

	auto i = 0;
	std::cout << "Enter size : ";
	std::cin >> i;
	InfoIndependentsWork * arr = new InfoIndependentsWork[i];

	{

		IndependentsWork Work(arr, i);

		std::regex regex_spaces("[\\s]{2,}");
		std::regex regex_firstSymbol("^[A-Z]");

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
			std::cout << "Choose option:" << std::endl << "0 - Exit " << std::endl << "1 - Add element" << std::endl << "2 - Delete element" << std::endl << "3 - Search by index" << std::endl << "4 - Search by Surname" << std::endl << "5 - Sort" << std::endl;
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
				auto j = 0;
				std::cout << std::endl << "Enter index by delete element : ";
				std::cin >> j;
				std::cout << std::endl;
				Work.deleteElem(j);
				system("cls");
				Work.print();
				break;
			}
			case 3: {
				auto z = 0;
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
			case 5: {
				system("cls");
				bool(*pointer)(int a, int b);
				int s;
				std::cout << "Sort: From large to small or From small to large  " << std::endl;
				std::cout << "0 - ( 1 -> 100 )" << std::endl;
				std::cout << "1 - ( 100 -> 1 )" << std::endl;
				std::cin >> s;
				if (s == 0) {
					pointer = sort;
				}
				else {
					pointer = sort2;
				}
				std::cout << std::endl << "Sort by..." << std::endl;
				std::cout << "1 - By mark" << std::endl;
				std::cout << "2 - By amount work" << std::endl;
				std::cout << "3 - By written work" << std::endl;
				std::cout << "Choose: ";
				std::cin >> s;
				switch (s) {
				case 1:
					Work.sort_by_mark(pointer);
					Work.print();
					break;
				case 2:
					Work.sort_by_amount(pointer);
					Work.print();
					break;
				case 3:
					Work.sort_by_written(pointer);
					Work.print();
					break;
				}
				break;
			default:
				break;
			}
			}
		} while (option != 0);
		Work.writeToFile();
		system("cls");
		Work.deleteArray();
	}

	delete[] arr;

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