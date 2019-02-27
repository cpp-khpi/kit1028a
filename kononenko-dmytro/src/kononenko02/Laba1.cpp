/**
* @file Laba1.cpp
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.02.20
*/

#include "pch.h"
#include <iostream>
#include <string>
#include "Laba1.h"
using std::cin;
using std::cout;
using std::endl;

void infoWork::set(char *creator) {
	mark = rand() % 5 + 1;
	pages = rand() % 336 + 100;
	type = rand() % 2 + 1;
	strcpy_s(name,30,creator);
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

	if (n >= size) {
		return;
	}

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
		if (i == n) {
			this->qual[i].set_n(a, b, c,name);
			i++;
		}
		this->qual[i] = arr[j];
		j++;
	}

	delete[] arr;
}
void studentsWork::del(int n) {
	if (n >= size) {
		return ;
	}
	
	size--;
	infoWork* arr = new infoWork[size + 1];
	
	for (int i = 0; i < size + 1; i++)
		arr[i] = this->qual[i];
	
	delete[] qual;
	qual = new infoWork[size];
	
	for (int i = 0, j = 0; i < size; i++) {
		if (i == n) {
			j++;
		}
		this->qual[i] = arr[j];
		j++;
	
	}
	delete[] arr;
}
void studentsWork::testDel()
{
	int n = 2;
	
	infoWork tester;
	tester = qual[n];
	
	size--;

	infoWork* arr = new infoWork[size + 1];

	for (int i = 0; i < size + 1; i++)
		arr[i] = this->qual[i];

	delete[] qual;
	qual = new infoWork[size];

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
	}else {
		cout << "your luck of skills" << endl;
	}
}
void studentsWork::testAdd()
{
	int n = 2;
	char name[] = { "Kononenko" };
	int a = 4;
	int b = 377;
	int c = 2;
	infoWork tester;
	tester.set_n(a, b, c, name);

	infoWork* arr = new infoWork[size];

	for (int i = 0; i < size; i++)
		arr[i] = this->qual[i];

	delete[] qual;
	size++;
	qual = new infoWork[size];

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
void studentsWork::delArr() {
	delete[] this->qual;
}
void studentsWork::printArr() {
	for (int i = 0; i < size; i++) {
		cout << "Name: " << qual[i].getName();;
		cout << " Mark= " << qual[i].getMark();
		cout << " Size= " << qual[i].getPages();
		if (qual[i].getType() == 1) {
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
	system("color 20");
	studentsWork qualWork;
	int j, x;
	int choose = 0;

	cout << "0 - Exit" << endl;
	cout << "1 - Create vector" << endl;
	cout << "Choose: ";
	cin >> choose;
	if (choose == 1) {
		cout << "Input size: ";
		cin >> x;
		qualWork.getSize(x);
		qualWork.createArr();
	}
	else {
		return 0;
	}

	do {
		cout << "\n";
		cout << "0 - Exit" << endl;
		cout << "1 - Print vector" << endl;
		cout << "2 - Find element by index" << endl;
		cout << "3 - Add element" << endl;
		cout << "4 - Delete element" << endl;
		cout << "5 - Find persent" << endl;
		cout << "Choose: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			qualWork.printArr();
			break;
		case 2:
			cout << "input index: ";
			cin >> j;
			qualWork.gibi(j);
			break;
		case 3:
			cout << "input insert point: ";
			cin >> j;
			qualWork.add(j);
			break;
		case 4:
			cout << "input delete point: ";
			cin >> j;
			qualWork.del(j);
			break;
		case 5:
			qualWork.findP();
			break;
		default:
			break;
		}
	} while (choose != 0);
	qualWork.testAdd();
	qualWork.testDel();

	qualWork.delArr();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();

}