#include "pch.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include "Exception.h"
#include "Arr.h"
using namespace std;

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

int maxInArray(int* arr,int size) {
	int max = arr[0];
	int index =0;

	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}

	return index;
}


int main() {
	{	int index1, index2;
		string address, address2;
		cout << "Hello user, input address of file or input";
		SetColor(4, 0);
		cout << " \\exit ";
		SetColor(7, 0);
		cout << "if you want to stop working with this programm: ";
		getline(cin, address);
	
		while (address != "\\exit") {
			try {
				Arr obj;
				obj.readFromFile(address);

				cout << "input index for search: " << endl;
				cout << "index1: ";
				cin >> index1;
				cout << "index2: ";
				cin >> index2;
				obj.getIndex(index1, index2);

				cout << "Input address of file for output: ";
				cin >> address2;
				obj.WriteMaxArray(address2);
				cin.ignore();
			}
			catch (Exception e) {
				cout << e.display() << endl;
				cin.ignore();
			}
			catch (...) {
				cout << "Unknown error" << endl;
				cin.ignore();
			}
			cout << "Input address of file or input";
			SetColor(4, 0);
			cout << " \\exit ";
			SetColor(7, 0);
			cout << "if you want to stop working with this programm: ";
			getline(cin, address);
		}
	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();


	system("PAUSE");
	return 0;
}