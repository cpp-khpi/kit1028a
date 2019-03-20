#pragma once
#include"Country.h"
class CountryArr {
private:
	int size;
	Country *arr;
public:
	void getSize(int size);
	void newArray(char **s);
	void print();
	void addElem(int population, int area, int revenue, char *name);
	void deleteElem(int l);
	void getByIndex(int index);
	void deleteArray();
	Country maxPop();
	void printMax(Country max);
};