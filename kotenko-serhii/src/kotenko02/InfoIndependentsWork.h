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
	InfoIndependentsWork() : amount(0), written(0), mark(0) {
		surname = (char *) operator new (sizeof(char) * 256);
	};
	int getAmount();
	int getWritten();
	int getMark();
	char *getSurname();
	void generation_values(char *s);
	void setData(int amount, int written, int mark, char *surname);
	~InfoIndependentsWork() {
		delete[] surname;
	}
};