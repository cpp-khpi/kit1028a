#pragma once
#include "Header.h"

class Array {
private:
	int size;
	workingProgram *mas;
public:
	Array();

	void addProgram(int ind, string n, float mg, float om, float twm);
	void showAll();
	void removeProgram(int ind);
	void getProgram(int ind);
	void searchProgram(string n);

	void deleteArray();
	int getSize(int sizeMas);


};
