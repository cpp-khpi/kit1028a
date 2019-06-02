#include "Homework.h"

Homework::Homework(int amount, int written, int mark, std::string person, int homework_count) : homework_count(homework_count), InfoIndependentsWork() {
}
Homework::Homework() : homework_count(0) {
}
Homework::Homework(const Homework &obj) : homework_count(obj.homework_count), InfoIndependentsWork(obj.amount, obj.written, obj.mark, obj.person) {
}
Homework::~Homework() {
}
std::ostream& operator<< (std::ostream &out, const Homework &obj) {
	out << obj.person << ": " << obj.homework_count << std::endl;
	return out;
}
std::istream& operator>> (std::istream &in, Homework &obj) {
	in >> obj.amount;
	in >> obj.written;
	in >> obj.mark;
	in >> obj.homework_count;
	in >> obj.person;
	return in;
}
bool Homework::operator< (const Homework obj) {
	return (amount < obj.amount && written < obj.written && mark < obj.mark && homework_count < obj.homework_count);
}
bool Homework::operator> (const Homework obj) {
	return (amount > obj.amount && written > obj.written && mark > obj.mark && homework_count > obj.homework_count);
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