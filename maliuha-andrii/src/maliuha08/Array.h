#pragma once
#include "Main.h"

class Array {
protected:
	unsigned int size;
	WorkingProgram *mas;
	Viruses viruses;
public:
	Array();
	void writeToFile();
	void readFromFile(int &sizeMas, Array &ops);
	void addProgram(WorkingProgram &newObj, int ind);
	void showAll();
	void removeProgram(int ind);
	void getProgram(int ind);
	void nameSearch(string n);
	void findProgram(float memoryGB);
	void removeViruses();
	void delMas();
	int getSize();
	void merge(int b, int m, int e);
	void DirectMergeSort(int b, int e);
	bool inputCheck(string str);
	void sortOutput();
	void countElem();

	friend istream& operator>> (istream &in, Array &ops);
	friend ostream& operator<< (ostream &out, Array &ops);
};
