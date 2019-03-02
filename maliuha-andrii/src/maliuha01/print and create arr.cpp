#include "Header.h"

void funcsForArray::createArr() {
	string n;
	float om, mg, twm;

	cout << "Enter size of array: " << endl;
	cin >> size;
	mas = new workingProgram[size];

	cout << "Instead of a space use '_'. It is a feature of the program." << endl;
	cout << "Otherwise the program will not work. You have been warned." << endl;

	for (int i = 0; i < size; i++) {
		cout << "Enter name of program:" << endl;
		cin >> n;
		cout << "Enter amount of consumed RAM(Mb):" << endl;
		cin >> om;
		cout << "Enter ocupied amount of hard disk memory(Mg):" << endl;
		cin >> mg;
		cout << "Enter time of work (in minutes):" << endl;
		cin >> twm;

		mas[i].setName(n);
		mas[i].setOpMemoryMb(om);
		mas[i].setMemoryGb(mg);
		mas[i].setTimeWorkMin(twm);

	}
}

void funcsForArray::addObj(int ind, string n, float mg, float om, float twm) {
	index = ind - 1;
	workingProgram *timeMas = new workingProgram[size];
	for (int i = 0; i < size; i++) {
		timeMas[i] = mas[i];
	}
	delete[] mas;
	mas = new workingProgram[size + 1];

	mas[index].setName(n);
	mas[index].setOpMemoryMb(om);
	mas[index].setMemoryGb(mg);
	mas[index].setTimeWorkMin(twm);

	for (int i = 0; i < size; i++) {
		if (i >= index) {
			mas[i + 1] = timeMas[i];
		}
		else {
			mas[i] = timeMas[i];
		}
	}
	size++;

	delete[] timeMas;
}

void funcsForArray::delObj(int ind) {
	if (mas == NULL) {
		cout << "Array is empty. Add at least one object to array." << endl;
		return;
	}

	ind = ind - 1;

	workingProgram *timeMas = new workingProgram[size - 1];
	for (int i = 0; i < size - 1; i++) {
		if (i < ind) {
			timeMas[i] = mas[i];
		}
		else {
			if (size > 1) {
				timeMas[i] = mas[i + 1];
			}
		}
	}
	delete[] mas;

	size--;

	mas = new workingProgram[size];


	for (int i = 0; i < size; i++) {
		mas[i] = timeMas[i];
	}


	delete[] timeMas;
}

void funcsForArray::printArr() {
	for (int i = 0; i < size; i++) {
		mas[i].print();
	}
}

void funcsForArray::setIndex(int ind) {
	index = ind - 1;
}

int funcsForArray::getIndex(int ind) {
	ind = index;
	return ind;
}

void funcsForArray::indexOutput() {
	mas[index].print();
}

void funcsForArray::nameSearch(string n) {
	string na;
	for (int i = 0; i < size; i++) {
		na = mas[i].getName(na);
		if (na == n) {
			mas[i].print();
		}
	}
}

int funcsForArray::getSize(int sizeMas) {
	sizeMas = size;
	return sizeMas;
}

void funcsForArray::delMas() {
	delete[] mas;
}