/**
* @file workingProgram.h
* Описание класса WorkingProgram
* @author Maliuga Andrey
* @version 0.6
* @date 30.03.2019
*/

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
	void merge(int b, int m, int e);
	void DirectMergeSort(int b, int e);
	bool inputCheck(string str);
	void sortOutput();
};
