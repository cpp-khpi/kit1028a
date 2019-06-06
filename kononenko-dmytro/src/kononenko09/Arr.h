#pragma once
#include "Exception.h"

class Arr {
private:
	int size;
	int **arr;
	int *sizes;
public:
	~Arr();
	void readFromFile(string address);
	void WriteMaxArray(string address);
	void WriteToFile(string address);
	int getIndex(int index, int index2);
};