#include "StudentsWork.h"
#include "InfoWork.h"
typedef bool(*fun)(int a, int b);

std::ostream& operator<< (std::ostream &out, const StudentsWork &obj) {
	out << "Size: " << obj.size << endl;
	for (int i = 0; i < obj.size; i++) {
		out << obj.qual[i];
	}
	return out;
}

InfoWork& StudentsWork::operator[] (const int index)
{
	cout << "Operator []" << endl;
	return qual[index];
}

std::istream& operator>> (std::istream &in, StudentsWork &obj) {
	in >> obj.size;
	for (int i = 0; i < obj.size; i++) in >> obj.qual[i];
	return in;
}


int StudentsWork::getSize() {
	return size;
}

void StudentsWork::sortByMark(bool(*fun)(int a, int b)) {
	InfoWork temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (fun(qual[i].getMark(),qual[j].getMark())) {
				temp = qual[i];
				qual[i] = qual[j];
				qual[j] = temp;
			}
		}
	}
}

void StudentsWork::sortBySize(bool(*fun)(int a, int b)) {
	InfoWork temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (fun(qual[i].getPages(),qual[j].getPages())) {
				temp = qual[i];
				qual[i] = qual[j];
				qual[j] = temp;
			}
		}
	}
}

void StudentsWork::sortByType(bool(*fun)(int a, int b)) {
	InfoWork temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (fun(qual[i].getType(),qual[j].getType())) {
				temp = qual[i];
				qual[i] = qual[j];
				qual[j] = temp;
			}
		}
	}
}

int StudentsWork::search(int index) {

	cout << "Name: " << qual[index].getName();
	cout << "Mark= " << qual[index].getMark();
	cout << " Size= " << qual[index].getPages();
	if (qual[index].getType() == 1) {
		cout << " BACALAVR" << endl;
	}
	else {
		cout << " MAGISTR" << endl;
	}
	return 0;
}
void StudentsWork::createArr(string *name) {
	qual = new InfoWork[size];
	for (int i = 0; i < size; i++) {
		qual[i].set(name[i]);
	}
}
int StudentsWork::add(InfoWork obj, int n) {

	if (n >= size) {
		return 1;
	}
	int i;
	int j = 0;

	size++;
	InfoWork* arr = new InfoWork[size];
	for (i = 0; i < n; i++) {
		arr[i] = this->qual[j];
		j++;
	}

	arr[n] = obj;

	for (i = n + 1; i < size; i++) {
		arr[i] = this->qual[j];
		j++;
	}
	delete[] qual;
	qual = arr;
	return 0;
}
int StudentsWork::del(int n) {
	if (n >= size) {
		cout << "Error: invalid index" << endl;
		return 2;
	}
	if (size < 2) {
		cout << "Error: you can not delete last element" << endl;
		return 1;
	}
	int j = 0;

	size--;
	InfoWork* arr = new InfoWork[size];
	for (int i = 0; i < n; i++) {
		arr[i] = this->qual[j];
		j++;
	}
	j++;
	for (int i = n; i < size; i++) {
		arr[i] = this->qual[j];
		j++;
	}
	delete[] qual;
	qual = arr;
	return 0;
}
void StudentsWork::testDel()
{
	int n = 2;

	InfoWork tester;
	tester = qual[n];

	size--;

	InfoWork* arr = new InfoWork[size + 1];

	for (int i = 0; i < size + 1; i++)
		arr[i] = this->qual[i];

	delete[] qual;
	qual = new InfoWork[size];

	for (int i = 0, j = 0; i < size; i++) {
		if (i == n) {
			j++;
		}
		this->qual[i] = arr[j];
		j++;

	}
	delete[] arr;
	if (qual[n].getMark() == tester.getMark() && qual[n].getPages() == tester.getPages() && qual[n].getType() == tester.getType()) {
		cout << "Your programm is not bad" << endl;
	}
	else {
		cout << "your luck of skills" << endl;
	}
}
void StudentsWork::testAdd()
{
	int n = 0;
	string name = { "Kononenko" };
	int a = 4;
	int b = 377;
	int c = 2;
	InfoWork tester;
	tester.set_n(a, b, c, name);

	InfoWork* arr = new InfoWork[size];

	for (int i = 0; i < size; i++)
		arr[i] = this->qual[i];

	delete[] qual;
	size++;
	qual = new InfoWork[size];

	for (int i = 0, j = 0; i < size; i++) {
		if (i == n) {
			this->qual[i].set_n(a, b, c, name);
			i++;
		}
		this->qual[i] = arr[j];
		j++;
	}

	delete[] arr;

	if (qual[n].getMark() == tester.getMark() && qual[n].getPages() == tester.getPages() && qual[n].getType() == tester.getType()) {
		cout << "working" << endl;
	}
	else {
		cout << "Your programm is not working well" << endl;
	}
}

void StudentsWork::printArr() {
	for (int i = 0; i < size; i++) {
		cout << "Name: " << qual[i].getName();;
		cout << " Mark= " << qual[i].getMark();
		cout << " Size= " << qual[i].getPages();
		if (qual[i].getType() == 1) {
			cout << " BACALAVR" << endl;
		}
		else {
			cout << " MAGISTR" <<endl;
		}
		//cout << " Teacher: " << qual[i].getTch() << endl;
	}
}
void StudentsWork::printFile(string file) {
	ofstream fout;
	fout.open(file);
	for (int i = 0; i < size; i++) {
		fout << "Name: " << qual[i].getName();;
		fout << " Mark= " << qual[i].getMark();
		fout << " Size= " << qual[i].getPages();
		if (qual[i].getType() == 1) {
			fout << " BACALAVR"<<endl;
		}
		else {
			fout << " MAGISTR" <<endl;
		}
	}
	fout.close();
}
float StudentsWork::rate() { //����� ������� ���������
	float counter = 0;
	for (int i = 0; i < size; i++) {
		int type = qual[i].getType();
		if (type == 2) {
			counter++;
		}
	}
	counter = counter * 100 / this->size;
	return counter;
}
void StudentsWork::setSize(int size) {
	this->size = size;
}
void StudentsWork::sortName() {
	regex regex_sort("[\\w]+[\\s]{1}[\\w]+");
	for (int i = 0; i < size; i++) {
		if (regex_search(qual[i].getName(), regex_sort))
		{
			cout << "Name: " << qual[i].getName();;
			cout << " Mark= " << qual[i].getMark();
			cout << " Size= " << qual[i].getPages();
			if (qual[i].getType() == 1) {
				cout << " BACALAVR" <<endl;
			}
			else {
				cout << " MAGISTR" << endl;
			}
		}
	}
}

bool StudentsWork::check_exist(InfoWork tmp) {
	for (int i = 0; i < size; i++) {
		if (qual[i] == tmp) {
			return true;
		}
	}
	return false;
}

void StudentsWork::delArr() {
	delete[] qual;
}