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

void School::setName(string p) {
	this->name = p;
}

string School::getName() {
	return name;
}

/* School::deleteName() {
	delete[] name;
}*/