#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>
#include <regex>

using std::string;
using std::cin;
using std::cout;
using std::endl;



class Country {
private:
	int population;
	int area;
	int revenue;
	string name;
public:
	Country& operator= (const Country &obj);
	friend std::ostream& operator<< (std::ostream &out, const Country &obj);
	friend std::istream& operator>> (std::istream &in, Country &obj);
	Country();
	int getPopulation();
	int getArea();
	int getRevenue();
	string getName();
	void getInfo(std::string s);
	void setData(int population, int area, int revenue, string name);
	virtual void Info() = 0;
	~Country();
};
