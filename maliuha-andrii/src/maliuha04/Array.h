#pragma once
#include "Main.h"


class Array {
private:
	int size;
	WorkingProgram *mas;
public:
	Array();
	void writeToFile();
	void readFromFile(ifstream &objects, string &info, string &n);
	void setInfoObj(string &info);
	void addProgram(WorkingProgram &newObj, int ind);
	void showAll();
	void removeProgram(int ind);
	void getProgram(int ind);
	void nameSearch(string n);
	void findProgram(float memoryGB);
	void removeViruses();
	void delMas();
	int getSize();


	bool inputCheck(string str);
	void sortOutput();
};
