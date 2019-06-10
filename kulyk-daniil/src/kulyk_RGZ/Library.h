#pragma once

#include "Textbook.h"

class Library {
private:
	int size;
	Textbook **arr;
public:
	/**
	* Library class constructors.
	*/
	Library();
	/**
	* Library class destructor.
	*/
	~Library();
	/**
	* Overloading of the output operator.
	*/
	friend ostream& operator<< (ostream &out, const Library &obj);
	/**
	* Overloading of the input operator.
	*/
	friend istream& operator>> (istream &in, Library &obj);

	void setSize(int size);
	void printAll();
	void addTextbook(Textbook* new_textbook);
	void deleteTextbook(int ind);
	void getByIndex(int index);
	void readFromFile(int new_size);
	void writeToFile();
	void searchBySurname(string search_surname);
	void sortByPages(bool(*sort)(int a, int b));
	void sortByGrade(bool(*sort)(int a, int b));
	void sortByCost(bool(*sort)(int a, int b));
};
