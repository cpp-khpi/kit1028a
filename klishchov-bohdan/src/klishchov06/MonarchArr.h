#pragma once
#include "Monarch.h"

class MonarchArr {
private:
	Monarch *arr;
	int size = 0;
public:
	void newArray(std::string name, std::string type);
	void print();
	void addEl(int population, int area, int revenue, std::string s, std::string type);
	void deleteEl(int l);
	void getByIndex(int index);
	void deleteArray();
	Monarch maxPop();
	void printMax(Monarch max);
	void sortArea(bool(*comp)(int x, int y));
	int getSize();
};