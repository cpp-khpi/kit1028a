/*
* @ mainpage
* @ author - Kulyk Daniil
* @ date - 08.06.19
* @ version - 1.0
*/

#include "TemplateFunctions.h"

int main() {

	int size;
	cout << "Enter size : ";
	cin >> size;
	int* arr = new int[size];

	{
		TemplateFunctions<int> textbook;
		textbook.createBacklist();
		int choice;
		do {
			cout << "Welcome to our menu list. What do you want? " << endl << "1 - Print the backlist" << endl << "2 - Sort array" << endl 
			<< "3 - Search by index" << endl << "4 - Search by min values" << endl << "5 - Exit " << endl;
			cout << endl;
			cin >> choice;

			switch (choice) {
			case 1: {
				system("cls");
				textbook.printAll();
				break;
			}
			case 2: {
				system("cls");
				textbook.sortBacklist();
				textbook.printAll();
				break;
			}
			case 3: {
				int index;
				cout << "Enter an index: ";
				cin >> index;
				system("cls");
				textbook.getByIndex(index);
				cout << index << endl << endl;
				break;
			}
			case 4: {
				int min = textbook.minElem();
				system("cls");
				cout << min << endl << endl;
				break;
			}
			default: {
				break;
			}
			}
		} while (choice != 5);
		system("cls");
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