#include "InfoIndependentsWork.h"

InfoIndependentsWork::InfoIndependentsWork() : mark(0) {
}
InfoIndependentsWork::InfoIndependentsWork(const InfoIndependentsWork &obj) : mark(obj.mark) {
}
InfoIndependentsWork::InfoIndependentsWork(int mark) : mark(mark) {
}
InfoIndependentsWork::~InfoIndependentsWork() {
}
std::ostream& operator<< (std::ostream &out, const InfoIndependentsWork &obj) {
	out << obj.mark << std::endl;
	return out;
}
std::istream& operator>> (std::istream &in, InfoIndependentsWork &obj) {
	in >> obj.mark;
	return in;
}
InfoIndependentsWork& InfoIndependentsWork::operator= (const InfoIndependentsWork &obj) {
	mark = obj.mark;
	return *this;
}
bool InfoIndependentsWork::operator< (const InfoIndependentsWork obj) {
	return (mark < obj.mark);
}
bool InfoIndependentsWork::operator== (const InfoIndependentsWork obj) {
	return (mark == obj.mark);
}
int InfoIndependentsWork::get_mark() {
	return this->mark;
}
void InfoIndependentsWork::generation_values() {
	mark = 1 + rand() % 5;
}
void InfoIndependentsWork::set_data(int mark) {
	this->mark = mark;
}
