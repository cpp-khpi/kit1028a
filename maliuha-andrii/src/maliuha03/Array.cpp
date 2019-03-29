#include "Header.h"

void Array::addProgram(workingProgram &newObj, int ind) {
	ind = ind - 1;

	workingProgram *timeMas = new workingProgram[size + 1];

	string n;
	string p;
	float om, mg, twm;

	n = newObj.getName();
	p = newObj.getPublisher();
	om = newObj.getOpMemoryMb();
	mg = newObj.getMemoryGb();
	twm = newObj.getTimeWorkMin();

	timeMas[ind].setName(n);
	timeMas[ind].setPublisher(p);
	timeMas[ind].setOpMemoryMb(om);
	timeMas[ind].setMemoryGb(mg);
	timeMas[ind].setTimeWorkMin(twm);

	int i = 0;
	while (i < ind) {
		timeMas[i] = mas[i];
		i++;
	}
	while (i < size) {
		timeMas[i + 1] = mas[i];
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
	workingProgram *timeMas = new workingProgram[size - 1];

	int i = 0;
	while (i < ind) {
		timeMas[i] = mas[i];
		i++;
	}

	if (size > 1) {
		while (i < size - 1) {
			timeMas[i] = mas[i + 1];
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

	stringstream showObj;
	for (int i = 0; i < size; i++) {
		stringstream showObj = mas[i].print();
		cout << showObj.str() << endl;
	}
}

void Array::getProgram(int ind) {
	if (size == 0) {
		return;
	}
	mas[ind - 1].print();
}

void Array::nameSearch(string n) {
	if (size == 0) {
		return;
	}

	string na;

	for (int i = 0; i < size; i++) {
		na = mas[i].getName();
		if (na == n) {
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

	string p = "unknown";
	string p2 = "";
	int i = 0;
	for (; i < size; i++) {
		p2 = mas[i].getPublisher();
		if (p == p2) {
			removeProgram(i + 1);
		}
	}
}

void Array::setInfoObj(workingProgram &obj) {
	string n;
	string p;
	float om, mg, twm;
	
	cout << "Enter name of program:" << endl;
	getline(cin, n);

	cout << "Enter name of publisher(if you don't know, enter 'unknown'):" << endl;
	getline(cin, p);

	cout << "Enter amount of consumed RAM(Mb):" << endl;
	cin >> om;
	cout << "Enter ocupied amount of hard disk memory(Mg):" << endl;
	cin >> mg;
	cout << "Enter time of work (in minutes):" << endl;
	cin >> twm;

	obj.setName(n);
	obj.setPublisher(p);
	obj.setOpMemoryMb(om);
	obj.setMemoryGb(mg);
	obj.setTimeWorkMin(twm);
}