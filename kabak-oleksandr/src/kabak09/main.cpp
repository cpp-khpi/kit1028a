#include "function.h"


int main() {
	string s;

	cout << "Enter the address of the file to read data:" << endl << "Enter ""/exit"" to exit. " << endl;
	getline(cin, s);

	Arrays newArray;

	int *arrPositiveValues = nullptr;
	int sizeArr;

	while (s != "/exit") {
		try {
			readFromFile(s, newArray);
			arrPositiveValues = getArrPositiveValues(newArray, sizeArr);

			cout << "Enter the address to create the data file: " << endl;
			getline(cin, s);

			writeToFile(arrPositiveValues, sizeArr, s);
			delete[] arrPositiveValues;
			removeArr(newArray);
		}
		catch (Exception& exception) {
			cout << "An error has occurred in working with arrays." << exception.what() << endl << " Error in this function: " << exception.getFunc() << endl;

			system("pause");
			delete[] arrPositiveValues;
			removeArr(newArray);
		}
		catch (exception& exception) {
			cout << "An error has occurred in working with arrays." << exception.what() << endl;

			system("pause");
			delete[] arrPositiveValues;
			removeArr(newArray);
		}
		catch (...) {
			cout << "Unknown error!" << endl;

			system("pause");
			delete[] arrPositiveValues;
			removeArr(newArray);
		}
		system("cls");
		cout << "Enter the address of the file to read data:" << endl << "Enter ""/exit"" to exit. " << endl;
		getline(cin, s);
	}


	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	system("pause");
	return _CrtDumpMemoryLeaks();
}