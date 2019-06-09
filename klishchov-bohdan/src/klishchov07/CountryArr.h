#pragma once
#include"Country.h"
#include"Information.h"
#include "Republic.h"

class CountryArr {
private:
	int size = 0;
	Republic *republic;
	Information info;
public:
	void newArray(string name, string pres);
	void print();
	void addEl(int population, int area, int revenue, string s, string pres);
	void deleteEl(int l);
	void getByIndex(int index);
	void deleteArray();
	Republic maxPop();
	void printMax(Republic max);
	void sortArea(bool(*comp)(int x, int y));
};