#include "IndependentsWork.h"

IndependentsWork::IndependentsWork() :amount(0), written(0), mark(0) {
}
IndependentsWork::IndependentsWork(const IndependentsWork &obj) : amount(obj.amount), written(obj.written), mark(obj.mark) {
}
IndependentsWork::IndependentsWork(int amount, int written, int mark, std::string person) : amount(amount), written(written), mark(mark), person(person) {
}
IndependentsWork::~IndependentsWork() {
}
std::ostream& operator<< (std::ostream &out, const IndependentsWork &obj) {
	out << obj.person << ": " << obj.amount << std::endl;
	out << obj.person << ": " << obj.written << std::endl;
	out << obj.person << ": " << obj.mark << std::endl;
	return out;
}
std::istream& operator>> (std::istream &in, IndependentsWork &obj) {
	in >> obj.amount;
	in >> obj.written;
	in >> obj.mark;
	in >> obj.person;
	return in;
}
IndependentsWork& IndependentsWork::operator= (const IndependentsWork &obj) {
	amount = obj.amount;
	written = obj.written;
	mark = obj.mark;
	return *this;
}
int IndependentsWork::get_amount() {
	return IndependentsWork::amount;
}
int IndependentsWork::get_written() {
	return IndependentsWork::written;
}
int IndependentsWork::get_mark() {
	return IndependentsWork::mark;
}
std::string IndependentsWork::get_person() {
	return IndependentsWork::person;
}
void IndependentsWork::generation_values(std::string s) {
	this->amount = 8 + rand() % 8;
	this->written = amount - rand() % 8;
	this->mark = 1 + rand() % 5;
	this->person = s;
}
void IndependentsWork::set_data(int amount, int written, int mark, std::string person) {
	this->person = person;
	this->amount = amount;
	this->written = written;
	this->mark = mark;
}
