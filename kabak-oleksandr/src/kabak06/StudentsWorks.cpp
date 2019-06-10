/**
* @file StudentsWorks.cpp
* File assignment				| Ñlass methods
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/


#include "StudentsWorks.h"

StudentsWorks::StudentsWorks(string s) : list(0), newStudent() {
	stringstream ss;
	ss << s;
	ss >> SIZE;
	list = new TestsInfo[SIZE];

	string k;
	ifstream fin("G:\\Visual Studio (SAVES)\\Lab2.4\\Lab2.4\\TEST.txt");

	regex reg("([A-Z])([a-z]+)"		  //Surname
		"( ([A-Z])([a-z]+))?"	  //Name
		" ?([0-9])?");		  //mb id
	if (fin.is_open()) {

		for (int i = 0; i < SIZE; i++) {
			getline(fin, k);

			if (regex_match(k, reg))
				list[i].setInfo(i + 1, rand() % 7 + 3, rand() % 4 + 1, k);
			else
				cout << "Check the names in the file for correctness -.-\n";
		}

		getline(fin, k);
		if (regex_match(k, reg))
			newStudent.setInfo(SIZE + 1, rand() % 7 + 3, rand() % 4 + 1, k);
		else
			cout << "Check the names in the file for correctness -.-\n";

	}
	else
		cout << "File failed to open";

	fin.close();
}
StudentsWorks::~StudentsWorks() {
	delete[]list;
	cout << "\nMemory cleanup successful!";
}


int  StudentsWorks::getSIZE() { return this->SIZE; }

void StudentsWorks::infoWorks(const int num) {
	cout << "The number of finished student works is " << list[num].getWorks() << "/10\n";
}

void StudentsWorks::addStud(const int num) {
	SIZE++;
	TestsInfo* tmp_list = new TestsInfo[SIZE];
	for (int i = 0; i < num - 1; i++)
		tmp_list[i] = list[i];
	tmp_list[num - 1] = newStudent;
	for (int i = num; i < SIZE; i++)
		tmp_list[i] = list[i - 1];

	delete[]list;
	list = tmp_list;
}
void StudentsWorks::removeStud(const int num) {
	SIZE--;
	TestsInfo* tmp_list = new TestsInfo[SIZE];
	for (int i = 0; i < num; i++)
		tmp_list[i] = list[i];
	for (int i = num; i < SIZE; i++)
		tmp_list[i] = list[i + 1];

	delete[]list;
	list = tmp_list;

}
void StudentsWorks::sortMarkStud(bool(*comp)(int x, int y)) {
	TestsInfo tmp;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (comp(list[i].getMark(), list[j].getMark())) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}


void StudentsWorks::getStud(const int num)const {
	for (int i = 0; i < SIZE; i++) {
		if (list[i].getNum() == num) {
			cout << list[i].printInfo();
			return;
		}
	}
	cout << "This student does not exist";
}
void StudentsWorks::getNewStud() {
	TestsInfo new_student_tmp = newStudent;
	cout << new_student_tmp.printInfo();
}
void StudentsWorks::setNewStud() {
	string s;
	cout << "\nStudent's last name:";
	cin >> s;

	regex reg_work("^(0-1)");

	int works, pages;


	int i = 2;
	while (i > 1) {
		cout << "Enter the number of student works(0-10):";
		cin >> works;
		if (works < 0 || works > 10) {
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

	newStudent.setInfo(SIZE + 1, works, pages, s);
}

void StudentsWorks::showAll()const {
	cout << "Current student journal:\n\n";
	for (int i = 0; i < SIZE; i++)
		cout << list[i].printInfo();
}
void StudentsWorks::showAll2()const {

	regex ger("(([A-Z])([a-z]+) ([A-Z])([a-z]+)) ?([0-9])?");

	for (int i = 0; i < SIZE; i++) {
		if (regex_match(list[i].getSur(), ger)) {
			cout << list[i].getSur() << endl;
		}
	}
}