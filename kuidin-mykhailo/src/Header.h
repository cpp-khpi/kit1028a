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
	School(const School &obj);
	int getNumber();
	int getCost();
	int getPupils();
	void setCost(int c);
	void setPupils(int a);
	void setNumber(int n);
	
	
};


class functions: public School {
private:
	
public:
	int count;
	functions *s;
	functions *tmp;
	functions *newS;
	functions *deltmp;
	functions *sTest;
	functions() :School() {

	}
	//~functions(){};
	void printall();
	void addObject(int index);
	void delElem(int index);
	void find(int index);
	void print();
	void createObjects();
	void deleteall();
	void test();
	//void setCount(int c);
};