#include "Country.h"

Country::Country() : popul(0), size(0) {
}
Country::Country(const Country &obj) : popul(obj.popul), size(obj.size) {
}
Country::Country(int popul, int size) : popul(popul), size(size) {
}
Country::~Country() {
}
std::ostream& operator<< (std::ostream &out, const Country &obj) {
	out << obj.popul << std::endl;
	return out;
}
std::istream& operator>> (std::istream &in, Country &obj) {
	in >> obj.popul;
	return in;
}
Country& Country::operator= (const Country &obj) {
	popul = obj.popul;
	return *this;
}
bool Country::operator< (const Country obj) {
	return (popul < obj.popul && size < obj.size);
}
bool Country::operator== (const Country obj) {
	return (popul == obj.popul);
}
int Country::get_popul() {
	return this->popul;
}
int Country::get_size() {
	return this->size;
}
void Country::generation_values() {
	size = rand() % 5;
	popul = 1 + rand() % 5;
}
void Country::set_data(int popul, int size) {
	this->size = size;
	this->popul = popul;
}