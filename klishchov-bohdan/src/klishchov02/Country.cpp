#include"Country.h"
Country::Country() :population(0), area(0), revenue(0), name() {
	name = new char[24];
};
Country::Country(int a, int b, int c, char* Name) :population(a), area(b), revenue(c) {
	name = new char[24];
	strcpy_s(name, 24, Name);
};
Country::Country(const Country &obj) :population(obj.population), area(obj.area), revenue(obj.revenue), name(obj.name) {};

int Country::getPopulation() {
	return Country::population;
}
int Country::getArea() {
	return Country::area;
}
int Country::getRevenue() {
	return Country::revenue;
}
char *Country::getName() {
	return Country::name;
}
void Country::setInfo(char *s) {
	population = rand() % 10000 + 40000;
	area = rand() % 10000 + 40000;
	revenue = rand() % 10000 + 40000;
	strcpy_s(name, 24, s);
}
void Country::setData(int population, int area, int revenue, char *name) {
	strcpy_s(Country::name, 24, name);
	Country::population = population;
	Country::area = area;
	Country::revenue = revenue;
}