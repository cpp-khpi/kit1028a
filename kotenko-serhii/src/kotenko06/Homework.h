#pragma once
#include "InfoIndependentsWork.h"

class Homework : public InfoIndependentsWork {
private:
	int homework_count;
public:
	Homework();
	Homework(int amount, int written, int mark, std::string person, int homework_count);
	Homework(const Homework &obj);

	int get_homework();
	void generation_values(std::string s);
	void set_data(int homework_count,int amount, int written, int mark, std::string person);

	~Homework();
};

