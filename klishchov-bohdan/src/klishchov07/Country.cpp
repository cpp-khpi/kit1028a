#include"Country.h"

int Country::getPopulation() {
	return Country::population;
}
int Country::getArea() {
	return Country::area;
}
int Country::getRevenue() {
	return Country::revenue;
}
std::string Country::getName() {
	return Country::name;
}
void Country::getInfo(std::string str) {
	population = rand() % 10000 + 40000;
	area = rand() % 10000 + 40000;
	revenue = rand() % 10000 + 40000;
	name = str;
}
void Country::setData(int population, int area, int revenue, std::string name) {
	Country::name = name;
	Country::population = population;
	Country::area = area;
	Country::revenue = revenue;
}
