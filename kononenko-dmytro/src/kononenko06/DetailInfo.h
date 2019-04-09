#pragma once
#include "InfoWork.h"

class DetailInfo : InfoWork
{
private:
	int novelty;
	int sizeOfLabor;
public:
	int getPages();
	int getMark();
	int getType();
	string getName();
	int getSizeLabor();
	int getNovelty();
	void setNovelty(int x);
	void setSizeLabor(int x);
	void set_n(int a, int b, int c, string d, int e,int f);
	void set(string x);
	DetailInfo();
	~DetailInfo();
};

