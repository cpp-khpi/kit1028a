#include "Homework.h"

Homework::Homework(int amount, int written, int mark, std::string person, int homework_count) : homework_count(homework_count), InfoIndependentsWork() {
}

Homework::Homework() : homework_count(0) {
}

Homework::Homework(const Homework &obj) : homework_count(obj.homework_count), InfoIndependentsWork(obj.amount, obj.written, obj.mark, obj.person) {
}
Homework::~Homework() {
}

int Homework::get_homework() {
	return Homework::homework_count;
}
void Homework::generation_values(std::string s) {
	homework_count = rand() % 16;
	amount = 8 + rand() % 8;
	written = amount - rand() % 8;
	mark = 1 + rand() % 5;
	person = s;
}
void Homework::set_data(int homework_count, int amount, int written, int mark, std::string person) {
	this->homework_count = homework_count;
	this->person = person;
	this->amount = amount;
	this->written = written;
	this->mark = mark;
}