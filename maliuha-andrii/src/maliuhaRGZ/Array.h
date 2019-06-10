#pragma once
#include "Main.h"

class Array {
private:
	int size;
	Program **mas;
public:
	Array();
	void writeToFile();
	void readFromFile(int &sizeMas, Array &ops);
	void addProgram(Program *newObj, int ind);
	const void showAll();
	void removeProgram(int ind);
	const void getProgram(int ind);
	void nameSearch(string n);
	void removeViruses();
	void delMas();
	int getSize();
	void merge(int b, int m, int e);
	void DirectMergeSort(int b, int e);
	bool inputCheck(string str);
	const void sortOutput();
	const void findProgram(float memoryGB);
};
