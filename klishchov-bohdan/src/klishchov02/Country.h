#pragma once
#include <iostream>
#include <ctime>

class Country {
private:
	int population;
	int area;
	int revenue;
	char *name;
public:
	Country();
	Country(int a, int b, int c, char* Name);
	Country(const Country &obj);
	Country &operator=(const Country &obj) {
		this->population = obj.population;
		this->area = obj.area;
		this->revenue = obj.revenue;
		strcpy_s(name, 24, obj.name);
		return *this;
	}

	int getPopulation();
	int getArea();
	int getRevenue();
	char *getName();
	void setInfo(char *s);
	void setData(int population, int area, int revenue, char *name);
	~Country() {

	}
};
