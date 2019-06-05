#pragma once
#include "InfoWork.h"

class DetailInfo : InfoWork
{
private:
	int novelty;
	int sizeOfLabor;
public:
	bool operator== (const DetailInfo obj) {}
	bool operator!= (const DetailInfo obj) {}
	friend std::ostream& operator<< (std::ostream &out, const DetailInfo &obj) {}
	friend std::istream& operator>> (std::istream &in, DetailInfo &obj) {}
	int getPages() ;
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

