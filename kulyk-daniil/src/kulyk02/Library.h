#pragma once
#include "Textbook.h"

class Library {
private:
	int size;
	char *surname;
	Textbook new_textbook;
	Textbook *backlist;

public:
	Library(int size);
	~Library();

	void getNewTextbook();
	int getSize();
	void getSurname(char** surname);

	void removeTextbook(const int num);
	void addTextbook(int num, int pages, int grade, int cost, int year_of_release, char* author);

	void getRequiredTextbook(const int num)const;
	void printAll()const;
	float averageAmountOfPages(int pages);
};
