#include <iostream>
#include "Shablon.h"
using std::cout;
using std::cin;
using std::endl;

void fill(int * arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 1000;
	}
}

int main() {
	int value;
	int size;
	int choose;
	Shablon obj;
	cout << "input size of arr: ";
	cin >> size;
	
	int* arr = new int[size];
	fill(arr, size);


	cout << "\n";
	cout << "0 - Exit" << endl;
	cout << "1 - Start" << endl;
	cout << "Choose: ";
	cin >> choose;

	do {
		cout << "\n";
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - sort vector" << endl;
		cout << "3 - find lowest" << endl;
		cout << "4 - find by valuse" << endl;
		cout << "Choose: ";
		cin >> choose;

		switch (choose)
		{
		case 0:
			break;
		case 1:
			obj.printOut(arr, size);
			break;
		case 2:
			system("cls");
			obj.sort(arr, size);
			break;
		case 3:
			system("cls");
			cout << obj.lowest(arr, size);
			break;
		case 4:
			cout << "input value: ";
			cin >> value;
			system("cls");
			cout << obj.find(arr, size,value);
			break;
		default:
			break;
		}
	} while (choose != 0);

	delete[] arr;

	return 0;
}