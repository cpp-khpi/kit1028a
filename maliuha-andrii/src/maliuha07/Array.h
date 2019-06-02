﻿#pragma once
#include "Main.h"

class Array {
private:
	size_t size;
	Program **mas;
public:
	Array();
	void writeToFile();
	//void readFromFile(ifstream &objects, string &info, string &n);
	void addProgram(Program *newObj, int ind);
	void showAll();
	void removeProgram(int ind);
	void getProgram(int ind);
	void nameSearch(string n);
	void removeViruses();
	void delMas();
	size_t getSize();
	void merge(int b, int m, int e);
	void DirectMergeSort(int b, int e);
	bool inputCheck(string str);
	void sortOutput();
};
