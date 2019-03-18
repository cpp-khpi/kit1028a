#include "Header.h"

void Array::addProgram(int ind, char* n, char* p, float mg, float om, float twm) {
	ind = ind - 1;

	workingProgram *timeMas = new workingProgram[size+1];

	timeMas[ind].setName(n);
	timeMas[ind].setPublisher(p);
	timeMas[ind].setOpMemoryMb(om);
	timeMas[ind].setMemoryGb(mg);
	timeMas[ind].setTimeWorkMin(twm);

	for (int i = 0; i < size; i++) {
		if (i >= ind) {
			n = mas[i].getName(n);
			p = mas[i].getPublisher(p);
			om = mas[i].getOpMemoryMb(om);
			mg = mas[i].getMemoryGb(mg);
			twm = mas[i].getTimeWorkMin(twm);
			timeMas[i + 1].setName(n);
			timeMas[ind].setPublisher(p);
			timeMas[i + 1].setOpMemoryMb(om);
			timeMas[i + 1].setMemoryGb(mg);
			timeMas[i + 1].setTimeWorkMin(twm);
		}
		else {
			n = mas[i].getName(n);
			p = mas[i].getPublisher(p);
			om = mas[i].getOpMemoryMb(om);
			mg = mas[i].getMemoryGb(mg);
			twm = mas[i].getTimeWorkMin(twm);
			timeMas[i].setName(n);
			timeMas[ind].setPublisher(p);
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
	if (size == 0) {
		return;
	}

	ind = ind - 1;

	char *n = NULL, *p = NULL;
	float mg,  om, twm;

	workingProgram *timeMas = new workingProgram[size - 1];
	for (int i = 0; i < size - 1; i++) {
		if (i < ind) {
			n = mas[i].getName(n);
			p = mas[i].getPublisher(p);
			om = mas[i].getOpMemoryMb(om);
			mg = mas[i].getMemoryGb(mg);
			twm = mas[i].getTimeWorkMin(twm);
			timeMas[i].setName(n);
			timeMas[i].setPublisher(p);
			timeMas[i].setOpMemoryMb(om);
			timeMas[i].setMemoryGb(mg);
			timeMas[i].setTimeWorkMin(twm);
		}
		else {
			if (size > 1) {
				n = mas[i].getName(n);
				p = mas[i].getPublisher(p);
				om = mas[i].getOpMemoryMb(om);
				mg = mas[i].getMemoryGb(mg);
				twm = mas[i].getTimeWorkMin(twm);
				timeMas[i + 1].setName(n);
				timeMas[i + 1].setPublisher(p);
				timeMas[i + 1].setOpMemoryMb(om);
				timeMas[i + 1].setMemoryGb(mg);
				timeMas[i + 1].setTimeWorkMin(twm);
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
	mas[ind - 1].print();
}

void Array::nameSearch(char* n) {
	if (size == 0) {
		return;
	}

	char* na = new char[50];

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

Array::Array() :size(0), mas(NULL) {
}