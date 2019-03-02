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
	workingProgram() {
		name = '\0';
		opMemoryMb = 0;
		memoryGb = 0;
		timeWorkMin = 0;
	}
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
	int size;
	int index;
	workingProgram *mas;
public:

	void createArr();
	void addObj(int ind, string n, float mg, float om, float twm);
	void printArr();
	void delObj(int ind);
	void indexOutput();
	void nameSearch(string n);

	void delMas();
	int getIndex(int ind);
	void setIndex(int ind);
	int getSize(int sizeMas);
	void setSize(int sizeMas);
	void createArrTest();
	
	bool testAdd(string n, float om, float mg, float twm, funcsForArray ops);
	bool testDel(string n, float om, float mg, float twm);
};