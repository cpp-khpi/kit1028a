#include "InfoWork.h"


InfoWork::InfoWork() :pages(0), mark(0), type(0), name() {
	name = new char[256];
};
InfoWork::InfoWork(int a, int b, int c, char* creator) :pages(a), mark(b), type(c){
	name = new char[256];
	strcpy_s(name, 256, creator);
};
InfoWork::InfoWork(const InfoWork &obj) :pages(obj.pages), mark(obj.mark), type(obj.type), name(obj.name) {};
InfoWork::~InfoWork() {
	delete[] name;
}
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