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
	TestsInfo(int num);
	TestsInfo(const TestsInfo &o);

	void setSurname(char * surname);
	void setInfo(int num);
	string getInfo()const;

	int getWorks()const;
	int idInfo()const;
};