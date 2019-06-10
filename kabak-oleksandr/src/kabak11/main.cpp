#include "TestInfo.h"



int main() {
	int SIZE = 0;

	cout << "Enter size: ";
	cin >> SIZE;
	int* arr = new int[SIZE];

	{
		int values, N;
		Template<int> test;
		test.fillArr();
		do {
			cout << "\n\nChoose option:\n1.Print array.\n2.Sort array.\n3.Search by index.\n4.Search by min values.\n0.Exit.\n\nYou choose ";
			cin >> N;


			switch (N) {
			case 1: {

				test.printArr();
				break;
			}
			case 2: {
				cout << "Result is :";
				test.sortArr();
				test.printArr();
				break;
			}
			case 3: {
				cout << "Enter values: ";
				cin >> values;
				cout << "\nResult is :";

				test.searchEl(values);
				cout << values << endl << endl;
				break;
			}
			case 4: {
				int min = test.minValues();
				cout << values << endl << endl;
				break;
			}
			default: {
				break;
			}
			}
		} while (N != 0);
	}
	delete[]arr;

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();

	cout << "Work is done.";
	system("pause");

	return _CrtDumpMemoryLeaks();
}