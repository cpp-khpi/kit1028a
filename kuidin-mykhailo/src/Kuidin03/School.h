#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class School {
private:
	unsigned int number;
	unsigned int pupils;
	unsigned int cost;
	unsigned int employers;
	string name;
public:
	School() : number(0), pupils(0), cost(0), employers(0), name(""){
		
	}
	School(int num, int cos, int pup, int emp, string p) {
		number = num;
		cost = cos;
		pupils = pup;
		employers = emp;
		name = p;
	}
	School(const School &obj){
		number = obj.number;
		cost = obj.cost;
		pupils = obj.pupils;
		employers = obj.employers;
		this->name = obj.name;
	}
	School& operator= (School obj) {
		number = obj.number;
		cost = obj.cost;
		pupils = obj.pupils;
		employers = obj.employers;
		this->name = obj.name;
		return *this;
	}
	
	int getNumber();
	int getCost();
	int getPupils();
	int getEmployers();
	string getName();
	void setCost(int c);
	void setPupils(int a);
	void setNumber(int n);
	void setEmployers(int d);
	void setName(string p);
	
};

