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
		cout << "Array is empty" << endl;
		system("pause");
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
		cout << "Array is empty" << endl;
		return;
	}
	workingProgram obj;
	string showObj;
	for (int i = 0; i < size; i++) {
		showObj = mas[i].print();
		obj.setObj(showObj);
		
		cout << "Name of program: " << obj.getName() << endl;
		cout << "Publisher: " << obj.getPublisher() << endl;
		cout << "Amount of consumed RAM(Mb): " << obj.getOpMemoryMb() << endl;
		cout << "Ocupied amount of hard disk memory(Gb): " << obj.getMemoryGb() << endl;
		cout << "Time of work (in minutes): " << obj.getTimeWorkMin() << endl;
		cout << endl;
		obj.setName("");
		obj.setPublisher("");
	}
}

void Array::getProgram(int ind) {
	if (size == 0) {
		cout << "Array is empty" << endl;
		system("pause");
		return;
	}
	string showObj;
	workingProgram obj;

	showObj = mas[ind-1].print();
	obj.setObj(showObj);

	cout << "Name of program: " << obj.getName() << endl;
	cout << "Publisher: " << obj.getPublisher() << endl;
	cout << "Amount of consumed RAM(Mb): " << obj.getOpMemoryMb() << endl;
	cout << "Ocupied amount of hard disk memory(Gb): " << obj.getMemoryGb() << endl;
	cout << "Time of work (in minutes): " << obj.getTimeWorkMin() << endl;
}

void Array::nameSearch(string n) {
	if (size == 0) {
		cout << "Array is empty" << endl;
		system("pause");
		return;
	}

	string na;
	string showObj;
	workingProgram obj;
	for (int i = 0; i < size; i++) {
		na = mas[i].getName();
		if (na == n) {

			showObj = mas[i].print();
			obj.setObj(showObj);

			cout << "Name of program: " << obj.getName() << endl;
			cout << "Publisher: " << obj.getPublisher() << endl;
			cout << "Amount of consumed RAM(Mb): " << obj.getOpMemoryMb() << endl;
			cout << "Ocupied amount of hard disk memory(Gb): " << obj.getMemoryGb() << endl;
			cout << "Time of work (in minutes): " << obj.getTimeWorkMin() << endl;
		}
	}
}

int Array::getSize() {
	return size;
}

void Array::delMas() {
	delete[] mas;
}

Array::Array() :size(0), mas(NULL) {
}

void Array::findProgram(float memoryGB) {
	if (size == 0) {
		cout << "Array is empty" << endl;
		return;
	}

	float timeMemory = 0;
	string showObj;
	workingProgram obj;
	for (int i = 0; i < size; i++) {
		timeMemory = mas[i].getMemoryGb();
		if (memoryGB < timeMemory) {
			showObj = mas[i].print();
			obj.setObj(showObj);

			cout << "Name of program: " << obj.getName() << endl;
			cout << "Publisher: " << obj.getPublisher() << endl;
			cout << "Amount of consumed RAM(Mb): " << obj.getOpMemoryMb() << endl;
			cout << "Ocupied amount of hard disk memory(Gb): " << obj.getMemoryGb() << endl;
			cout << "Time of work (in minutes): " << obj.getTimeWorkMin() << endl;
		}
	}

}

void Array::removeViruses() {
	if (size == 0) {
		cout << "Array is empty" << endl;
		system("pause");
		system("cls");
		return;
	}

	string p = "unknown";
	int i = 0;
	for (; i < size; i++) {
		if (p == mas[i].getPublisher()) {
			removeProgram(i + 1);
		}
	}
}

void Array::setInfoObj(string &info) {
	string n;
	string p;
	float om, mg, twm;
	stringstream infoObj;
	
	cout << "Enter name of program:" << endl;
	getline(cin, n);
	infoObj << n << "|";

	cout << "Enter name of publisher(if you don't know, enter 'unknown'):" << endl;
	getline(cin, p);
	infoObj << p << "|";
	
	cout << "Enter amount of consumed RAM(Mb):" << endl;
	cin >> om;
	infoObj << om << " ";
	
	cout << "Enter ocupied amount of hard disk memory(Gg):" << endl;
	cin >> mg;
	infoObj << mg << " ";

	cout << "Enter time of work (in minutes):" << endl;
	cin >> twm;
	infoObj << twm << " ";

	getline(infoObj, info);
}

void Array::readFromFile(ifstream &objects, string &info, string &n) {
	string p;
	float om, mg, twm;
	stringstream infoObj;

	getline(objects, n);
	if (n == "end") {
		return;
	}
	infoObj << n << "|";

	getline(objects, p);
	infoObj << p << "|";

	objects >> om;
	infoObj << om << " ";

	objects >> mg;
	infoObj << mg << " ";

	objects >> twm;
	infoObj << twm << " ";

	getline(objects, n);
	getline(infoObj, info);
}

void Array::writeToFile() {
	ofstream txt;
	txt.open("E:/File for projects/maliuha03w.txt");
	if (!txt.is_open()) {
		cout << "File was not opened" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < size; i++) {
		txt << "Name of program: " << mas[i].getName() << endl;
		txt << "Publisher: " << mas[i].getPublisher() << endl;
		txt << "Amount of consumed RAM(Mb): " << mas[i].getOpMemoryMb() << endl;
		txt << "Ocupied amount of hard disk memory(Gb): " << mas[i].getMemoryGb() << endl;
		txt << "Time of work (in minutes): " << mas[i].getTimeWorkMin() << endl;
		txt << "------------------------------------------------------" << endl;
	}
}
