/**
* @file Country.cpp
* Implementation of all functions of Country class.
* @author Klishchov Bohdan
* @version 1.0
* @date 2019.09.06
*/

#include "Country.h"

#include"Country.h"
Country::Country() :population(0), area(0), revenue(0), name() {
};
Country::Country(int a, int b, int c, std::string Name) :population(a), area(b), revenue(c) {
	name = Name;
};
Country::Country(const Country &obj) :population(obj.population), area(obj.area), revenue(obj.revenue), name(obj.name) {};

std::string Country::getName() {
	return this->name;
}
int Country::getArea() {
	return this->area;
}
int Country::getPopulation() {
	return this->population;
}
int Country::getRevenue() {
	return this->revenue;
}
void Country::setRand(std::string name) {
	this->area = rand() % 654365 + 65436;
	this->population = rand() % 654236 + 85676;
	this->revenue = rand() % 45678 + 34567;
	this->name = name;
}

void Country::setData(string name, int area, int population, int revenue) {
	this->name = name;
	this->population = population;
	this->area = area;
	this->revenue = revenue;
}
