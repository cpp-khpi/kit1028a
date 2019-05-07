#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <cstddef>

#define _CRTDBG_MAP_ALLOC

class Country {
private:
	int population;
	int area;
	int revenue;
	std::string name;
public:
	Country();
	Country(int a, int b, int c, std::string Name);
	Country(const Country &obj);
	int getPopulation();
	int getArea();
	int getRevenue();
	std::string getName();
	void getInfo(std::string s);
	void setData(int population, int area, int revenue, std::string name);
	~Country() {
	}
};
