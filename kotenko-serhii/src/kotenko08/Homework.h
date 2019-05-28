#pragma once
#include "InfoIndependentsWork.h"

class Homework : public InfoIndependentsWork {
private:
	int homework_count;
public:
	friend std::ostream& operator<< (std::ostream &out, const Homework &obj) {
		out << obj.person << ": " << obj.homework_count << std::endl;
		return out;
	}
	friend std::istream& operator>> (std::istream &in, Homework &obj) {
		in >> obj.amount;
		in >> obj.written;
		in >> obj.mark;
		in >> obj.homework_count;
        in >> obj.person;
		return in;
	}
	bool operator< (const Homework obj) {
		return (amount < obj.amount && written < obj.written && mark < obj.mark && homework_count < obj.homework_count);
	}
	bool operator> (const Homework obj) {
		return (amount > obj.amount && written > obj.written && mark > obj.mark && homework_count > obj.homework_count);
	}
	Homework();
	Homework(int amount, int written, int mark, std::string person, int homework_count);
	Homework(const Homework &obj);

	int get_homework();
	void generation_values(std::string s);
	void set_data(int homework_count, int amount, int written, int mark, std::string person);

	~Homework();
};

