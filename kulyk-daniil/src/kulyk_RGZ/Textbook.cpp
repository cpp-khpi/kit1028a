#include "Textbook.h"

Textbook::Textbook() :pages(0), grade(0), cost(0) {
}
Textbook::Textbook(const Textbook &obj) : pages(obj.pages),grade(obj.grade), cost(obj.cost) {
}
Textbook::Textbook(int pages, int grade, int cost, string author) : pages(pages), grade(grade), cost(cost), author(author) {
}
ostream& operator<< (ostream &out, const Textbook &obj) {
	out << obj.author << ": " << obj.pages << endl;
	out << obj.author << ": " << obj.grade << endl;
	out << obj.author << ": " << obj.cost << endl;
	return out;
}
ostream& operator<< (ostream &out, const Textbook *obj) {
	out << obj->author << ": " << obj->pages << endl;
	out << obj->author << ": " << obj->grade << endl;
	out << obj->author << ": " << obj->cost << endl;
	return out;
}
istream& operator>> (istream &in, Textbook &obj) {
	in >> obj.pages;
	in >> obj.grade;
	in >> obj.cost;
	in >> obj.author;
	return in;
}
istream& operator>> (istream &in, Textbook *obj) {
	in >> obj->pages;
	in >> obj->grade;
	in >> obj->cost;
	in >> obj->author;
	return in;
}
Textbook& Textbook::operator= (const Textbook &obj) {
	pages = obj.pages;
	grade = obj.grade;
	cost = obj.cost;
	return *this;
}
Textbook::~Textbook() {
};
int Textbook::getPages() {
	return Textbook::pages;
}
int Textbook::getGrade() {
	return Textbook::grade;
}
int Textbook::getCost() {
	return Textbook::cost;
}
string Textbook::getAuthor() {
	return Textbook::author;
}
void Textbook::generateData(string s) {
	this->pages = rand() % 220 + 100;
	this->grade = rand() % 11 + 1;
	this->cost = rand() % 300 + 100;
	this->author = s;
}
void Textbook::setInfo(int pages, int grade, int cost, string author) {
	this->author = author;
	this->pages = pages;
	this->grade = grade;
	this->cost = cost;
}