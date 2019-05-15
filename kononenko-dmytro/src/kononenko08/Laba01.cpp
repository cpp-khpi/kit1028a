/**
* @file Laba1.cpp
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.03.08
*/

#include <iostream>
#include "InfoWork.h"
#include "StudentsWork.h"
#include "DetailInfo.h"
#include "AdvenceWork.h"

bool sortWay(int a,int b) {
	return a < b;
}

bool sortWay2(int a, int b) {
	return a > b;
}

int main(){

	system("color 0A");
	StudentsWork qualWork;
	ifstream fin;
	bool(*pointer)(int a,int b);
	int j, x;
	int choose = 0;
	int ErrorTest;
	cout << "0 - Exit" << endl;
	cout << "1 - Create vector" << endl;
	cout << "Choose: ";
	cin >> choose;


	if (choose == 1) {
		regex regex_repeat("^[a-z].*|.*\\s{2,}.*");
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
				getline(fin, name[i]);
				if (regex_match(name[i], regex_repeat)) {
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
				getline(cin, name[i]);
				if (regex_match(name[i], regex_repeat)) {
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
			cout << "5 - Find percent" << endl;
			cout << "6 - Sorted by Name output" << endl;
			cout << "7 - Sort" << endl;
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

				if (qualWork.search(j) != 0) {
					cout << "imposible to find\n";
				}
				break;
			case 3: {
				string names;
				InfoWork obj;
				int a, b, c;
				cin.ignore();

				cout << "input name:";
				getline(cin, names);
				if (regex_match(names, regex_repeat)) {
					cout << "Use upper case for first symbol:" << endl;
					getline(cin, names);
				}
				cout << "input mark: ";
				cin >> a;
				cout << "input size: ";
				cin >> b;
				cout << "input type: ";
				cin >> c;
				//cout << "input teacher's name: ";
				//cin.ignore();
				//getline(cin, names2);
				cout << "input insert point: ";
				cin >> j;
				obj.set_n(a, b, c, names);
				if (qualWork.add(obj,j) != 0) {
					cout << "Error: invalid index" << endl;
				}
				break;
			}
			case 4:
				cout << "input delete point: ";
				cin >> j;

				ErrorTest = qualWork.del(j);

				if (ErrorTest == 2) {
					cout << "Error: invalid index" << endl;
					break;
				}if (ErrorTest == 1) {
					cout << "Error: you can not delete last element" << endl;
					break;
				}
				system("cls");
				break;
			case 5: {
				cout << "There your persent: ";
				cout << qualWork.rate();
				break;
			}
			case 6:
				qualWork.sortName();
				break;
			case 7:

				cout << "Which way of sort do you prefer: < or >" << endl;
				cout << "0 - <" << endl;
				cout << "1 - >" << endl;
				cout << "Choose: ";
				cin >> j;
				
				if (j != 0) {
					pointer = sortWay2;
				}
				else {
					pointer = sortWay;
				}

				cout << "Which type of sort do you want to perfom:" << endl;
				cout << "0 - By mark" << endl;
				cout << "1 - By size" << endl;
				cout << "2 - By type" << endl;
				cout << "Choose: ";
				cin >> j;
				
				switch (j) {
				case 0:
					qualWork.sortByMark(pointer);
					break;
				case 1:
					qualWork.sortBySize(pointer);
					break;
				case 2:
					qualWork.sortByType(pointer);
					break;
				default:
					cout << "Wrong index" << endl;
					break;
				}
				break;
			default:
				break;
			}
		} while (choose != 0);

		qualWork.delArr();
	}

	cout << "0 - Exit" << endl;
	cout << "1 - Create vector" << endl;
	cout << "Choose: ";
	cin >> choose;


	if (choose == 1) {
		regex regex_repeat("^[a-z].*|.*\\s{2,}.*");
		AdvenceWork work;
		string file{ "cppstudio.txt" };

		cout << "Input size: ";
		cin >> x;
		work.setSize(x);

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
				getline(fin, name[i]);
				if (regex_match(name[i], regex_repeat)) {
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
				getline(cin, name[i]);
				if (regex_match(name[i], regex_repeat)) {
					cout << "Use upper case for first symbol:" << endl;
					getline(cin, name[i]);
				}
			}
			break;
		}

		work.createArr(name);
		delete[x] name;


		do {
			cout << "\n";
			cout << "0 - Exit" << endl;
			cout << "1 - Print vector" << endl;
			cout << "2 - Find element by index" << endl;
			cout << "3 - Add element" << endl;
			cout << "4 - Delete element" << endl;
			cout << "Choose: ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				work.printArr();
				break;
			case 2:
				cout << "input index: ";
				cin >> j;

				work.search(j);

				break;
			case 3: {
				string names;
				DetailInfo obj;
				int a, b, c,e,f;
				cin.ignore();

				cout << "input name:";
				getline(cin, names);
				if (regex_match(names, regex_repeat)) {
					cout << "Use upper case for first symbol:" << endl;
					getline(cin, names);
				}
				cout << "input mark: ";
				cin >> a;
				cout << "input size: ";
				cin >> b;
				cout << "input type: ";
				cin >> c;
				cout << "input novelty: ";
				cin >> e;
				cout << "input size of Labor: ";
				cin >> f;
				cout << "input insert point: ";
				cin >> j;
				obj.set_n(a, b, c, names,e,f);
				work.add(obj, j);
				break;
			}
			case 4:
				cout << "input delete point: ";
				cin >> j;

				work.del(j);

				system("cls");
				break;
			default:
				break;
			}
		} while (choose != 0);
		work.delArr();
	}


	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	return _CrtDumpMemoryLeaks();
}
