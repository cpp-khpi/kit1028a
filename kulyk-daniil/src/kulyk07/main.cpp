/*
* @ mainpage
* @ author - Kulyk Daniil
* @ date - 06.06.19
* @ version - 1.0
*/

#include "Library.h"
#include "Grammarway.h"

bool sort(int a, int b) {
	return a < b;
}

int main() {
	auto size = 0;
	cout << "Enter size : ";
	cin >> size;
	{

		Library textbooks;

		std::regex regex_upperRegister("^[A-Z]");
		std::regex regex_space("[\\s]{2,}");

		system("cls");
		textbooks.readFromFile(size);

		system("cls");
		textbooks.printAll(size);

		Textbook* new_textbook;
		int option = 0;
		do {
			cout << "Welcome to our library website, Please, choose your option:  " << endl << "1 - Add element" << endl << "2 - Delete element" << endl
				<< "3 - Show average amount of pages of textbook from our library. " << endl << "4 - Check required textbook. " << endl
				<< "5 - Sort textbooks by difficulty. " << endl << "6 - Exit. " << endl;
			getchar();
			cin >> option;

			switch (option) {
			case 1: {
				new_textbook = new Grammarway;
				new_textbook->input();
				textbooks.addTextbook(new_textbook);
				break;

				system("cls");
				textbooks.printAll(size);
				break;
			}
			case 2: {
				auto ind = 0;
				cout << endl << "Enter the number of rextbook which you want to remove from backlist:  ";
				cin >> ind;
				cout << endl;
				textbooks.removeTextbook(ind);
				system("cls");
				textbooks.printAll(size);
				break;
			}
			case 3: {
				textbooks.averageAmountOfPages(size);
				break;
			}
			case 4: {
				system("cls");
				int index;
				cout << "Enter the number of required textbook:  ";
				cin >> index;
				textbooks.getRequiredTextbook(index);
				break;
			}
			case 5: {
				system("cls");
				bool(*pointer)(int a, int b);
				pointer = sort;
				textbooks.sortByDifficulty(pointer);
				textbooks.printAll(size);
				break;
			default:
				break;
			}
			}
		} while (option != 6);
			textbooks.writeToFile();
			system("cls");
		}

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