#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>
#include <regex>

class InfoIndependentsWork {
protected:
	int amount;
	int written;
	int mark;
	std::string person;
public:
	InfoIndependentsWork();
	InfoIndependentsWork(const InfoIndependentsWork &obj);
	InfoIndependentsWork(int amount, int written, int mark, std::string person);
	int get_amount();
	int get_written();
	int get_mark();
	std::string get_person();
	void generation_values(std::string s);
	void set_data(int amount, int written, int mark, std::string person);
	~InfoIndependentsWork() {
	}
};