#pragma once
#include "Homework.h"

class DoHomework {
private:
	int size;
	Homework *arr;
public:
	void set_size(int size);
	void new_array(std::string *s);
	void print();
	void add_elem(int amount, int written, int mark, int homework_count, std::string person);
	void delete_elem(int l);
	void get_by_index(int index);
	void delete_array();
	void read_from_file(std::string *person);
	void write_to_file();
	void search_by_surname(std::string search_person);
	void sort_by_mark(bool(*sort)(int a, int b));
	void sort_by_amount(bool(*sort)(int a, int b));
	void sort_by_written(bool(*sort)(int a, int b));
	void sort_by_homework(bool(*sort)(int a, int b));
};