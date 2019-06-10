/**
* @file Country.h
* Declaration of Country class.
* @author Klishchov Bohdan
* @version 1.0
* @date 2019.09.06
*/

#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>
#include <regex>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::endl;

class Country {
private:
	string name; // Строкове поле країни (Назва країни)
	int area; // Числове поле країни (Площа країни)
	int population; // Числове поле країни (Населення країни)
	int revenue; // Числове поле країни (Населення країни)
public:
	/**
	* Constructor without arguments.
	*/
	Country();
	/**
	* Constructor with arguments.
	*/
	Country(int a, int b, int c, std::string Name);
	/**
	* Counstructor kakashi.
	*/
	Country(const Country &obj);

	/**
	* Function getter for name.
	*/
	string getName();

	/**
	* Function getter for area.
	*/
	int getArea();
	/**
	* Function getter for population.
	*/
	int getPopulation();
	/**
	* Function getter for revenue.
	*/
	int getRevenue();
	/**
	* Function for random generation information.
	*/
	void setRand(std::string name);
	/**
	* Function setter.
	* \param string name, int area, population, revenue.
	*/
	void setData(string name, int area, int population, int revenue);

	/**
	* Abstract function.
	*/
	virtual void Info() = 0;
};
