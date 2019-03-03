#pragma once
#include "InfoWork.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;


class StudentsWork {
private:
	int size;
	InfoWork *qual;
public:
	void setSize(int size);
	void createArr(char** name);
	void search(int index);
	void printArr();
	void rate();
	void add(int n, int mark, int pages, int type, char * name);
	void del(int n);
	void testDel();
	void testAdd();
	void delArr();
};