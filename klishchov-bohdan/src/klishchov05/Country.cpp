#include"Country.h"
Country::Country() :population(0), area(0), revenue(0), name() {
};
Country::Country(int a, int b, int c, std::string Name) :population(a), area(b), revenue(c) {
	name = Name;
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

void Country::Human() {
	popul.Human();
}

void Country::RiverName() {
	std::cout << "This is " << river.GetName() << " river" << std::endl;
}