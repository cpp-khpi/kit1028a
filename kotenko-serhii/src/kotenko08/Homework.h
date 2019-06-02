#pragma once
#include "InfoIndependentsWork.h"

class Homework : public InfoIndependentsWork {
private:
	int homework_count;
public:
	friend std::ostream& operator<< (std::ostream &out, const Homework &obj);
	friend std::istream& operator>> (std::istream &in, Homework &obj);
	bool operator< (const Homework obj);
	bool operator> (const Homework obj);
	Homework();
	Homework(int amount, int written, int mark, std::string person, int homework_count);
	Homework(const Homework &obj);

	int get_homework();
	void generation_values(std::string s);
	void set_data(int homework_count, int amount, int written, int mark, std::string person);

	~Homework();
};

