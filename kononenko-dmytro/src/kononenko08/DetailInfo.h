#pragma once
#include "InfoWork.h"

class DetailInfo : InfoWork
{
private:
	int novelty;
	int sizeOfLabor;
public:
	bool operator== (const DetailInfo obj) {
		return (pages == obj.pages && type == obj.type && mark == obj.mark && name == obj.name);
	}
	bool operator!= (const DetailInfo obj) {
		return (pages != obj.pages && type != obj.type && mark != obj.mark && name != obj.name);
	}
	friend std::ostream& operator<< (std::ostream &out, const DetailInfo &obj) {
		out << obj.name << ";" << obj.mark << endl;
		return out;
	}
	friend std::istream& operator>> (std::istream &in, DetailInfo &obj) {
		in >> obj.pages;
		in >> obj.mark;
		in >> obj.type;
		in >> obj.name;
		in >> obj.novelty;
		in >> obj.sizeOfLabor;

		return in;
	}
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

