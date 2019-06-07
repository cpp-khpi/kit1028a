#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

class Textbook {
private:
	int num;
	int pages;
	int grade;
	int cost;
	int year_of_release;
public:
	Textbook();
	Textbook(int num, int pages, int grade, int cost, int year_of_release);
	Textbook(const Textbook &obj);
	~Textbook() {};

	void setNum(int num);
	void setPages(int pages);
	void setGrade(int grade);
	void setCost(int cost); 
	void setYearOfRelease(int year_of_release);

	int getNum()const;
	int getPages()const;
	int getGrade()const;
	int getCost()const;
	int getYearOfRelease()const;

	void printInfo()const;
};
