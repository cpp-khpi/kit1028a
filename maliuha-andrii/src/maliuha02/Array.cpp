#include "Header.h"

void Array::addProgram(int ind, char* n, float mg, float om, float twm) {
	ind = ind - 1;

	workingProgram *timeMas = new workingProgram[size+1];

	timeMas[ind].setName(n);
	timeMas[ind].setOpMemoryMb(om);
	timeMas[ind].setMemoryGb(mg);
	timeMas[ind].setTimeWorkMin(twm);

	for (int i = 0; i < size; i++) {
		if (i >= ind) {
			n = mas[i].getName(n);
			om = mas[i].getOpMemoryMb(om);
			mg = mas[i].getMemoryGb(mg);
			twm = mas[i].getTimeWorkMin(twm);
			timeMas[i + 1].setName(n);
			timeMas[i + 1].setOpMemoryMb(om);
			timeMas[i + 1].setMemoryGb(mg);
			timeMas[i + 1].setTimeWorkMin(twm);
		}
		else {
			n = mas[i].getName(n);
			om = mas[i].getOpMemoryMb(om);
			mg = mas[i].getMemoryGb(mg);
			twm = mas[i].getTimeWorkMin(twm);
			timeMas[i].setName(n);
			timeMas[i].setOpMemoryMb(om);
			timeMas[i].setMemoryGb(mg);
			timeMas[i].setTimeWorkMin(twm);
		}
	}

	delete[] mas;
	mas = timeMas;
	
	size++;
}

void Array::removeProgram(int ind) {
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

void Array::showAll() {
	if (mas == NULL) {
		return;
	}

	for (int i = 0; i < size; i++) {
		mas[i].print();
	}
}

void Array::getProgram(int ind) {
	if (mas == NULL) {
		return;
	}
	mas[ind - 1].print();
}

void Array::nameSearch(char* n) {
	if (mas == NULL) {
		return;
	}

	char* na = (char*)calloc(50,sizeof(char));

	for (int i = 0; i < size; i++) {
		strcpy(na, mas[i].getName(na));
		if (strcmp(na, n)==0) {
			mas[i].print();
		}
	}
}

int Array::getSize(int sizeMas) {
	sizeMas = size;
	return sizeMas;
}

void Array::delMas() {
	delete[] mas;
}

Array::Array() {
	size = 0;
	mas = NULL;
}