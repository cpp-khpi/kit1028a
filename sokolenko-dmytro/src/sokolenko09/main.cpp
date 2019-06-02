#include <iostream>
#include "array.h"

using std::cout;
using std::cin;
using std::cerr;
using std::getline;


int main()
{
	{
		system("color B");
		cout << "Hello! Welcome to sokolenko09 program!" << endl <<
			endl << "Press ENTER to continue.";
		cin.get();

		string choice;

		system("cls");
		cout << "To continue enter file name as shown on the screen:" << endl << endl <<
			"DiskName:\\folder\\folder\\...\\fileName.txt" << endl << endl <<
			"For example:" << endl << "E:\\programming\\database.txt" << endl <<
			"To exit enter \"/exit\" without quotes." << endl << endl << "Option: ";
		getline(cin, choice);

		TwoDimenIntArray integerArray;

		int* negativeElemArray = nullptr;
		unsigned int sizeNegatArr;

		while (choice != "/exit") {
			try {
				readFromFile(choice, integerArray);
				negativeElemArray = getNegativeElements(integerArray, sizeNegatArr);

				cout << "Array of negative elements was received. " << endl <<
					"Enter file name for writing as shown on the screen:" << endl << endl <<
					"DiskName:\\folder\\folder\\...\\fileName.txt" << endl << endl <<
					"For example:" << endl << "E:\\programming\\database.txt" << endl << endl << "File name: ";
				getline(cin, choice);

				writeToFile(negativeElemArray, sizeNegatArr, choice);

				delete[] negativeElemArray;
				deleteArray(integerArray);

			} 
			catch (MyException& exception) {
				cerr << "An array exception occurred (" << exception.what() << " in function " <<
					exception.getFunction() << ")" << endl;

				delete[] negativeElemArray;
				deleteArray(integerArray);
			} 
			catch (exception& exception) {
				cerr << "An array exception occurred (" << exception.what() << ")" << endl;

				delete[] negativeElemArray;
				deleteArray(integerArray);
			}
			catch (...) {
				cerr << "Unknown error!" << endl;

				delete[] negativeElemArray;
				deleteArray(integerArray);
			}

			cout << endl << "Press ENTER to continue.";
			cin.get();

			system("cls");
			cout << "To continue enter file name as shown on the screen:" << endl << endl <<
				"DiskName:\folder\folder\...\fileName.txt" << endl << endl <<
				"For example:" << endl << "E:\programming\database.txt" << endl <<
				"To exit enter \"/exit\" without quotes." << endl << endl << "Option: ";
			getline(cin, choice);
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