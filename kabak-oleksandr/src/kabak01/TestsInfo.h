#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

class TestsInfo {
private:
	int num;
	int works, pages, mark;
public:
	
	void setInfo(int num);
	void getInfo()const;

	int idInfo()const;
};