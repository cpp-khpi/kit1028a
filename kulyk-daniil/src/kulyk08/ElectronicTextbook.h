#pragma once
#include "Textbook.h"

class ElectronicTextbook : public Textbook {
private:
	int amount_of_charge;
public:
	friend std::ostream& operator<< (std::ostream &out, const ElectronicTextbook &obj);
	friend std::istream& operator>> (std::istream &in, ElectronicTextbook &obj);
	bool operator< (const ElectronicTextbook obj);
	bool operator> (const ElectronicTextbook obj);

	ElectronicTextbook();
	ElectronicTextbook(int num, int pages, int grade, int cost, int year_of_release, string author, int amount_of_charge);
	ElectronicTextbook(const ElectronicTextbook &obj);
	~ElectronicTextbook();

	int getAmountOfCharge();
	void getInfo(string s);
	void setInfo(int amount_of_charge, int num, int pages, int grade, int cost, int year_of_release, string author);
};

