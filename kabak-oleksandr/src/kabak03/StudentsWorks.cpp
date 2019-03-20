#pragma once
#include "StudentsWorks.h"

using std::ifstream;


StudentsWorks::StudentsWorks(string S): SIZE(),list(0),new_student() {
	stringstream ss;
	int SIZE;

	ss << S;
	ss >> SIZE;

	this->SIZE = SIZE;
	list = new TestsInfo[SIZE];

	ifstream fin(/*место расположение файла*/);
	if (!fin.is_open()) 
		cout << "File can't be open!\n"; 
	else {
		string s;

		int i = 0;
		for (; i < SIZE; i++) {
			list[i].setInfo(i + 1);
			fin >> s;
			list[i].setSurname(s);
		}

		fin >> s;
		new_student.setSurname(s);
		new_student.setInfo(SIZE + 1);
	}
	fin.close();
}

StudentsWorks::~StudentsWorks() {
	delete[]list;
	cout << "\nMemory cleanup successful!";
}

void StudentsWorks::setStud(const int num) {
		new_student.setInfo(num);
}
void StudentsWorks::infoWorks(const int num) {
	cout << "The number of finished student works is "<<list[num+1].getWorks() <<"/10\n";
}

void StudentsWorks::add_Stud(const int num) {
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
void StudentsWorks::del_Stud(const int num) {
	SIZE--;
	TestsInfo *tmp_list = new TestsInfo[SIZE];
	for (int i = 0; i < num; i++)
		tmp_list[i] = list[i];
	for (int i = num; i < SIZE; i++)
		tmp_list[i] = list[i + 1];

	delete[]list;
	list = tmp_list;

}


void StudentsWorks::print_stud(const int num)const {
	cout <<list[num].getInfo();
}
void StudentsWorks::print_new_stud() {
	cout << new_student.getInfo();
}
void StudentsWorks::print_all()const {
	cout<<"Current student journal:\n\n";
	for (int i = 0; i < SIZE; i++)
		cout << list[i].getInfo();
}

