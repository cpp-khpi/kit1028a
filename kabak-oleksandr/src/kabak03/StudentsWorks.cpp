#pragma once
#include "StudentsWorks.h"
using std::ifstream;

StudentsWorks::StudentsWorks(int SIZE): SIZE(SIZE),list(0),new_student() {
	list = new TestsInfo[SIZE];
	string s;
	ifstream fin("G:\\Visual Studio (SAVES)\\Lab2.3\\Lab2.3\\TEST.txt");
		
	for (int i = 0; i < SIZE; i++) {
		fin >> s;
		list[i].setInfo(i + 1, rand() % 7 + 3, rand() % 4 + 1, s);
	}
	fin >> s;
	new_student.setInfo(SIZE + 1, rand() % 7 + 3, rand() % 4 + 1, s);
	
	fin.close();
}

StudentsWorks::~StudentsWorks() {
	delete[]list;
	cout << "\nMemory cleanup successful!";
}

void StudentsWorks::setNewStud() {
	string s;
	cout << "\nStudent's last name:";
	cin >> s;

	int works, pages;
	int i = 2;
	while (i > 1) {
		cout << "Enter the number of student works(0-10):";
		cin >> works;
		if (works < 0 || works >10) {
			cout << "You entered an invalid value, try again\n";
		}
		else { i = 1; }
	}
	while (i > 0) {
		cout << "Enter the number of pages in works(1-5):";
		cin >> pages;
		if (pages < 1 || pages >5) {
			cout << "You entered an invalid value, try again\n";
		}
		else { i = 0; }
	}

	new_student.setInfo(SIZE + 1, works, pages, s);
}
int StudentsWorks::getSIZE() { return this->SIZE; }
void StudentsWorks::infoWorks(const int num) {
	cout << "The number of finished student works is "<<list[num].getWorks() <<"/10\n";
}

void StudentsWorks::addStud(const int num) {
	SIZE++;
	TestsInfo *tmp_list = new TestsInfo[SIZE];
	for (int i = 0; i < num - 1; i++)
		tmp_list[i] = list[i];
	tmp_list[num - 1] = new_student;
	for (int i = num; i < SIZE; i++)
		tmp_list[i] = list[i - 1];

	delete[]list;
	list = tmp_list;

}
void StudentsWorks::removeStud(const int num) {
	SIZE--;
	TestsInfo *tmp_list = new TestsInfo[SIZE];
	for (int i = 0; i < num; i++)
		tmp_list[i] = list[i];
	for (int i = num; i < SIZE; i++)
		tmp_list[i] = list[i + 1];

	delete[]list;
	list = tmp_list;

}


void StudentsWorks::getStud(const int num)const {
	cout << list[num].printInfo();
}
void StudentsWorks::getNewStud() {
	TestsInfo new_student_tmp = new_student;
	cout << new_student_tmp.printInfo();
}
void StudentsWorks::showAll()const {
	cout<<"Current student journal:\n\n";
	for (int i = 0; i < SIZE; i++)
		cout << list[i].printInfo();
}

