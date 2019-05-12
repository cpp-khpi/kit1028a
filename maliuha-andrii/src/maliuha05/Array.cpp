#include "Main.h"

void Array::addProgram(WorkingProgram &newObj, int ind) {
	ind = ind - 1;

	WorkingProgram *timeMas = new WorkingProgram[size + 1];

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
	WorkingProgram *timeMas = new WorkingProgram[size - 1];

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
	WorkingProgram obj;
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
	mas[ind - 1].print();
}

void Array::nameSearch(string n) {
	if (size == 0) {
		cout << "Array is empty" << endl;
		system("pause");
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

	for (int i = 0; i < size; i++) {
		timeMemory = mas[i].getMemoryGb();
		if (memoryGB < timeMemory) {
			mas[i].print();
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

	string p = "Unknown";
	for (int i = 0; i < size; i++) {
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

	while (true) {
		cout << "Enter name of program:" << endl;
		getline(cin, n);
		if (inputCheck(n) == true) {
			cout << "Enter name of publisher(if you don't know, enter 'Unknown'):" << endl;
			getline(cin, p);
			if (inputCheck(p) == true) {
			break;
			}
		}
		n = "";
		p = "";
	}

	infoObj << n << "|";
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

bool Array::inputCheck(string str) {
	regex regular("^[A-Z][a-z][A-Za-z ,.]*");
	regex regular2(" {2,}");
	if (!regex_match(str, regular) || regex_search(str, regular2)) {
		cout << "This line does not meet the requirements: " << endl;
		cout << str << endl;
		return false;
	}
	else {
		return true;
	}
}

void Array::sortOutput() {
	regex regular("[A-Za-z]*");
	WorkingProgram obj;
	string object;
	for (int i = 0; i < size; i++) {
		if (regex_match(mas[i].getName(), regular)) {
			object = mas[i].print();
			obj.setObj(object);
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
}

void Array::merge(int b, int m, int e) {
	int pos1 = b;
	int pos2 = m + 1;
	int pos3 = 0;
	WorkingProgram *temp = new WorkingProgram[e - b + 1];
	float opMemory1, opMemory2;
	while (pos1 <= m && pos2 <= e)
	{
		opMemory1 = mas[pos1].getOpMemoryMb();
		opMemory2 = mas[pos2].getOpMemoryMb();
		if (opMemory1 < opMemory2) {
			temp[pos3++] = mas[pos1++]; 
		}
		else { 
			temp[pos3++] = mas[pos2++]; 
		}
	}

	while (pos2 <= e) {
		temp[pos3++] = mas[pos2++];
	}
	while (pos1 <= m) {
		temp[pos3++] = mas[pos1++];
	}
	for (pos3 = 0; pos3 < e - b + 1; pos3++) {
		mas[b + pos3] = temp[pos3];
	}
	delete[] temp;
}


void Array::DirectMergeSort(int b, int e)
{
	long m;
	if (b < e)
	{
		m = (b + e) / 2;
		DirectMergeSort(b, m);
		DirectMergeSort(m + 1, e);
		merge(b, m, e);
	}
}


