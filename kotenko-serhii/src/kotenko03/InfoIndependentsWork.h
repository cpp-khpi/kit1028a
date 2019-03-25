#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

class InfoIndependentsWork {
private:
	int amount;
	int written;
	int mark;
	std::string surname;
public:
	InfoIndependentsWork() : amount(0), written(0), mark(0) {
	}
	InfoIndependentsWork(const InfoIndependentsWork &Info) : amount(Info.amount), written(Info.written), mark(Info.mark){
	}
	int getAmount();
	int getWritten();
	int getMark();
	std::string getSurname();
	void generation_values(std::string s);
	void setData(int amount, int written, int mark, std::string surname);
	~InfoIndependentsWork() {
	}
};
