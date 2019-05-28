#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>
#include <regex>

class InfoIndependentsWork {
protected:
	int amount;
	int written;
	int mark;
	std::string person;
public:
	InfoIndependentsWork& operator= (const InfoIndependentsWork &obj) {
		amount = obj.amount;
		written = obj.written;
		mark = obj.mark;
		return *this;
	}
	friend std::ostream& operator<< (std::ostream &out, const InfoIndependentsWork &obj) {
		out << obj.person << ": " << obj.mark << std::endl;
		return out;
	}
	friend std::istream& operator>> (std::istream &in, InfoIndependentsWork &obj) {
		in >> obj.amount;
		in >> obj.written;
		in >> obj.mark;
		in >> obj.person;

		return in;
	}
	bool operator< (const InfoIndependentsWork obj) {
		return (amount < obj.amount && written < obj.written && mark < obj.mark);
	}
	bool operator> (const InfoIndependentsWork obj) {
		return (amount > obj.amount && written > obj.written && mark > obj.mark);
	}
	InfoIndependentsWork();
	InfoIndependentsWork(const InfoIndependentsWork &obj);
	InfoIndependentsWork(int amount, int written, int mark, std::string person);
	int get_amount();
	int get_written();
	int get_mark();
	std::string get_person();
	void generation_values(std::string s);
	void set_data(int amount, int written, int mark, std::string person);
	~InfoIndependentsWork() {
	}
};