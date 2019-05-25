#include "Main.h"

void FuncArr::countElem() {
	if (size == 0) {
		cout << "Array is empty" << endl;
		system("pause");
		system("cls");
		return;
	}

	string p = "Unknown";
	for (int i = 0; i < size; i++) {
		if (p == mas[i].getPublisher()) {
			amount++;
		}
	}
	cout << "Amount of viruses: " << amount << endl;
	system("pause");
	system("cls");
}

FuncArr::FuncArr() :amount(0) {
}