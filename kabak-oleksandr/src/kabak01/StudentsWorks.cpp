#pragma once
#include "StudentsWorks.h"

StudentsWorks::StudentsWorks(int SIZE): SIZE(SIZE),list(),new_student(){
	list = new TestsInfo[SIZE];

	for (int i = 0; i < SIZE; i++)
		list[i].setInfo(i + 1, rand() % 7 + 3, rand() % 4 + 1);
	
	new_student.setInfo(SIZE + 1, rand() % 7 + 3, rand() % 4 + 1);
}

StudentsWorks::~StudentsWorks() {
	delete[]list;
	printf("\nMemory cleanup successful!");
}

int  StudentsWorks::getSIZE()const {return this->SIZE;}
void StudentsWorks::setNewStud() {
	int works, pages;
	int i = 2;
	while (i > 1) {
		cout << "Enter the number of student works(0-10)";
		cin >> works;
		if (works < 0 || works >10) {
			cout << "You entered an invalid value, try again\n";
		}
		else { i = 1; }
	}
	while (i > 0) {
		cout << "Enter the number of pages in works(1-5)";
		cin >> pages;
		if (pages < 1 || pages >5) {
			cout << "You entered an invalid value, try again\n";
		}
		else { i = 0; }
	}

	new_student.setInfo(SIZE + 1, works, pages);
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
	list[num].printInfo();
}
void StudentsWorks::getNewStud()const{
	cout << "The new number will be ->  ";
	new_student.printInfo();
}
void StudentsWorks::showAll()const {
	printf("\nCurrent student journal:\n\n");
	for (int i = 0; i < SIZE; i++) {
		list[i].printInfo();
	}
}
