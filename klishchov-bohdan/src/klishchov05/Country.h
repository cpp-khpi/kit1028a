#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>
#include <regex>

#define _CRTDBG_MAP_ALLOC

class Army {
public:
	std::string getSection() {
		return section;
	}
private:
	std::string	section = "air force";
};

class Country {
private:
	int population;
	int area;
	int revenue;
	std::string name;
	//-------------------------------------------------------------------
	//----------------------Композиция-----------------------------------
	class Population {
	public:
		void Human() {
			std::cout << "I live in a beautiful town :)" << std::endl;
		}
	};
	Population popul;
	//-------------------------------------------------------------------
	//--------------------------Агрегация--------------------------------
	Army army;
	//-------------------------------------------------------------------
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

	void Human();
	void Speaking();

	~Country() {
	}
};
