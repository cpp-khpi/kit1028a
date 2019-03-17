/**
* @file Laba1.cpp
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.03.08
*/

#include <iostream>
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
		regex regex_repeat("[\\s]{2,3}");
		regex regex_firstSymbol("((^[A-Z])[\\w\\s]+)");
		string names;
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
			cin.ignore();
			fin.open("cppNames.txt");
			for (int i = 0; i < x; i++) {
				getline(fin,name[i]);
				if (!(regex_match(name[i], regex_firstSymbol)) ||regex_search(name[i],regex_repeat)){
					cout << "Use upper case for first symbol:" << endl;
					getline(cin, name[i]);
				}
			}
			fin.close();
			break;
		}
		default:
			cin.ignore();
			for (int i = 0; i < x; i++) {
				cout << "input name:";
				getline(cin,name[i]);
				if (!(regex_match(name[i], regex_firstSymbol)) || regex_search(name[i], regex_repeat)) {
					cout << "Use upper case for first symbol:" << endl;
					getline(cin, name[i]);
				}
			}
			break;
		}

		qualWork.createArr(name);
		delete[x] name;


		do {
			cout << "\n";
			cout << "0 - Exit" << endl;
			cout << "1 - Print vector" << endl;
			cout << "2 - Find element by index" << endl;
			cout << "3 - Add element" << endl;
			cout << "4 - Delete element" << endl;
			cout << "5 - Find persent" << endl;
			cout << "6 - Sorted output" << endl;
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
				cin.ignore();

				cout << "input name:";
				getline(cin, names);
				if (!(regex_match(names, regex_firstSymbol)) || regex_search(names, regex_repeat)){
					cout << "Use upper case for first symbol:" << endl;
					getline(cin, names);
				}
				cout << "input mark: ";
				cin >> a;
				cout << "input size: ";
				cin >> b;
				cout << "input type: ";
				cin >> c;
				cout << "input insert point: ";
				cin >> j;
				qualWork.add(j, a, b, c, names);
				system("cls");
				break;
			case 4:
				cout << "input delete point: ";
				cin >> j;
				qualWork.del(j);
				system("cls");
				break;
			case 5:
				cout << "There your persent: ";
				cout << qualWork.rate();
				break;
			case 6:
				qualWork.sort();
				break;
			default:
				break;
			}
		} while (choose != 0);



	}else {
		return 0;
	}

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
