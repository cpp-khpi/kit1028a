#include "InfoWork.h"

InfoWork::InfoWork() :pages(0), mark(0), type(0), name() {};
InfoWork::InfoWork(int a, int b, int c, string creator) :pages(a), mark(b), type(c), name(creator) {};
InfoWork::InfoWork(const InfoWork &obj) :pages(obj.pages), mark(obj.mark), type(obj.type), name(obj.name) {};

void InfoWork::set(string creator) {
	mark = rand() % 5 + 1;
	pages = rand() % 336 + 100;
	type = rand() % 2 + 1;
	name = creator;
}
void InfoWork::set_n(int mark, int pages, int type, string creator) {
	this->mark = mark;
	this->pages = pages;
	this->type = type;
	this->name = creator;
}
InfoWork InfoWork::get_element(){
	InfoWork obj;
	obj.name = name;
	obj.mark = mark;
	obj.pages = pages;
	obj.type = type;
	return obj;
}
int InfoWork::getMark() {
	return this->mark;
}
int InfoWork::getPages() {
	return this->pages;
}
int InfoWork::getType() {
	return this->type;
}
string InfoWork::getName() {
	return this->name;
}

bool InfoWork::operator== (const InfoWork obj) {
	return (pages == obj.pages && type == obj.type && mark == obj.mark && name == obj.name);
}

bool InfoWork::operator!= (const InfoWork obj) {
	return (pages != obj.pages && type != obj.type && mark != obj.mark && name != obj.name);
}

std::istream& operator>> (std::istream &in, InfoWork &obj) {
	in >> obj.pages;
	in >> obj.mark;
	in >> obj.type;
	in >> obj.name;

	return in;
}

std::ostream& operator<< (std::ostream &out, const InfoWork &obj) {
	out << obj.name << ": " << obj.mark << endl;
	return out;
}

InfoWork& InfoWork::operator= (const InfoWork obj) {
	pages = obj.pages;
	mark = obj.mark;
	type = obj.type;
	name = obj.name;
	return *this;
}
