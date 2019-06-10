#include "Textbook.h"

Textbook::Textbook() : size(0), pages(0) {
}

Textbook::Textbook(const Textbook &obj) : size(obj.size), pages(obj.pages) {
}

Textbook::Textbook(int size, int pages) : size(size), pages(pages) {
}

Textbook::~Textbook() {
}

ostream& operator<< (ostream &out, const Textbook &obj) {
	out << obj.pages << endl;
	return out;
}

istream& operator>> (istream &in, Textbook &obj) {
	in >> obj.pages;
	return in;
}

Textbook& Textbook::operator= (const Textbook &obj) {
	pages = obj.pages;
	return *this;
}

bool Textbook::operator< (const Textbook obj) {
	return (size < obj.size && pages < obj.pages);
}

bool Textbook::operator== (const Textbook obj) {
	return (pages == obj.pages);
}

int Textbook::getPages() {
	return this->pages;
}

int Textbook::getSize() {
	return this->size;
}

void Textbook::setInfo() {
	size = rand() % 5 + 1;
	pages = rand() % 100 + 180;
}

void Textbook::getInfo(int size, int pages) {
	this->size = size;
	this->pages = pages;
}