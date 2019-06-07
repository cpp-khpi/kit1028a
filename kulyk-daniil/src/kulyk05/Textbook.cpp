#include"Textbook.h"

Textbook::Textbook() :num(0), pages(0), grade(0), cost(0), year_of_release(0), author() {
};
Textbook::Textbook(int n, int p, int g, int c, int y, string sur) :
	num(n), pages(p), grade(g), cost(c), year_of_release(y) {
	author = sur;
};
Textbook::Textbook(const Textbook &obj) :num(obj.num), pages(obj.pages), grade(obj.grade), cost(obj.cost), year_of_release(obj.year_of_release), author(obj.author) {};

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
void Textbook::setInfo(int num, int pages, int grade, int cost, int year_of_release, string author) {
	Textbook::num = num;
	Textbook::pages = pages;
	Textbook::grade = grade;
	Textbook::cost = cost;
	Textbook::year_of_release = year_of_release;
	Textbook::author = author;
}

void Textbook::printInfo() {
	picture.printInfo();
}

void Textbook::RatingStats() {
	cout << "This textbook has " << rate.getRate() << "/10. Thanks for your voting." << endl;
}