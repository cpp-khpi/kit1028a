#include"Textbook.h"

Textbook::Textbook() :num(0), pages(0), grade(0), cost(0), year_of_release(0), author() {
};
Textbook::Textbook(int n, int p, int g, int c, int y, string sur) :
	num(n), pages(p), grade(g), cost(c), year_of_release(y) {
	author = sur;
};
Textbook::Textbook(const Textbook &obj) :num(obj.num), pages(obj.pages), grade(obj.grade), cost(obj.cost),
year_of_release(obj.year_of_release), author(obj.author) {
};

void Textbook::setInfo(int num, int pages, int grade, int cost, int year_of_release, string author) {
	Textbook::num = num;
	Textbook::pages = pages;
	Textbook::grade = grade;
	Textbook::cost = cost;
	Textbook::year_of_release = year_of_release;
	Textbook::author = author;
}

int Textbook::getNum() {
	return Textbook::num;
}

int Textbook::getPages() {
	return Textbook::pages;
}

int Textbook::getGrade() {
	return Textbook::grade;
}

int Textbook::getCost() {
	return Textbook::cost;
}

int Textbook::getYearOfRelease() {
	return Textbook::year_of_release;
}

string Textbook::getAuthor() {
	return Textbook::author;
}

void Textbook::getInfo(string str) {
	num = num;
	pages = rand() % 100 + 180;
	grade = rand() % 11 + 1;
	cost = rand() % 100 + 220;
	year_of_release = rand() % 15 + 2000;
	author = str;
}

std::ostream& operator<< (std::ostream &out, const Textbook &obj) {
	out << obj.author << ": " << obj.num << endl;
	out << obj.author << ": " << obj.pages << endl;
	out << obj.author << ": " << obj.grade << endl;
	out << obj.author << ": " << obj.cost << endl;
	out << obj.author << ": " << obj.year_of_release << endl;
	return out;
}
std::istream& operator>> (std::istream &in, Textbook &obj) {
	in >> obj.num;
	in >> obj.pages;
	in >> obj.grade;
	in >> obj.cost;
	in >> obj.year_of_release;
	in >> obj.author;
	return in;
}
Textbook& Textbook::operator= (const Textbook &obj) {
	num = obj.num;
	pages = obj.pages;
	grade = obj.grade;
	cost = obj.cost;
	year_of_release = obj.year_of_release;
	return *this;
}
bool Textbook::operator< (const Textbook obj) {
	return (num < obj.num && pages < obj.pages && grade < obj.grade && cost < obj.cost && year_of_release < obj.year_of_release);
}
bool Textbook::operator> (const Textbook obj) {
	return (num > obj.num && pages > obj.pages && grade > obj.grade && cost > obj.cost && year_of_release > obj.year_of_release);
}