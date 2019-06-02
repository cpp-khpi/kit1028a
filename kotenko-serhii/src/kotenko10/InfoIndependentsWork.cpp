#include "InfoIndependentsWork.h"

InfoIndependentsWork::InfoIndependentsWork() : mark(0), size(0) {
}
InfoIndependentsWork::InfoIndependentsWork(const InfoIndependentsWork &obj) : mark(obj.mark), size(obj.size) {
}
InfoIndependentsWork::InfoIndependentsWork(int mark,int size) : mark(mark), size(size) {
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
	return (mark < obj.mark && size < obj.size);
}
bool InfoIndependentsWork::operator== (const InfoIndependentsWork obj) {
	return (mark == obj.mark);
}
int InfoIndependentsWork::get_mark() {
	return this->mark;
}
int InfoIndependentsWork::get_size() {
	return this->size;
}
void InfoIndependentsWork::generation_values() {
	size = rand() % 5;
	mark = 1 + rand() % 5;
}
void InfoIndependentsWork::set_data(int mark, int size) {
	this->size = size;
	this->mark = mark;
}
