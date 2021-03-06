/**
* @file Laba1.cpp
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.03.08
*/

#include <iostream>
#include "InfoWork.h"
#include "StudentsWork.h"
#define N 5

int aggreg() {
	string tmp;
	InfoWork *arr = new InfoWork[N];

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr[i].set(tmp);
	}

	{
		StudentsWork qual(arr, N);
		qual.setSize(N);
		qual.printArr();
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i].getName() << "\t";
	}

	delete[] arr;
	return 0;
}


bool comp(int a, int b) {
	return a < b;
}

bool comp2(int a, int b) {
	return a > b;
}

int main() {
	system("color 0A");
	StudentsWork qualWork;
	ifstream fin;
	bool (*pointer)(int a,int b);
	int j, x;
	int choose = 0;
	int ErrorTest;

	cout << "0 - Exit" << endl;
	cout << "1 - Create vector" << endl;
	cout << "Choose: ";
	cin >> choose;


	if (choose == 1) {

		regex regex_repeat("[\\s]{2,}");
		regex regex_firstSymbol("^[A-Z]");
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
				if (!(regex_search(name[i], regex_firstSymbol)) || regex_search(name[i], regex_repeat)) {
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
				if (!(regex_search(name[i], regex_firstSymbol)) || regex_search(name[i], regex_repeat)) {
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
				string names,names2;
				InfoWork obj;
				int a, b, c;
				cin.ignore();

				cout << "input name:";
				getline(cin, names);
				if (!(regex_search(names, regex_firstSymbol)) || regex_search(names, regex_repeat)) {
					cout << "Use upper case for first symbol:" << endl;
					getline(cin, names);
				}
				cout << "input mark: ";
				cin >> a;
				cout << "input size: ";
				cin >> b;
				cout << "input type: ";
				cin >> c;
				cout << "input teacher's name: ";
				cin.ignore();
				getline(cin, names2);
				cout << "input insert point: ";
				cin >> j;
				obj.set_n(a, b, c, names,names2);
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
			case 5:
				cout << "There your persent: ";
				cout << qualWork.rate();
				break;
			case 6:
				qualWork.sortName();
				break;
			case 7:
				cout << "Choose way of sort: < or > " << endl;
				cout << "0 - by <" << endl;
				cout << "1 - by >" << endl;
				cin >> j;
				if (j == 1) {
					pointer = comp;
				}
				else {
					pointer = comp2;
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
				}
				break;
			default:
				break;
			}
		} while (choose != 0);



	}
	else {
		return 0;
	}

	qualWork.delArr();

	aggreg();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	return _CrtDumpMemoryLeaks();
}
