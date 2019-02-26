#include "Header.h"

void funcs::addObj(int ind, string n, float mg, float om, float twm) {
	index = ind - 1;
	programOn *timeMas = new programOn[size];
	for (int i = 0; i < size; i++) {
		timeMas[i] = mas[i];
	}
	delete[] mas;
	mas = new programOn[size+1];

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

void funcs::delObj(int ind) {
	index = ind - 1;
	size--;
	programOn *timeMas = new programOn[size + 1];
	for (int i = 0; i < size; i++) {
		if (i < index) {
			timeMas[i] = mas[i];
		}
		else {
			if (size != 0) {
				timeMas[i] = mas[i + 1];
			}
		}
	}
	delete[] mas;

	mas = new programOn[size];


	for (int i = 0; i < size; i++) {
		mas[i] = timeMas[i];
	}


	delete[] timeMas;
}

void funcs::printArr() {
	for (int i = 0; i < size; i++) {
		mas[i].print();
	}
}

void funcs::setIndex(int ind) {
	index = ind - 1;
}

int funcs::getIndex(int ind) {
	ind = index;
	return ind;
}

void funcs::indexOutput() {
	mas[index].print();
}

void funcs::nameSearch(string n) {
	string na;
	for (int i = 0; i < size; i++) {
		na = mas[i].getName(na);
		if (na == n) {
			mas[i].print();
		}
	}
}

int funcs::getSize(int sizeMas) {
	sizeMas = size;
	return sizeMas;
}

void funcs::delMas() {
	delete[] mas;
}