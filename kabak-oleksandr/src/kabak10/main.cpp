#include "TestInfo.h"

namespace Template {

	template <typename T>
	void fillArr(T* arr, int size) {
		cout << "Enter marks: ";
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
	}

	template <typename T>
	void printArr(T* arr, int size) {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	template <typename T>
	T minValues(T* arr, int size) {
		T min = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		return min;
	}

	template <typename T>
	void sortArr(T* arr, int size) {
		T temp;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (arr[i] < arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}

	template <typename T>
	int searchEl(T* arr, int size, T values) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == values) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	int SIZE = 0;

	cout << "Enter size: ";
	cin >> SIZE;
	TestInfo* arr = new TestInfo[SIZE];

	{
		int N;
		TestInfo values(5, 3);
		Template::fillArr(arr, SIZE);

		do {
			cout << "\n\nChoose option:\n1.Print array.\n2.Sort array.\n3.Search by index.\n4.Search by min values.\n0.Exit.\n\n";
			cout << "You choose "; cin >> N;
			cout << endl;

			switch (N) {
			case 1: {
				Template::printArr(arr, SIZE);
				break;
			}
			case 2: {
				cout << "Result is :\n";
				Template::sortArr(arr, SIZE);
				Template::printArr(arr, SIZE);
				break;
			}
			case 3: {
				cout << "Enter values: ";
				cin >> values;
				cout << "\nResult is :";

				Template::searchEl(arr, SIZE, values);
				cout << values << endl << endl;
				break;
			}
			case 4: {
				TestInfo min = Template::minValues(arr, SIZE);
				cout << min << endl << endl;
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