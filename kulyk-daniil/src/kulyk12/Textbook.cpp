#include "Textbook.h"

Textbook::Textbook() :pages(rand() % 110 + 170), grade(rand() % 5 + 1), cost(rand() % 90 + 230), author() {
};
Textbook::Textbook(int p, int g, int c, string surname) :pages(p), grade(g), cost(c), author(surname) {
};
Textbook::Textbook(const Textbook &obj) :pages(obj.pages), grade(obj.grade), cost(obj.cost), author(obj.author) {
};

void Textbook::generateObject(string surname) {
	grade = rand() % 11 + 1;
	pages = rand() % 100 + 180;
	cost = rand() % 100 + 220;
	author = surname;
}
void Textbook::setInfo(int grade, int pages, int cost, string surname) {
	this->grade = grade;
	this->pages = pages;
	this->cost = cost;
	this->author = surname;
}
Textbook Textbook::getInfo() {
	Textbook obj;
	obj.author = author;
	obj.grade = grade;
	obj.pages = pages;
	obj.cost = cost;
	return obj;
}
int Textbook::getGrade() {
	return this->grade;
}
int Textbook::getPages() {
	return this->pages;
}
int Textbook::getCost() {
	return this->cost;
}
string Textbook::getAuthor() {
	return this->author;
}