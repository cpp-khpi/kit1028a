#pragma once
#include "InfoIndependentsWork.h"

class IndependentsWork {
private:
	int size;
	InfoIndependentsWork *arr;
public:
	friend std::ostream& operator<< (std::ostream &out, const IndependentsWork &obj);
	friend std::istream& operator>> (std::istream &in, IndependentsWork &obj);
	InfoIndependentsWork &operator[] (const int index);
	void set_size(int size);
	void new_array(std::string *s);
	void print();
	void add_elem(int amount, int written, int mark, std::string person);
	void delete_elem(int l);
	void get_by_index(int index);
	void delete_array();
	void read_from_file(std::string *person);
	void write_to_file();
	void search_by_surname(std::string search_person);
	void sort_by_mark(bool(*sort)(int a, int b));
	void sort_by_amount(bool(*sort)(int a, int b));
	void sort_by_written(bool(*sort)(int a, int b));
};