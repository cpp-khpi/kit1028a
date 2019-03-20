#pragma once
#include "StudentsWorks.h"

StudentsWorks::StudentsWorks(int SIZE):SIZE(0){
	new_student.setInfo(SIZE + 1);
	list = new TestsInfo[SIZE];
	for (int i = 0; i < SIZE; i++)
		list[i].setInfo(i + 1);
	this->SIZE = SIZE;
}
StudentsWorks::~StudentsWorks() {
	delete[]list;
	printf("\nMemory cleanup successful!");
}

int  StudentsWorks::getSIZE()const {
	return this->SIZE;
}
void StudentsWorks::setStud(const int num) {
	if (num <= list[SIZE].idInfo() ) {
		printf("\nSince this number is incorrect, its number will be next after the last:%d\n",SIZE+1);
	}
	else if(num==SIZE+1){
		new_student.setInfo(num);
	}
	else if (num > SIZE + 1) {
		printf("Since this number exceeds the size of the list, its number will be the next after the last:%d\n", SIZE + 1);
		new_student.setInfo(SIZE + 1);
	}
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
	list[num].getInfo();
}
void StudentsWorks::print_new_stud()const{
	new_student.getInfo();
}
void StudentsWorks::print_all()const {
	printf("Current student journal:\n\n");
	for (int i = 0; i < SIZE; i++) {
		list[i].getInfo();
	}
}
