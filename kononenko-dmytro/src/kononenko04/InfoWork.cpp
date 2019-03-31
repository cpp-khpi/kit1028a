#include "InfoWork.h"

InfoWork::InfoWork() :pages(0), mark(0), type(0), name() {};
InfoWork::InfoWork(int a, int b, int c, string creator) :pages(a), mark(b), type(c), name(creator) {};
InfoWork::InfoWork(const InfoWork &obj) :pages(obj.pages), mark(obj.mark), type(obj.type), name(obj.name), person(obj.person) {};

void InfoWork::set(string creator) {
	mark = rand() % 5 + 1;
	pages = rand() % 336 + 100;
	type = rand() % 2 + 1;
	name = creator;
}
void InfoWork::set_n(int mark, int pages, int type, string creator, string tchName) {
	this->mark = mark;
	this->pages = pages;
	this->type = type;
	this->name = creator;
	this->person.setName(tchName);
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

string InfoWork::getTch() {
	return person.getName();
}