#include "Main.h"

void Array::addProgram(Program *newObj, int ind) {
	ind = ind - 1;

	Program **timeMas = new Program*[size + 1];

	string n;
	string p;
	float om, mg;
	Time *twm;
	Version version;

	timeMas[ind] = newObj;

	int i = 0;
	while (i < ind) {
		timeMas[i] = mas[i];
		i++;
	}
	while (i < size) {
		timeMas[i + 1] = mas[i];
		i++;
	}

	if (size != 0) {
		delete[] mas;
	}
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
	Program **timeMas = new Program*[size - 1];

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
	for (int i = 0; i < size; i++) {
		mas[i]->show();
	}
}

void Array::getProgram(int ind) {
	if (size == 0) {
		cout << "Array is empty" << endl;
		system("pause");
		return;
	}
	mas[ind - 1]->show();
}

void Array::nameSearch(string n) {
	if (size == 0) {
		cout << "Array is empty" << endl;
		system("pause");
		return;
	}

	string na;

	for (int i = 0; i < size; i++) {
		na = mas[i]->getName();
		if (na == n) {
			mas[i]->print();
		}
	}
}

size_t Array::getSize() {
	return size;
}

void Array::delMas() {
	delete[] mas;
}

Array::Array() :size(0), mas(NULL) {
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
		if (p == mas[i]->getPublisher()) {
			removeProgram(i + 1);
		}
	}
}

//void Array::readFromFile(ifstream &objects, string &info, string &n) {
//	string p;
//	float om, mg;
//	Time *timer = new Time;
//	Version version;
//	stringstream infoObj;
//
//	getline(objects, n);
//	if (n == "end") {
//		return;
//	}
//	infoObj << n << "|";
//
//	getline(objects, p);
//	infoObj << p << "|";
//
//	objects >> om;
//	infoObj << om << " ";
//
//	objects >> mg;
//	infoObj << mg << " ";
//
//	objects >> timer->hours;
//	infoObj << timer->hours << " ";
//
//	objects >> timer->minutes;
//	infoObj << timer->minutes << " ";
//
//	objects >> timer->seconds;
//	infoObj << timer->seconds << " ";
//
//	getline(objects, version.name);
//	infoObj << version.name << "|";
//	
//	for (int i = 0; i < 3; i++) {
//		objects >> version.arr[i];
//		infoObj << version.arr[i] << " ";
//	}
//
//	getline(infoObj, info);
//}

void Array::writeToFile() {
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::ofstream out("maliuha07w.txt");
	std::cout.rdbuf(out.rdbuf());
	for (int i = 0; i < size; i++) {
		mas[i]->show();
		
	}
	std::cout.rdbuf(coutbuf);
}

bool Array::inputCheck(string str) {
	regex regular("^[A-Z][a-z][A-Za-z ,.1234567890]*");
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
	for (int i = 0; i < size; i++) {
		if (regex_match(mas[i]->getName(), regular)) {
			mas[i]->show();
		}
	}
}

void Array::merge(int b, int m, int e) {
	int pos1 = b;
	int pos2 = m + 1;
	int pos3 = 0;
	Program **temp = new Program*[e - b + 1];
	string name1, name2;

	while (pos1 <= m && pos2 <= e)
	{
		name1 = mas[pos1]->getName();
		name2 = mas[pos2]->getName();
		if (name1[0] < name2[0]) {
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


