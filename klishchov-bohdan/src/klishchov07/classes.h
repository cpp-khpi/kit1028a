#pragma once
#include "Country.h"

class Island : public Country {
public:
	void Info() override {
		cout << "This country is washed by the ocean." << endl;
	}
};

class Mainland : public Country {
public:
	void Info() override {
		cout << "This country is on the mainland" << endl;
	}
};

class Information {
public:
	void Info(Country *country)
	{
		country->Info();
	}
};