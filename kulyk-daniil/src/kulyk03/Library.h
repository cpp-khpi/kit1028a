#pragma once
#include "Textbook.h"

class Library {
private:
	int size;
	Textbook new_textbook;
	Textbook *backlist;

public:
	Library(int size);
	~Library();

	void setNewTextbook();
	int getSize();
	float averageAmountOfPages(int num);

	void removeTextbook(const int num);
	void addTextbook(const int num);

	void getRequiredTextbook(const int num)const;
	void getNewTextbook();
	void printAll()const;
};
