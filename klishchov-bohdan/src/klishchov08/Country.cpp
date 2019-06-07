#include"Country.h"

Country::Country() :population(0), area(0), revenue(0) {
}

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

std::ostream& operator<< (std::ostream &out, const Country &obj) {
	out << obj.name << ": " << obj.area << std::endl;
	out << obj.name << ": " << obj.population << std::endl;
	return out;
}
std::istream& operator>> (std::istream &in, Country &obj) {
	in >> obj.name;
	in >> obj.population;
	in >> obj.area;
	in >> obj.revenue;
	return in;
}
Country& Country::operator= (const Country &obj) {
	area = obj.area;
	population = obj.population;
	revenue = obj.revenue;
	return *this;
}

Country::~Country() {

}