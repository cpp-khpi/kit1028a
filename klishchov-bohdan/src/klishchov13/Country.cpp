#include "Country.h"

void Country::setData(string name) {
	popul = rand() % 6342454 + 6532;
	area = rand() % 5678 + 24;
	this->name = name;
}

int Country::getPopul() {
	return popul;
}
int Country::getArea() {
	return area;
}
string Country::getName() {
	return name;
}