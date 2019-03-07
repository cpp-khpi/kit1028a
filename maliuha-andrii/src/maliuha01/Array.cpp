#include "Header.h"

void Array::addProgram(int ind, string n, float mg, float om, float twm) {
	ind = ind - 1;

	workingProgram *timeMas = new workingProgram[size + 1];
	
	timeMas[ind].setName(n);
	timeMas[ind].setOpMemoryMb(om);
	timeMas[ind].setMemoryGb(mg);
	timeMas[ind].setTimeWorkMin(twm);

	for (int i = 0; i < size; i++) {
		if (i >= ind) {
			timeMas[i + 1] = mas[i];
		}
		else {
			timeMas[i] = mas[i];
		}
	}

	delete[] mas;

	mas = timeMas;

	size++;
}

void Array::removeProgram(int ind) {
	if (size == 0) {
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

	mas = timeMas;

	size--;
}

void Array::showAll() {
	if (size == 0) {
		return;
	}

	for (int i = 0; i < size; i++) {
		mas[i].print();
	}
}

void Array::getProgram(int ind) {
	if (size == 0) {
		return;
	}
	mas[ind-1].print();
}

void Array::searchProgram(string n) {
	if (size == 0) {
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

int Array::getSize(int sizeMas) {
	sizeMas = size;
	return sizeMas;
}

void Array::deleteArray() {
	delete[] mas;
}

Array::Array() {
	size = 0;
	mas = NULL;
}