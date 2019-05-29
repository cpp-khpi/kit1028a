#include "Main.h"

void Array::addProgram(WorkingProgram &newObj, int ind) {
	ind = ind - 1;

	WorkingProgram *timeMas = new WorkingProgram[size + 1];

	string n;
	string p;
	float om, mg;
	Time *twm;
	Version version;

	n = newObj.getProgram();
	p = newObj.getPublisher();
	om = newObj.getRAM();
	mg = newObj.getHDisk();
	twm = newObj.getTimer();
	version = newObj.getVersion();

	timeMas[ind].setName(n);
	timeMas[ind].setPublisher(p);
	timeMas[ind].setRAM(om);
	timeMas[ind].setHDisk(mg);
	timeMas[ind].setTimer(twm);
	timeMas[ind].setVersion(version);

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
	Time *timer;
	Version version;
	for (int i = 0; i < size; i++) {
		showObj = mas[i].print();
		obj.setObj(showObj);
		timer = obj.getTimer();
		version = obj.getVersion();
		cout << "Name of program: " << obj.getProgram() << endl;
		cout << "Publisher: " << obj.getPublisher() << endl;
		cout << "Amount of consumed RAM(Mb): " << obj.getRAM() << endl;
		cout << "Ocupied amount of hard disk memory(Gb): " << obj.getHDisk() << endl;
		cout << "Time of work: " << timer->hours << "(h) " << timer->minutes << "(m) " << timer->seconds << "(s)" << endl;
		cout << "Version: " << version.name << ' ' << version.arr[0] << '.' << version.arr[1] << '.' << version.arr[2] << endl;
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
		na = mas[i].getProgram();
		if (na == n) {
			mas[i].print();
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

void Array::findProgram(float memoryGB) {
	if (size == 0) {
		cout << "Array is empty" << endl;
		return;
	}

	float timeMemory = 0;

	for (int i = 0; i < size; i++) {
		timeMemory = mas[i].getHDisk();
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
	string name;
	string publisher;
	float RAM, hDisk;
	Time *timer = new Time;
	stringstream infoObj;
	Version version;
	
	while (true) {
		cout << "Enter name of program:" << endl;
		getline(cin, name);
		if (inputCheck(name) == true) {
			break;
		}
	}
	while (true) {
		cout << "Enter name of publisher(if you don't know, enter 'Unknown'):" << endl;
		getline(cin, publisher);
		if (inputCheck(publisher) == true) {
			break;
		}
	}

	infoObj << name << "|";
	infoObj << publisher << "|";
	cout << "Enter amount of consumed RAM(Mb):" << endl;
	cin >> RAM;
	infoObj << RAM << " ";
	
	cout << "Enter ocupied amount of hard disk memory(Gg):" << endl;
	cin >> hDisk;
	infoObj << hDisk << " ";

	cout << "Enter time of work:" << endl;
	
	cout << "Hours - ";
	cin >> timer->hours;
	infoObj << timer->hours << " ";
	
	while (true) {
		cout << "(0-59)Minutes - ";
		cin >> timer->minutes;
		infoObj << timer->minutes << " ";
		if (timer->minutes < 0 || timer->minutes >= 60) {
			cout << "You must enter from 0 to 59 minutes, try again" << endl;
		}
		else {
			break;
		}
	}
	while (true) {
		cout << "(0-59)Seconds - ";
		cin >> timer->seconds;
		infoObj << timer->seconds;
		if (timer->seconds < 0 || timer->seconds >= 60) {
			cout << "You must enter from 0 to 59 minutes, try again" << endl;
		}
		else {
			break;
		}
	}

	cin.ignore();
	cout << "Enter version:" << endl;
	cout << "Name of version - ";
	getline(cin, version.name);
	infoObj << version.name << '|';
	
	cout << "First number - ";
	cin >> version.arr[0];
	infoObj << version.arr[0] << " ";
	
	cout << "Second number - ";
	cin >> version.arr[1];
	infoObj << version.arr[1] << " ";

	cout << "Third number - ";
	cin >> version.arr[2];
	infoObj << version.arr[2];

	getline(infoObj, info);
}

void Array::readFromFile(ifstream &objects, string &info, string &n) {
	string p;
	float om, mg;
	Time *timer = new Time;
	Version version;
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

	objects >> timer->hours;
	infoObj << timer->hours << " ";

	objects >> timer->minutes;
	infoObj << timer->minutes << " ";

	objects >> timer->seconds;
	infoObj << timer->seconds << " ";

	getline(objects, version.name);
	infoObj << version.name << "|";
	
	for (int i = 0; i < 3; i++) {
		objects >> version.arr[i];
		infoObj << version.arr[i] << " ";
	}

	getline(infoObj, info);
}

void Array::writeToFile() {
	ofstream txt;
	Time *timer;
	Version version;
	txt.open("maliuha03w.txt");
	if (!txt.is_open()) {
		cout << "File was not opened" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < size; i++) {
		txt << "Name of program: " << mas[i].getProgram() << endl;
		txt << "Publisher: " << mas[i].getPublisher() << endl;
		txt << "Amount of consumed RAM(Mb): " << mas[i].getRAM() << endl;
		txt << "Ocupied amount of hard disk memory(Gb): " << mas[i].getHDisk() << endl;

		version = mas->getVersion();
		timer = mas->getTimer();
		txt << "Time of work: " << timer->hours << "(h) " << timer->minutes << "(m) " << timer->seconds << "(s)" << endl;
		txt << "Version: " << version.name << ' ' << version.arr[0] << '.' << version.arr[1] << '.' << version.arr[2];
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
	Time *timer;
	Version version;
	for (int i = 0; i < size; i++) {
		if (regex_match(mas[i].getProgram(), regular)) {
			object = mas[i].print();
			obj.setObj(object);
			cout << "Name of program: " << obj.getProgram() << endl;
			cout << "Publisher: " << obj.getPublisher() << endl;
			cout << "Amount of consumed RAM(Mb): " << obj.getRAM() << endl;
			cout << "Ocupied amount of hard disk memory(Gb): " << obj.getHDisk() << endl;
			timer = obj.getTimer();
			version = obj.getVersion();
			cout << "Time of work: " << timer->hours << "(h) " << timer->minutes << "(m) " << timer->seconds << "(s)" << endl;
			cout << "Version: " << version.name << ' ' << version.arr[0] << '.' << version.arr[1] << '.' << version.arr[2];
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
	system("pause");
	system("cls");
}