#include "Country.h"


namespace Functions {

	template <typename T>
	void enterData(T* arr, int size) {
		std::cout << "Enter population: " << std::endl;
		for (int i = 0; i < size; i++) {
			std::cin >> arr[i];
		}
	}

	template <typename T>
	void print(T* arr, int size) {
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << std::endl;
		}
	}

	template <typename T>
	T minimum(T* arr, int size) {
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
	int getByIndex(T* arr, int size, T values) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == values) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	int size = 0;
	std::cout << "Enter size : ";
	std::cin >> size;
	int* arr = new int[size];

	{
		int values;
		Functions::enterData(arr, size);
		int option;
		do {
			std::cout << "Choose option:" << std::endl << "0 - Exit " << std::endl << "1 - Print array" << std::endl << "2 - Sort array" << std::endl << "3 - Search by index" << std::endl << "4 - Search by min values" << std::endl;
			std::cout << std::endl;
			std::cin >> option;

			switch (option) {
			case 1: {
				system("cls");
				Functions::print(arr, size);
				break;
			}
			case 2: {
				system("cls");
				Functions::sortArr(arr, size);
				Functions::print(arr, size);
				break;
			}
			case 3: {
				std::cout << "Enter values: ";
				std::cin >> values;
				system("cls");
				Functions::getByIndex(arr, size, values);
				std::cout << values << std::endl << std::endl;
				break;
			}
			case 4: {
				int min = Functions::minimum(arr, size);
				system("cls");
				std::cout << min << std::endl << std::endl;
				break;
			}
			default: {
				break;
			}
			}
		} while (option != 0);
		system("cls");
	}
	delete[]arr;

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();
	system("pause");
	return _CrtDumpMemoryLeaks();
}