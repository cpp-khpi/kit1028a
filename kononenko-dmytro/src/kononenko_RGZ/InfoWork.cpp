/**
* @file InfoWork.cpp
* Implementation of all functions of InfoWork class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/

#include "InfoWork.h"

InfoWork::InfoWork() :pages(0), mark(0), type(0), name() {};
InfoWork::InfoWork(int pgs, int points, int kind, string creator) :pages(pgs), mark(points), type(kind), name(creator) {};
InfoWork::InfoWork(const InfoWork &obj) :pages(obj.pages), mark(obj.mark), type(obj.type), name(obj.name) {};
InfoWork::~InfoWork() {};
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

bool InfoWork::operator== (const InfoWork &obj) {
	return (pages == obj.pages && type == obj.type && mark == obj.mark && name == obj.name);
}

bool InfoWork::operator!= (const InfoWork &obj) {
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
	out <<"Name: " <<obj.name << " Mark: " << obj.mark <<endl;
	out << "Size: " << obj.pages;
	if (obj.type == 1) {
		out << " BACALAVR";
	}
	else {
		out << " MAGISTR";
	}
	return out;
}

InfoWork& InfoWork::operator= (const InfoWork &obj) {
	pages = obj.pages;
	mark = obj.mark;
	type = obj.type;
	name = obj.name;
	return *this;
}