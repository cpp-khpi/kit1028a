#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using namespace std;

class School {
private:
	unsigned int number;
	unsigned int pupils;
	unsigned int cost;
	unsigned int employers;
	char *name;
public:

	School();
	School(int num, int cos, int pup, int emp, char *p);
	School(const School &obj);
	~School();
	int getNumber();
	int getCost();
	int getPupils();
	int getEmployers();
	void getName(char *ptr);
	void setCost(int c);
	void setPupils(int a);
	void setNumber(int n);
	void setEmployers(int d);
	void setName(char *p);
};

