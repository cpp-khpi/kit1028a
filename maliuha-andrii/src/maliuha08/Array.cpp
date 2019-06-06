#include "Main.h"

void Array::addProgram(WorkingProgram &newObj, int ind) {
	ind = ind - 1;
	WorkingProgram *timeMas = new WorkingProgram[size + 1];

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
	for (int i = 0; i < size; i++) {
		cout << mas[i];
	}
}

void Array::getProgram(int ind) {
	if (size == 0) {
		cout << "Array is empty" << endl;
		system("pause");
		return;
	}
	cout << mas[ind - 1];
}

void Array::nameSearch(string n) {
	if (size == 0) {
		cout << "Array is empty" << endl;
		system("pause");
		return;
	}

	string na;

	for (int i = 0; i < size; i++) {
		na = mas[i].getProgram();
		if (na == n) {
			cout << mas[i];
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
		timeMemory = mas[i].getHDisk();
		if (memoryGB < timeMemory) {
			cout << mas[i];
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


void Array::readFromFile(int &sizeMas, Array &ops) {
	string publisher, name = " ";
	float RAM, hDisk;
	Time timer;
	Version version;
	stringstream infoObj;
	string info;
	ifstream objects("maliuha08.txt");

	if (!objects.is_open()) {
		cout << "File was not opened" << endl;
		system("pause");
		return;
	}

	for (int i = 0; i < sizeMas + 1; i++) {
		getline(objects, name);
		if (name == "") {
			getline(objects, name);
		}
			if (name != "") {
			infoObj << name << "|";

			getline(objects, publisher);
			infoObj << publisher << "|";

			objects >> RAM;
			infoObj << RAM << " ";

			objects >> hDisk;
			infoObj << hDisk << " ";

			objects >> timer.hours;
			infoObj << timer.hours << " ";

			objects >> timer.minutes;
			infoObj << timer.minutes << " ";

			objects >> timer.seconds;
			infoObj << timer.seconds << " ";

			getline(objects, version.name);
			if (version.name == "") {
				getline(objects, version.name);
			}
			infoObj << version.name << "|";

			for (int i = 0; i < 3; i++) {
				objects >> version.arr[i];
				infoObj << version.arr[i] << " ";
			}

			getline(infoObj, info);

			WorkingProgram obj;
			obj.setObj(info);
			ops.addProgram(obj, sizeMas + 1);

			name = "";
			sizeMas++;
			infoObj.str("");
			infoObj.clear();
		}
	}
	objects.close();
}

void Array::writeToFile() {
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::ofstream out("maliuha08w.txt");
	std::cout.rdbuf(out.rdbuf());
	for (int i = 0; i < size; i++) {
		cout << mas[i];
	}
	std::cout.rdbuf(coutbuf);
}

bool Array::inputCheck(string str) {
	regex regular("^[A-Z][A-Za-z ,.1234567890]*");
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
		if (!regex_match(mas[i].getProgram(), regular)) {
			cout << mas[i];
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
		opMemory1 = mas[pos1].getRAM();
		opMemory2 = mas[pos2].getRAM();
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



void Array::countElem() {
	if (size == 0) {
		cout << "Array is empty" << endl;
		system("pause");
		system("cls");
		return;
	}
	int amount = 0;
	string p = "Unknown";
	for (int i = 0; i < size; i++) {
		if (p == mas[i].getPublisher()) {
			amount++;
		}
	}
	viruses.setAmountV(amount);
	cout << "Amount of viruses: " << amount << endl;
}

istream& operator>> (istream &in, Array &ops) {
	cout << "Enter size of array: ";
	in >> ops.size;
	ops.mas = new WorkingProgram[ops.size];
	for (int i = 0; i < ops.size; i++) {
		cin >> ops.mas[i];
	}
	ops.countElem();
	return in;
}

ostream& operator<< (ostream &out, Array &ops) {
	out << "Size of array: " << ops.size << endl;
	for (int i = 0; i < ops.size; i++) {
		cout << ops.mas[i];
	}
	out << "Amount of suspicious programs: " << ops.viruses.getAmountV() << endl;
	return out;
}