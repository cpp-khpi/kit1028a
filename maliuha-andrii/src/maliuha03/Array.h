#pragma once
#include "Header.h"

class Array {
private:
	int size;
	workingProgram *mas;
public:
	Array();

	void addProgram(workingProgram&, int);
	void showAll();
	void removeProgram(int ind);
	void getProgram(int ind);
	void nameSearch(string n);
	void findProgram(float memoryGB);
	void removeViruses();

	void delMas();
	int getSize(int sizeMas);


};
