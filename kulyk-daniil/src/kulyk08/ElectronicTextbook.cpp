#include "ElectronicTextbook.h"

ElectronicTextbook::ElectronicTextbook(int num, int pages, int grade, int cost, int year_of_release, string person, int amount_of_charge) : 
	amount_of_charge(amount_of_charge), Textbook() {
}
ElectronicTextbook::ElectronicTextbook() : amount_of_charge(0) {
}
ElectronicTextbook::ElectronicTextbook(const ElectronicTextbook &obj) : amount_of_charge(obj.amount_of_charge), Textbook(obj.num, obj.pages, 
	obj.grade, obj.cost, obj.year_of_release, obj.author) {
}
ElectronicTextbook::~ElectronicTextbook() {
}
std::ostream& operator<< (std::ostream &out, const ElectronicTextbook &obj) {
	out << obj.author << ": " << obj.amount_of_charge << endl;
	return out;
}
std::istream& operator>> (std::istream &in, ElectronicTextbook &obj) {
	in >> obj.num;
	in >> obj.pages;
	in >> obj.grade;
	in >> obj.cost;
	in >> obj.year_of_release;
	in >> obj.amount_of_charge;
	in >> obj.author;
	return in;
}
bool ElectronicTextbook::operator< (const ElectronicTextbook obj) {
	return (num < obj.num && pages < obj.pages && grade < obj.grade && cost < obj.cost && year_of_release < obj.year_of_release && amount_of_charge < obj.amount_of_charge);
}
bool ElectronicTextbook::operator> (const ElectronicTextbook obj) {
	return (num > obj.num && pages > obj.pages && grade > obj.grade && cost > obj.cost && year_of_release > obj.year_of_release && amount_of_charge > obj.amount_of_charge);
}
int ElectronicTextbook::getAmountOfCharge() {
	return ElectronicTextbook::amount_of_charge;
}
void ElectronicTextbook::getInfo(string s) {
	amount_of_charge = rand() % 100 + 0;
	num = rand() % 4 + 1;
	pages = rand() % 100 + 180;
	grade = rand () % 11 + 1;
	cost = rand() % 100 + 220;
	year_of_release = rand() % 15 + 2000;
	author = s;
}
void ElectronicTextbook::setInfo(int amount_of_charge, int num, int pages, int grade, int cost, int year_of_release, string author) {
	this->amount_of_charge = amount_of_charge;
	this->author = author;
	this->num = num;
	this->pages = pages;
	this->grade = grade;
	this->cost = cost;
	this->year_of_release = year_of_release;
}