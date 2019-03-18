#pragma once
#include "Header.h"

class Array {
private:
	int size;
	workingProgram *mas;
public:
	Array();

	void addProgram(int ind, char* n, char* p, float mg, float om, float twm);
	void showAll();
	void removeProgram(int ind);
	void getProgram(int ind);
	void nameSearch(char* n);
	void findProgram(float memoryGB);
	void removeViruses();

	void delMas();
	int getSize(int sizeMas);


};
