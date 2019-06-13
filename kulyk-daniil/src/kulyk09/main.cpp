/**
* @file main.cpp
* @author Kulyk Daniil
* @date 09.06.2019
* @version 1.0
*/

#include "Operations.h"

int main() {
	{
		string command;
		cout << "Enter command" << endl;
		cout << "(/exit) to close the program" << endl;
		cout << "(1) to read information of arrays from txt file and create array whit max values of arrays" << endl;
		Operations arr;
		string fileW, fileR;
		int *newArr = NULL;
		stringstream arrays1;

		while (command != "/exit") {
			cout << "Enter name of file for reading: ";
			getline(cin, fileR);
			cout << "Enter name of file for writing: ";
			getline(cin, fileW);
			system("cls");
			try {
				arrays1 = arr.readFromFile(fileR);
				arr.createArrays1(arrays1);
				arr.ArrMaxValue(newArr);
				arr.writeToFile(newArr, fileW);
				arr.delArrays();

				delete[] newArr;
			}
			catch (Exception& exception) {
				std::cerr << "An array exception occurred (" << exception.what() << endl;
			}
			catch (exception& exception) {
				std::cerr << "An array exception occurred (" << exception.what() << ")" << endl;
			}
			catch (...) {
				std::cerr << "Unknown error!" << endl;
			}

			cout << "Enter command" << endl;
			cout << "(/exit) to close the program" << endl;
			cout << "(1) to read information of arrays from txt file and create array with max values of arrays" << endl;
			getline(cin, command);
		}
	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	return _CrtDumpMemoryLeaks();
}