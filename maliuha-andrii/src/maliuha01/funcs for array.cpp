#include "Header.h"

void funcsForArray::addObj(int ind, string n, float mg, float om, float twm) {
	ind = ind - 1;

	workingProgram *timeMas = new workingProgram[size];
	for (int i = 0; i < size; i++) {
		timeMas[i] = mas[i];
	}
	delete[] mas;
	mas = new workingProgram[size + 1];

	mas[ind].setName(n);
	mas[ind].setOpMemoryMb(om);
	mas[ind].setMemoryGb(mg);
	mas[ind].setTimeWorkMin(twm);

	for (int i = 0; i < size; i++) {
		if (i >= ind) {
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
	if (mas == NULL) {
		return;
	}

	for (int i = 0; i < size; i++) {
		mas[i].print();
	}
}

void funcsForArray::indexOutput(int ind) {
	if (mas == NULL) {
		return;
	}
	mas[ind-1].print();
}

void funcsForArray::nameSearch(string n) {
	if (mas == NULL) {
		return;
	}

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

funcsForArray::funcsForArray() {
	size = 0;
	mas = NULL;
}