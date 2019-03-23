#include "Header.h"

void Array::addProgram(int ind, char* n, char* p, float mg, float om, float twm) {
	ind = ind - 1;

	workingProgram *timeMas = new workingProgram[size+1];

	timeMas[ind].setName(n);
	timeMas[ind].setPublisher(p);
	timeMas[ind].setOpMemoryMb(om);
	timeMas[ind].setMemoryGb(mg);
	timeMas[ind].setTimeWorkMin(twm);

	int i = 0;
	while (i < ind) {
		n = mas[i].getName();
		p = mas[i].getPublisher();
		om = mas[i].getOpMemoryMb();
		mg = mas[i].getMemoryGb();
		twm = mas[i].getTimeWorkMin();
		timeMas[i].setName(n);
		timeMas[i].setPublisher(p);
		timeMas[i].setOpMemoryMb(om);
		timeMas[i].setMemoryGb(mg);
		timeMas[i].setTimeWorkMin(twm);
		i++;
	}
	while (i < size) {
		n = mas[i].getName();
		p = mas[i].getPublisher();
		om = mas[i].getOpMemoryMb();
		mg = mas[i].getMemoryGb();
		twm = mas[i].getTimeWorkMin();
		timeMas[i + 1].setName(n);
		timeMas[i + 1].setPublisher(p);
		timeMas[i + 1].setOpMemoryMb(om);
		timeMas[i + 1].setMemoryGb(mg);
		timeMas[i + 1].setTimeWorkMin(twm);
		i++;
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

	char *n = new char[50];
	char *p = new char[50];
	float mg,  om, twm;

	workingProgram *timeMas = new workingProgram[size - 1];
	
	int i = 0;
	while (i < ind) {
		n = mas[i].getName();
		p = mas[i].getPublisher();
		om = mas[i].getOpMemoryMb();
		mg = mas[i].getMemoryGb();
		twm = mas[i].getTimeWorkMin();
		timeMas[i].setName(n);
		timeMas[i].setPublisher(p);
		timeMas[i].setOpMemoryMb(om);
		timeMas[i].setMemoryGb(mg);
		timeMas[i].setTimeWorkMin(twm);
		i++;
	}
	if (size > 1) {
		while(i < size - 1) {
			n = mas[i + 1].getName();
			p = mas[i + 1].getPublisher();
			om = mas[i + 1].getOpMemoryMb();
			mg = mas[i + 1].getMemoryGb();
			twm = mas[i + 1].getTimeWorkMin();
			timeMas[i].setName(n);
			timeMas[i].setPublisher(p);
			timeMas[i].setOpMemoryMb(om);
			timeMas[i].setMemoryGb(mg);
			timeMas[i].setTimeWorkMin(twm);
			i++;
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
		strcpy(na, mas[i].getName());
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

void Array::findProgram(float memoryGB) {
	if (size == 0) {
		return;
	}
	
	float timeMemory = 0;
	
	for (int i = 0; i < size; i++) {
		timeMemory = mas[i].getMemoryGb();
		if (memoryGB < timeMemory) {
			mas[i].print();
		}
	}

}

void Array::removeViruses() {
	if (size == 0) {
		return;
	}
	
	char *p = "unknown";
	char *p2 = NULL;
	for (int i = 0; i < size; i++) {
		p2 = mas[i].getPublisher();
		if (strcmp(p, p2) == 0) {
			removeProgram(i);
		}
	}
}