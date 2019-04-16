#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>

class InfoIndependentsWork {
private:
	int amount;
	int written;
	int mark;
	std::string surname;
public:
	InfoIndependentsWork();
	InfoIndependentsWork(const InfoIndependentsWork &obj);
	InfoIndependentsWork(int amount, int written, int mark, std::string surname);
	int getAmount();
	int getWritten();
	int getMark();
	std::string getSurname();
	void generation_values(std::string s);
	void setData(int amount, int written, int mark, std::string surname);
	~InfoIndependentsWork() {
	}
};
