#include "pch.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class infoWork {
private:
	int pages;
	int mark;
	int type;
	char *name;
public:
	infoWork() {
		cout << "konstructor " << endl;
		this->pages = 0;
		this->mark = 0;
		this->type = 0;
		name = (char *) operator new (sizeof(char) * 256);
	}
	infoWork &operator=(const infoWork &obj) {
		cout << "copy operator" << endl;
		this->pages = obj.pages;
		strcpy_s(name, 256, obj.name);
		this->mark = obj.mark;
		this->type = obj.type;
		return *this;
	}
	~infoWork() {
		delete[] name;
	}
	void set(char *creator);
	void set_n(int a, int b, int c, char *creator);
	int getPages();
	int getMark();
	int getType();
	char* getName();
};

void infoWork::set(char *creator) {
	this->mark = rand() % 5 + 1;
	this->pages = rand() % 336 + 100;
	this->type = rand() % 2 + 1;
	strcpy_s(this->name,30,creator);
}
void infoWork::set_n(int a, int b, int c,char *creator) {
	this->mark = a;
	this->pages = b;
	this->type = c;
	strcpy_s(this->name,30,creator);
}
int infoWork::getMark() {
	return this->mark;
}
int infoWork::getPages() {
	return this->pages;
}
int infoWork::getType() {
	return this->type;
}
char* infoWork::getName() {
	return this->name;
}

class studentsWork{
private:
	int size;
	infoWork *qual;
public:
	void getSize(int x);
	void createArr();
	void gibi(int index);
	void printArr();
	void findP();
	void add(int n);
	void del(int n);
	void delArr();
};

void studentsWork::gibi(int index) {
	if (index >= size) {
		cout << "imposible to find\n";
		return;
	}
	int m = qual[index].getMark();
	int p = qual[index].getPages();
	int type = qual[index].getType();
	char* name = qual[index].getName();

	cout << "Name: " << name;
	cout << "Mark= " << m;
	cout << " Size= " << p;
	if (type == 1) {
		cout << " BACALAVR" << endl;
	}
	else {
		cout << " MAGISTR" << endl;
	}
}
void studentsWork::getSize(int x) {
	this->size = x;
}
void studentsWork::createArr() {
	qual = new infoWork[size];;
	for (int i = 0; i < size; i++) {
		char name[30];
		cout << "Input name: ";
		cin >> name;
		qual[i].set(name);
	}
}
void studentsWork::add(int n) {
	int a, b, c;
	char name[30];

	cout << "input name: ";
	cin >> name;
	cout << "input mark: ";
	cin >> a;
	cout << "input size: ";
	cin >> b;
	cout << "input type: ";
	cin >> c;

	infoWork* arr = new infoWork[size];

	for (int i = 0; i < size; i++)
		arr[i] = this->qual[i];

	delete[] qual;
	size++;
	qual = new infoWork[size];

	for (int i = 0, j = 0; i < size; i++) {
		if (i == n - 1) {
			this->qual[i].set_n(a, b, c,name);
			i++;
		}
		this->qual[i] = arr[j];
		j++;
	}

	delete[] arr;
}
void studentsWork::del(int n) {
	
	size--;
	infoWork* arr = new infoWork[size + 1];
	
	for (int i = 0; i < size + 1; i++)
		arr[i] = this->qual[i];
	
	delete[] qual;
	qual = new infoWork[size];
	
	for (int i = 0, j = 0; i < size; i++) {
		if (i == n - 1) {
			j++;
		}
		this->qual[i] = arr[j];
		j++;
	
	}
	delete[] arr;
}
void studentsWork::delArr() {
	delete[] this->qual;
}
void studentsWork::printArr() { // 
	for (int i = 0; i < size; i++) {
		int m = qual[i].getMark();
		int p = qual[i].getPages();
		int type = qual[i].getType();
		char* name = qual[i].getName();
		cout << "Name: " << name;
		cout << " Mark= " << m;
		cout << " Size= " << p;
		if (type == 1) {
			cout << " BACALAVR" << endl;
		}
		else {
			cout << " MAGISTR" << endl;
		}
	}
} 
void studentsWork::findP() { //найти процент магистров
	float counter= 0;
	for (int i = 0; i < size; i++) {
		int type = qual[i].getType();
		if (type == 2) {
			counter++;
		}
	}
	counter = counter * 100 / this->size;
	cout << "There your persent ";
	cout << counter;
}


int main() {
	system("color 70");
	studentsWork qualWork;
	int j, x;
	int choose = 0;
	
	do {
		cout << "\n";
		cout << "0 - Exit" << endl;
		cout << "1 - Create vector" << endl;
		cout << "2 - Print vector" << endl;
		cout << "3 - Find element by index" << endl;
		cout << "4 - Add element" << endl;
		cout << "5 - Delete element" << endl;
		cout << "6 - Find persent" << endl;
		cout << "Choose: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Input size: ";
			cin >> x;
			qualWork.getSize(x);
			qualWork.createArr();
			break;
		case 2:
			qualWork.printArr();
			break;
		case 3:
			cout << "input index: ";
			cin >> j;
			qualWork.gibi(j);
			break;
		case 4:
			cout << "input insert point: ";
			cin >> j;
			qualWork.add(j);
			break;
		case 5:
			cout << "input delete point: ";
			cin >> j;
			qualWork.del(j);
			break;
		case 6:
			qualWork.findP();
			break;
		default:
			break;
		}
	} while (choose != 0);

	qualWork.delArr();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();

}