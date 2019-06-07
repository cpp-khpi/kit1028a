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

	void getNewTextbook();
	int getSize();

	void removeTextbook(const int num);
	void addTextbook(Textbook &);

	void getRequiredTextbook(const int num)const;
	void printAll()const;
};