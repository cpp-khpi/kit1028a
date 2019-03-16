/**
* @file Laba1.cpp
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.02.20
*/

#include <iostream>
#include <string>
#include "InfoWork.h"
#include "StudentsWork.h"
using std::cin;
using std::cout;
using std::endl;

int main() {
	system("color 20");
	StudentsWork qualWork;
	int j, x;
	int choose = 0;

	cout << "0 - Exit" << endl;
	cout << "1 - Create vector" << endl;
	cout << "Choose: ";
	cin >> choose;
	if (choose == 1) {
		cout << "Input size: ";
		cin >> x;

		qualWork.setSize(x);

		char** names = new char*[x];
		for (int i = 0; i < x; i++) {
			names[i] = new char[256];
		}

		for (int i = 0; i < x; i++) {
			cout << "input name:";
			cin >> names[i];
		}
		qualWork.createArr(names);
		for (int i = 0; i < x; i++) {
			delete[] names[i];
		}
		delete[] names;
	}
	else {
		return 0;
	}

	do {
		InfoWork elem;
		cout << "\n";
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - Find element by index" << endl;
		cout << "3 - Add element" << endl;
		cout << "4 - Delete element" << endl;
		cout << "5 - Find persent" << endl;
		cout << "Choose: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			qualWork.printArr();
			break;
		case 2:
			cout << "input index: ";
			cin >> j;

			qualWork.search(j);
			break;
		case 3:

			int a, b, c;
			char name[30];

			cout << "input name: ";
			cin >> name;
			cout << "input mark: ";
			cin >> a;
			cout << "input size: ";
			cin >> b;
			cout << "input type: ";
			cin >> c;
			cout << "input insert point: ";
			cin >> j;
			elem.set_n(a, b, c, name);
			qualWork.add(j, a, b, c, name);
			break;
		case 4:
			cout << "input delete point: ";
			cin >> j;
			qualWork.del(j);
			break;
		case 5:
			cout << "Here your persent:";
			cout << qualWork.rate();
			break;
		default:
			break;
		}
	} while (choose != 0);
	//qualWork.testAdd();
	//qualWork.testDel();

	qualWork.delArr();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();

}
