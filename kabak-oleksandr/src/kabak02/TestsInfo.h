#pragma once
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
using namespace std;

class TestsInfo {
private:
	int num;
	int works, pages, mark;
	char surname[20];
public:
	TestsInfo();
	TestsInfo(int num, int works, int pages,char* surname);
	TestsInfo(const TestsInfo &o);
	~TestsInfo() {};

	void setInfo(int num, int works, int pages, char* surname);
	int getNum()const;
	int getWorks()const;
	int getPages()const;
	int getMark()const;
	char* getSurname()const;

	void printInfo()const;
};