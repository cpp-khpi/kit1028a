/*
* @ mainpage
* @ author - Kulyk Daniil
* @ date - 08.06.19
* @ version - 1.0
*/

#include "ElectronicLibrary.h"
#include "Library.h"
#include "ElectronicTextbook.h"

bool sort(int a, int b) {
	return a < b;
}

int main() {
	auto size = 0;
	cout << "Enter size : ";
	cin >> size;
	ElectronicTextbook *book = new ElectronicTextbook[size];
	{
		ElectronicLibrary elecTextbooks;

		std::regex regex_upperRegister("^[A-Z]");
		std::regex regex_space("[\\s]{2,}");

		elecTextbooks.setSize(size);
		system("cls");
		string *textbook = new string[size];
		elecTextbooks.readFromFile(textbook);

		system("cls");
		elecTextbooks.printAll();

		elecTextbooks.getSurname(textbook);
		delete[] textbook;
		system("cls");
		elecTextbooks.printAll();


		int option = 0;
		do {
			cout << "Welcome to our library website, Please, choose your option:  " << endl << "1 - Add textbook. " << endl << "2 - Delete textbook. " << endl
				<< "3 - Show average amount of pages of textbook from our library. " << endl << "4 - Check required textbook. " << endl
				<< "5 - Sort textbooks by cost. " << endl << "6 - Exit. " << endl << "You choose: ";
			getchar();
			cin >> option;

			switch (option) {
			case 1: {
				int num, pages, grade, cost, year_of_release, amount_of_charge;
				string author;
				cout << "Enter the textbook's author name: " << endl;
				cin.ignore();
				getline(std::cin, author);
				if (!(regex_search(author, regex_upperRegister)) || regex_search(author, regex_space)) {
					cout << "Incorrect entry, writing with large letters(A - Z) and without double spaces : " << endl;
					cin.ignore();
					getline(std::cin, author);
				}
				cout << "Enter the number of textbooks: ";
				cin >> num;
				cout << "Enter the number of pages of textbook: ";
				cin >> pages;
				cout << "Enter the grade this textbook for: ";
				cin >> grade;
				cout << "Enter the cost of the textbook: ";
				cin >> cost;
				cout << "Enter the year of release of the textbook: ";
				cin >> year_of_release;
				cout << "Enter the amount of charge of the electronic textbook: ";
				cin >> amount_of_charge;

				elecTextbooks.addTextbook(num, pages, grade, cost, year_of_release, amount_of_charge, author);
				system("cls");
				elecTextbooks.printAll();
				break;
			}
			case 2: {
				auto ind = 0;
				cout << endl << "Enter the number of textbook which you want to remove from backlist:  ";
				cin >> ind;
				cout << endl;
				elecTextbooks.removeTextbook(ind);
				system("cls");
				elecTextbooks.printAll();
				break;
			}
			case 3: {
				elecTextbooks.averageAmountOfPages(size);
				break;
			}
			case 4: {
				system("cls");
				int index;
				cout << "Enter the number of required textbook:  " << endl;
				cin >> index;
				elecTextbooks.getRequiredTextbook(index);
				break;
			}
			case 5: {
				system("cls");
				bool(*pointer)(int a, int b);
				pointer = sort;
				elecTextbooks.sortByCost(pointer);
				elecTextbooks.printAll();
				break;
			default:
				break;
			}
			}
		} while (option != 6);
		elecTextbooks.writeToFile();
		system("cls");
	}
	delete[]book;

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