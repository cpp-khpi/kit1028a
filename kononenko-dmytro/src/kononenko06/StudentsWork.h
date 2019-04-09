#pragma once
#include "InfoWork.h"
#include <iostream>
#include <string>
#include <fstream>
using std::ofstream;
using std::ifstream;

class StudentsWork {
private:
	int size;
	InfoW *qual;
public:
	StudentsWork() :size(0) {};
	void sortName();
	void setSize(int size);
	void createArr(string* name);
	void sortByMark(bool(*fun)(int a, int b));
	void sortBySize(bool(*fun)(int a, int b));
	void sortByType(bool(*fun)(int a, int b));
	int search(int index);
	void printArr();
	float rate();
	void printFile(string file);
	int add(InfoWork obj,int n);
	int del(int n);
	void testDel();
	void testAdd();
	void delArr();
};