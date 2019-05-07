#pragma once
#include"Country.h"
class CountryArr {
private:
	int size;
	Country *arr;
public:
	void setSize(int size);
	void newArray(std::string *name);
	void print();
	void addEl(int population, int area, int revenue, std::string s);
	void deleteEl(int l);
	void getByIndex(int index);
	void deleteArray();
	Country maxPop();
	void printMax(Country max);
};