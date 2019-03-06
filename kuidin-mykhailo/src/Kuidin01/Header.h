#pragma once

#include <iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;


class School {
private:
	unsigned int number;
	unsigned int pupils;
	unsigned int cost;
public:
	School(int n, int p, int c) {
		number = n;
		pupils = p;
		cost = c;
	}
	School()
	{
		number = 0;
		pupils = 0;
		cost = 0;
	}

	int getNumber();
	int getCost();
	int getPupils();
	void setCost(int c);
	void setPupils(int a);
	void setNumber(int n);
	
	
};


class Functions {
private:
	
public:
	int count;
	School *s;
	School *tmp;
	School *newS;
	School *deltmp;
	School *sTest;
	Functions() {

	}
	
	void printall();
	void addObject(int index, int num, int pup, int cost);
	void delElem(int index);
	void find(int index);
	void createObjects();
	void deleteall();
	void test();
	
};