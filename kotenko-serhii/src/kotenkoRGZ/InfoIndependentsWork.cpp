#include "InfoIndependentsWork.h"

InfoIndependentsWork::InfoIndependentsWork() :amount(0), written(0), mark(0) {
}
InfoIndependentsWork::InfoIndependentsWork(const InfoIndependentsWork &obj) : amount(obj.amount), written(obj.written), mark(obj.mark) {
}
InfoIndependentsWork::InfoIndependentsWork(int amount, int written, int mark, std::string person) : amount(amount), written(written), mark(mark), person(person) {
}
std::ostream& operator<< (std::ostream &out, const InfoIndependentsWork &obj) {
	out << obj.person << ": " << obj.amount << std::endl;
	out << obj.person << ": " << obj.written << std::endl;
	out << obj.person << ": " << obj.mark << std::endl;
	return out;
}
std::ostream& operator<< (std::ostream &out, const InfoIndependentsWork *obj) {
	out << obj->person << ": " << obj->amount << std::endl;
	out << obj->person << ": " << obj->written << std::endl;
	out << obj->person << ": " << obj->mark << std::endl;
	return out;
}
std::istream& operator>> (std::istream &in, InfoIndependentsWork &obj) {
	in >> obj.amount;
	in >> obj.written;
	in >> obj.mark;
	in >> obj.person;
	return in;
}
std::istream& operator>> (std::istream &in, InfoIndependentsWork *obj) {
	in >> obj->amount;
	in >> obj->written;
	in >> obj->mark;
	in >> obj->person;
	return in;
}
InfoIndependentsWork& InfoIndependentsWork::operator= (const InfoIndependentsWork &obj) {
	amount = obj.amount;
	written = obj.written;
	mark = obj.mark;
	return *this;
}
InfoIndependentsWork::~InfoIndependentsWork() {
};
int InfoIndependentsWork::get_amount() {
	return InfoIndependentsWork::amount;
}
int InfoIndependentsWork::get_written() {
	return InfoIndependentsWork::written;
}
int InfoIndependentsWork::get_mark() {
	return InfoIndependentsWork::mark;
}
std::string InfoIndependentsWork::get_person() {
	return InfoIndependentsWork::person;
}
void InfoIndependentsWork::generation_values(std::string s) {
	this->amount = 8 + rand() % 8;
	this->written = amount - rand() % 8;
	this->mark = 1 + rand() % 5;
	this->person = s;
}
void InfoIndependentsWork::set_data(int amount, int written, int mark, std::string person) {
	this->person = person;
	this->amount = amount;
	this->written = written;
	this->mark = mark;
}
