#pragma once

#include "InfoIndependentsWork.h"

class IndependentsWork {
private:
	int size;
	InfoIndependentsWork **arr;
public:
	/**
	* IndependentsWork class constructors.
	*/
	IndependentsWork();
	/**
	* Overloading of the output operator.
	*/
	friend std::ostream& operator<< (std::ostream &out, const IndependentsWork &obj);
	/**
	* Overloading of the input operator.
	*/
	friend std::istream& operator>> (std::istream &in, IndependentsWork &obj);

	void set_size(int size);
	void print();
	void add_elem(InfoIndependentsWork* new_work);
	void delete_elem(int l);
	void get_by_index(int index);
	void read_from_file(int new_size);
	void write_to_file();
	void search_by_surname(std::string search_person);
	void sort_by_mark(bool(*sort)(int a, int b));
	void sort_by_amount(bool(*sort)(int a, int b));
	void sort_by_written(bool(*sort)(int a, int b));
	/**
	* InfoIndependentsWork class destructor.
	*/
	~IndependentsWork();
};