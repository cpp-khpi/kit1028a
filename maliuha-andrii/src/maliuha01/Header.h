#pragma once

#include <cstdlib>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class workingProgram {
private:
	string name;
	float opMemoryMb;
	float memoryGb;
	float timeWorkMin;
public:
	workingProgram();
	void const print();

	void setName(string);
	void setOpMemoryMb(float);
	void setMemoryGb(float);
	void setTimeWorkMin(float);

	string getName(string);
	float getOpMemoryMb(float);
	float getMemoryGb(float);
	float getTimeWorkMin(float);
};

class funcsForArray : public workingProgram {
private:
	int size = 0;
	int index;
	workingProgram *mas;
public:
	
	void addObj(int ind, string n, float mg, float om, float twm);
	void printArr();
	void delObj(int ind);
	void indexOutput();
	void nameSearch(string n);
	
	void delMas();
	int getIndex(int ind);
	void setIndex(int ind);
	int getSize(int sizeMas);


};

void menu(funcsForArray ops);