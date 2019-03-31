#pragma once
#include "InfoWork.h"
#include <iostream>
#include <string>
#include <fstream>
using std::ofstream;
using std::ifstream;

class StudentsWork {
private:
	size_t size;
	InfoW *qual;
public:
	StudentsWork() :size(0) {};
	void sortName();
	void setSize(int size);
	void createArr(string* name);
	void sortBy(StudentsWork qual, int x, int(*)());
	void sortByMark(int b);
	void sortBySize(int b);
	void sortByType(int b);
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