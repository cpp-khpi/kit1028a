#pragma once
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
	
	School() : number(10), pupils(10), cost(10), employers(10) {
		strcpy(name, "0");
	}

	School(int num, int cos, int pup, int emp, char *p) {
		number = num;
		cost = cos;
		pupils = pup;
		employers = emp;
		strcpy(name, p);
	}
	School(const School &obj){
		number = obj.number;
		cost = obj.cost;
		pupils = obj.pupils;
		employers = obj.employers;
		strcpy(name, obj.name);
	}
	/*~School() {
		delete[] name;
	}*/
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
	void deleteName();
};

