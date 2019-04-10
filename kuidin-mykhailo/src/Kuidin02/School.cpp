#include "School.h"
#include "InfoStorge.h"

void School::setNumber(int n) {
	number = n;
}
void School::setPupils(int a) {
	pupils = a;
}
void School::setCost(int c) {
	cost = c;
}
void School::setEmployers(int d) {
	employers = d;
}
void InfoStorge::setCount(int c) {
	count = c;
}


int School::getNumber() {
	return number;
}

int School::getCost() {
	return cost;
}

int School::getPupils() {
	return pupils;
}

int School::getEmployers() {
	return employers;
}

void School::setName(char *p) {
	name = (char*) operator new (sizeof(char) * 256);
	strcpy_s(name,30, p);
}

void School::getName(char *ptr) {
	strcpy(ptr,name);
}

School::School() : number(0), pupils(0), cost(0), employers(0), name(NULL) {
	
}

School::School(int num, int cos, int pup, int emp, char *p) {
	number = num;
	cost = cos;
	pupils = pup;
	employers = emp;
	strcpy(name, p);
}

School::School(const School &obj) {
	number = obj.number;
	cost = obj.cost;
	pupils = obj.pupils;
	employers = obj.employers;
	strcpy(name, obj.name);
}

School::~School() {
	delete[] name;
}