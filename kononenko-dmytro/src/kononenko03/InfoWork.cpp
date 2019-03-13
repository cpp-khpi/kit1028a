#include "InfoWork.h"

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