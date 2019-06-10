#include "Textbook.h"

Textbook::Textbook() : pages(0) {
}

Textbook::Textbook(const Textbook &obj) : pages(obj.pages) {
}

Textbook::Textbook(int mark) : pages(pages) {
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
	return (pages < obj.pages);
}

bool Textbook::operator== (const Textbook obj) {
	return (pages == obj.pages);
}

int Textbook::getPages() {
	return this->pages;
}

void Textbook::setInfo(int pages) {
	pages = rand () % 100 + 180;
}

void Textbook::getInfo() {
	this->pages = pages;
}
