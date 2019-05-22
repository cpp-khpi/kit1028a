#include <iostream>
#include "Shablon.h"
#include "InfoWork.h"
using std::cout;
using std::cin;
using std::endl;


template <typename T>
void fill(T * arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Input size and points: ";
		cin >> arr[i];
	}
}

int main() {
	InfoWork value;
	int size;
	int choose;
	cout << "input size of arr: ";
	cin >> size;
	
	InfoWork* arr = new InfoWork[size];
	fill(arr, size);

	do {
		cin.ignore();
		cout << "\n";
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - sort vector" << endl;
		cout << "3 - find lowest" << endl;
		cout << "4 - find by value" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 0:
			break;
		case 1:
			shablon::printOut(arr, size);
			break;
		case 2:
			system("cls");
			shablon::sort(arr, size);
			break;
		case 3:
			system("cls");
			value = shablon::lowest(arr, size);
			cout << value;
			break;
		case 4:
			cout << "input value: ";
			cin >> value;
			system("cls");
			cout << shablon::find(arr, size,value);
			break;
		default:
			break;
		}
	} while (choose != 0);

	delete[] arr;

	return 0;
 }