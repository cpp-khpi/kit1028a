/*
* @ mainpage
* @ author - Kulyk Daniil
* @ date - 09.06.19
* @ version - 1.0
*/

#include "Library.h"
#include "Algebra.h"
#include "English.h"
#include "Exception.h"

bool sort(int a, int b) {
	return a < b;
}
bool sort2(int a, int b) {
	return a > b;
}

int main() {
	try {
		auto i = 0;
		cout << "Enter the size : ";
		cin >> i;
		Library textbook;

		regex regex_space("[\\s]{2,}");
		regex regex_upperRegister("^[A-Z]");

		system("cls");
		textbook.readFromFile(i);

		system("cls");
		textbook.printAll();

		Textbook* new_textbook;
		int option = 0;
		do {
			cout << "Welcome to our library menu. What do you want? "  << endl << "1 - Add a textbook" << endl << "2 - Delete a textbook" << endl 
				<< "3 - Search a textbook by index" << endl << "4 - Search a textbook by author" << endl << "5 - Sort textbooks" << endl << "6 - Exit " << endl << endl;
			cin >> option;

			switch (option) {
			case 1: {
				cout << " Choose option: " << endl << " 0 - Add Algebra " << " 1 - Add English " << endl;
				cin >> option;
				switch (option) {
				case 0: {
					new_textbook = new Algebra;
					new_textbook->input();
					textbook.addTextbook(new_textbook);
					break;
				}
				case 1: {
					new_textbook = new English;
					new_textbook->input();
					textbook.addTextbook(new_textbook);
					break;
				}
				}
				system("cls");
				textbook.printAll();
				break;
			}
			case 2: {
				auto num = 0;
				cout << endl << "Enter the number of textbook you want to remove: ";
				cin >> num;
				cout << endl;
				textbook.deleteTextbook(num);
				system("cls");
				textbook.printAll();
				break;
			}
			case 3: {
				auto index = 0;
				cout << endl << "Enter the index : ";
				cin >> index;
				cout << endl;
				system("cls");
				textbook.printAll();
				textbook.getByIndex(index);
				break;
			}
			case 4: {
				system("cls");
				string search_surname;
				cout << "Enter the name of the author of required textbook: ";
				cin.ignore();
				getline(cin, search_surname);

				textbook.searchBySurname(search_surname);
				break;
			}
			case 5: {
				system("cls");
				bool(*pointer)(int a, int b);
				int s;
				cout << "Sort: From large to small or From small to large  " << endl;
				cout << "0 - ( 1 -> 100 )" << endl;
				cout << "1 - ( 100 -> 1 )" << endl;
				cin >> s;
				if (s == 0) {
					pointer = sort;
				}
				else {
					pointer = sort2;
				}
				cout << endl << "Sort textbooks by..." << endl;
				cout << "1 - By pages" << endl;
				cout << "2 - By grade" << endl;
				cout << "3 - By cost" << endl;
				cout << "You choose: ";
				cin >> s;
				switch (s) {
				case 1:
					textbook.sortByPages(pointer);
					textbook.printAll();
					break;
				case 2:
					textbook.sortByGrade(pointer);
					textbook.printAll();
					break;
				case 3:
					textbook.sortByCost(pointer);
					textbook.printAll();
					break;
				}
				break;
			default:
				break;
			}
			}
		} while (option != 6);
		textbook.writeToFile();
		system("cls");
	}
	catch (Exception& exception) {
		cout << "An error has occurred in working." << exception.what() << endl << " Error in this function: " << exception.getFunc() << endl;
	}
	catch (std::exception& exception) {
		cout << "An error has occurred in working." << exception.what() << endl;
	}
	catch (...) {
		cout << "Unknown error!" << endl;
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();
	return _CrtDumpMemoryLeaks();
	system("pause");
}