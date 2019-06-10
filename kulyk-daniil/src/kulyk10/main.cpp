/*
* @ mainpage
* @ author - Kulyk Daniil
* @ date - 08.06.19
* @ version - 1.0
*/

#include "Textbook.h"

namespace TemplateFunctions {

	template <typename T>
	void createBacklist(T* backlist, int size) {
		cout << "Enter number of pages: " << endl;
		for (int i = 0; i < size; i++) {
			cin >> backlist[i];
		}
	}

	template <typename T>
	void printAll(T* arr, int size) {
		for (int i = 0; i < size; i++) {
			cout << "Number of pages in " << i + 1 << " textbook is: " << arr[i] << endl;
		}
		cout << endl;
	}

	template <typename T>
	T minElem(T* arr, int size) {
		T min = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		return min;
	}

	template <typename T>
	void sortBacklist(T* arr, int size) {
		T temp;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (arr[i] < arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}

	template <typename T>
	int getByIndex(T* arr, int size, T values) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == values) {
				return i;
			}
		}
		return -1;
	}
};

int main() {

	int size = 0;
	cout << "Enter size: ";
	cin >> size;
	int* backlist = new int[size];

	{
		int values;
		TemplateFunctions::createBacklist(backlist, size);
		int choice;
		do {
			cout << endl << "Welcome to our menu list. What do you want?:" << endl << "0 - Exit " << endl << "1 - Print array" << endl << "2 - Sort array" << endl
			<< "3 - Search by index" << endl << "4 - Search by min values" << endl;
			cout << endl;
			cin >> choice;

			switch (choice) {
			case 1: {
				system("cls");
				TemplateFunctions::printAll(backlist, size);
				break;
			}
			case 2: {
				system("cls");
				TemplateFunctions::sortBacklist(backlist, size);
				TemplateFunctions::printAll(backlist, size);
				break;
			}
			case 3: {
				cout << "Enter values: ";
				cin >> values;
				system("cls");
				TemplateFunctions::getByIndex(backlist, size, values);
				cout << values << endl << endl;
				break;
			}
			case 4: {
				int min = TemplateFunctions::minElem(backlist, size);
				system("cls");
				cout << min << endl << endl;
				break;
			}
			default: {
				break;
			}
			}
		} while (choice != 0);
		system("cls");
	}
	delete[]backlist;

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