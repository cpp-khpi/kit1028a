/*
 * @ mainpage
 * @ author - Kotenko Sergey
 * @ date - 10.03.19
 * @ version - 3.0
 */

#include "InfoIndependentsWork.h"
#include "IndependentsWork.h"

int main() {
	system("color A");

	InfoIndependentsWork Do;
	IndependentsWork Work;

	int i = 0;
	std::cout << "Enter size : ";
	std::cin >> i;

	Work.getSize(i);
	system("cls");

	char** surname = new char*[i];	
	for (int j = 0; j < i; j++) {
		surname[j] = new char[256];
	}
	for (int j = 0; j < i; j++) {
		std::cout << "Enter surname:  ";
		std::cin >> surname[j];
	}

	system("cls");
	Work.newArray(surname);
	for (int j = 0; j < i; j++) {
		delete[]surname[j];
	} 
	delete[] surname;
	Work.print();

	int option = 0;
	do {
		std::cout << "Choose option:" << std::endl << "1 - Exit " << std::endl << "2 - Add element" << std::endl << "3 - Delete element" << std::endl << "4 - Search by index" << std::endl;
		std::cout << std::endl;
		std::cin >> option;

		switch (option) {
		case 1: {
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

			exit(0);
		}
		case 2: {
			system("cls");
			int amount, written, mark;
			char surname[30];
			std::cout << "Enter student surname: ";
			std::cin >> surname;
			std::cout << "Enter amount of independent works:  ";
			std::cin >> amount;
			std::cout << "Enter amount of written independent works :  ";
			std::cin >> written;
			std::cout << "Enter student mark (average) :  ";
			std::cin >> mark;
			std::cout << std::endl;

			Work.addElem(amount, written, mark, surname);
			system("cls");
			Work.print();
			break;
		}
		case 3: {
			int j = 0;
			std::cout << std::endl << "Enter index by delete element : ";
			std::cin >> j;
			std::cout << std::endl;
			Work.deleteElem(j);
			system("cls");
			Work.print();
			break;
		}
		case 4: {
			int z = 0;
			std::cout << std::endl << "Enter index : " ;
			std::cin >> z;
			std::cout << std::endl;
			system("cls");
			Work.print();
			Work.getByIndex(z);
			break;
		}
		}
	} while (option != 0);

	return 0;
}
