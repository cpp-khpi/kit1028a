#pragma once
#include"Country.h"
#include"classes.h"

class CountryArr {
private:
	int size = 0;
	Island *island;
	Mainland *mainland;
	Information info;
public:
	void newArray(std::string name);
	void print();
	void addEl(int population, int area, int revenue, std::string s);
	void deleteEl(int l);
	void getByIndex(int index);
	void deleteArray();
	Island maxPop();
	void printMax(Island max);
	void sortArea(bool(*comp)(int x, int y));
	friend std::ostream& operator<< (std::ostream &out, const CountryArr &obj);
	friend std::istream& operator>> (std::istream &in, CountryArr &obj);
	Country &operator[] (const int index);
};