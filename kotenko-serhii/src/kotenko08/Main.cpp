/*
* @ mainpage
* @ author - Kotenko Sergey
* @ date - 28.05.19
* @ version - 1.0
*/

#include "InfoIndependentsWork.h"
#include "IndependentsWork.h"
#include "Homework.h"
#include "DoHomework.h"

bool sort(int a, int b) {
	return a < b;
}
bool sort2(int a, int b) {
	return a > b;
}

int main() {
	srand(time(NULL));
	system("color A");

	auto i = 0;
	std::cout << "Enter size : ";
	std::cin >> i;
	Homework * arr = new Homework[i];
	{
		DoHomework Work;

		std::regex regex_spaces("[\\s]{2,}");
		std::regex regex_firstSymbol("^[A-Z]");

		Work.set_size(i);
		system("cls");
		std::string *person = new std::string[i];
		Work.read_from_file(person);

		Work.new_array(person);
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
				int amount, written, mark, homework_count;
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
				std::cout << "Enter amount of written independent works:  ";
				std::cin >> written;
				std::cout << "Enter student mark (average):  ";
				std::cin >> mark;
				std::cout << "Enter student homework:  ";
				std::cin >> homework_count;
				std::cout << std::endl;

				Work.add_elem(amount, written, mark, homework_count, person);
				system("cls");
				Work.print();
				break;
			}
			case 2: {
				auto j = 0;
				std::cout << std::endl << "Enter index by delete element : ";
				std::cin >> j;
				std::cout << std::endl;
				Work.delete_elem(j);
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
				Work.get_by_index(z);
				break;
			}
			case 4: {
				system("cls");
				std::string search_surname;
				std::cout << "Enter searches person : ";
				std::cin.ignore();
				getline(std::cin, search_surname);

				Work.search_by_surname(search_surname);
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
				std::cout << "4 - By homework" << std::endl;
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
				case 4:
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
		Work.write_to_file();
		system("cls");
		Work.delete_array();
	}
	delete[]arr;

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