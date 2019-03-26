#pragma once
#include <iostream>

using namespace std;

class TestsInfo {
private:
	int num;
	int works, pages, mark;
public:
	void setInfo(int num,int works,int pages);
	int getNum()const;
	int getWorks()const;
	int getPages()const;
	int getMark()const;

	void printInfo()const;
};