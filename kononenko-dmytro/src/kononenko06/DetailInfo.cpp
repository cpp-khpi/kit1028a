#include "DetailInfo.h"



DetailInfo::DetailInfo(): sizeOfLabor(0),novelty(0),InfoWork()
{
}

void DetailInfo::set(string x) {
	sizeOfLabor = rand() % 300;
	novelty = rand() % 30 + 1990;
	mark = rand() % 5 + 1;
	pages = rand() % 336 + 100;
	type = rand() % 2 + 1;
	name = x;
}

void DetailInfo::set_n(int a, int b, int c, string d, int e, int f){
	InfoWork::set_n(a, b, c, d);
	sizeOfLabor = f;
	novelty = e;
}

void DetailInfo::setNovelty(int x) {
	novelty = x;
}

void DetailInfo::setSizeLabor(int x) {
	sizeOfLabor = x;
}

DetailInfo::~DetailInfo()
{
}

int DetailInfo::getMark() {
	return this->mark;
}
int DetailInfo::getPages() {
	return this->pages;
}
int DetailInfo::getType() {
	return this->type;
}
string DetailInfo::getName() {
	return this->name;
}

int DetailInfo::getNovelty() {
	return this->novelty;
}

int DetailInfo::getSizeLabor() {
	return this->sizeOfLabor;
}