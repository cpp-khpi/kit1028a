#pragma once
#include <iostream>
#include <ctime>

class InfoIndependentsWork {
private:
	int amount;
	int written;
	int mark;
	char *surname;
public:
	InfoIndependentsWork();
	int getAmount();
	int getWritten();
	int getMark();
	char *getSurname();
	void setInfo(char *s);
	void setData(int amount, int written, int mark, char *surname);
	~InfoIndependentsWork() {
	}
};