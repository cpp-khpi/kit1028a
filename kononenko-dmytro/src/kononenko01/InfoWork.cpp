#include "InfoWork.h"

void InfoWork::set(char *creator) {
	mark = rand() % 5 + 1;
	pages = rand() % 336 + 100;
	type = rand() % 2 + 1;
	strcpy_s(name, 256, creator);
}
void InfoWork::set_n(int mark, int pages, int type, char *creator) {
	this->mark = mark;
	this->pages = pages;
	this->type = type;
	strcpy_s(this->name, 256, creator);
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
char* InfoWork::getName() {
	return this->name;
}