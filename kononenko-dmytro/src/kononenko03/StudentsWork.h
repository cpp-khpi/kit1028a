#pragma once
#include "InfoWork.h"
#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;


class StudentsWork {
private:
	int size;
	InfoWork *qual;
public:
	void setSize(int size);
	void createArr(string* name);
	void search(int index);
	void printArr();
	void rate();
	void printFile(string file);
	void add(int n, int mark, int pages, int type, string name);
	void del(int n);
	void testDel();
	void testAdd();
	void delArr();
};