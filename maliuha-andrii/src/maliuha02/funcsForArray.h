#pragma once
#include "Header.h"

class funcsForArray {
private:
	int size;
	workingProgram *mas;
public:
	funcsForArray();

	void addObj(int ind, char* n, float mg, float om, float twm);
	void printArr();
	void delObj(int ind);
	void indexOutput(int ind);
	void nameSearch(char* n);

	void delMas();
	int getSize(int sizeMas);


};
