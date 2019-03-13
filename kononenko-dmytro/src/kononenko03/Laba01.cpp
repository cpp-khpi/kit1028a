/**
* @file Laba1.cpp
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.03.08
*/

#include <iostream>
#include <string>
#include <fstream>
#include "InfoWork.h"
#include "StudentsWork.h"


int main() {
	system("color 0A");
	StudentsWork qualWork;
	ifstream fin;
	int j, x;
	int choose = 0;

	cout << "0 - Exit" << endl;
	cout << "1 - Create vector" << endl;
	cout << "Choose: ";
	cin >> choose;


	if (choose == 1) {
		string file{ "cppstudio.txt" };

		cout << "Input size: ";
		cin >> x;
		qualWork.setSize(x);

		string* name = new string[x];

		cout << "Which type of input do you choose?" << endl;
		cout << "0 - Manual" << endl;
		cout << "1 - From file" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 1: {
			fin.open("cppNames.txt");
			for (int i = 0; i < x; i++) {
				fin >> name[i];
			}
			fin.close();
			break;
		}
		default:
			for (int i = 0; i < x; i++) {
				cout << "input name:";
				cin >> name[i];
			}
			break;
		}

		qualWork.createArr(name);
		delete[x] name;


		do {
			string name;
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
				qualWork.printFile(file);
				break;
			case 2:
				cout << "input index: ";
				cin >> j;

				qualWork.search(j);
				break;
			case 3:

				int a, b, c;

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
				qualWork.add(j, a, b, c, name);
				system("cls");
				break;
			case 4:
				cout << "input delete point: ";
				cin >> j;
				qualWork.del(j);
				system("cls");
				break;
			case 5:
				qualWork.rate();
				break;
			default:
				break;
			}
		} while (choose != 0);



	}else {
	return 0;
	}
	
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

	return 0;
}
