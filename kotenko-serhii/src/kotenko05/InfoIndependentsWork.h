#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>
#include <regex>
#include "IndependentTesting.h"

class InfoIndependentsWork {
private:
	int amount;
	int written;
	int mark;
	std::string person;
	IndependentTesting ZNO;
public:
	InfoIndependentsWork();
	InfoIndependentsWork(const InfoIndependentsWork &obj);
	InfoIndependentsWork(int amount, int written, int mark, std::string person);
	int getAmount();
	int getWritten();
	int getMark();
	std::string getPerson();
	void generation_values(std::string s);
	void setData(int amount, int written, int mark, std::string person);
	~InfoIndependentsWork() {
	}
};