#pragma once
#include <iostream>
#include <ctime>
#include <string>

class Country {
private:
	int population;
	int area;
	int revenue;
	char *fakeName;
	std::string name;
public:
	Country();
	Country(int a, int b, int c, std::string Name);
	Country(const Country &obj);
	int getPopulation();
	int getArea();
	int getRevenue();
	std::string getName();
	void setInfo(std::string s);
	void setData(int population, int area, int revenue, std::string name);
	~Country() {
	}
};
