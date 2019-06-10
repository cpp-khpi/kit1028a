#include "Algebra.h"

Algebra::Algebra(int pages, int grade, int cost, string author, int amount_of_examples) : amount_of_examples(amount_of_examples), Textbook() {
}
Algebra::Algebra() : amount_of_examples(0) {
}
Algebra::Algebra(const Algebra &obj) : amount_of_examples(obj.amount_of_examples), Textbook(obj.pages, obj.grade, obj.cost, obj.author) {
}
Algebra::~Algebra() {
}
ostream& operator<< (ostream &out, const Algebra &obj) {
	out << obj.author << ": " << obj.amount_of_examples << endl;
	return out;
}
ostream& operator<< (ostream &out, const Algebra *obj) {
	out << obj->author << ": " << obj->amount_of_examples << endl;
	return out;
}
istream& operator>> (istream &in, Algebra &obj) {
	in >> obj.pages;
	in >> obj.grade;
	in >> obj.cost;
	in >> obj.amount_of_examples;
	in >> obj.author;
	return in;
}
istream& operator>> (istream &in, Algebra *obj) {
	in >> obj->pages;
	in >> obj->grade;
	in >> obj->cost;
	in >> obj->amount_of_examples;
	in >> obj->author;
	return in;
}
bool Algebra::operator< (const Algebra obj) {
	return (pages < obj.pages && grade < obj.grade && cost < obj.cost && amount_of_examples < obj.amount_of_examples);
}
bool Algebra::operator> (const Algebra obj) {
	return (pages > obj.pages && grade > obj.grade && cost > obj.cost && amount_of_examples > obj.amount_of_examples);
}
int Algebra::getAmountOfExamples() {
	return Algebra::amount_of_examples;
}
void Algebra::generateData(string s) {
	amount_of_examples = rand() % 400 + 600;
	this->pages = rand() % 220 + 100;
	this->grade = rand() % 11 + 1;
	this->cost = rand() % 300 + 100;
	this->author = s;
}
void Algebra::setInfo(int amount_of_examples, int pages, int grade, int cost, string author) {
	this->amount_of_examples = amount_of_examples;
	this->author = author;
	this->pages = pages;
	this->grade = grade;
	this->cost = cost;
}
void Algebra::input() {
	cout << "Enter the textbook author: ";
	cin.ignore();
	getline(cin, author);
	cout << "Enter the amount of pages:  ";
	cin >> pages;
	cout << "Enter the grade:  ";
	cin >> grade;
	cout << "Enter the cost:  ";
	cin >> cost;
	cout << "Enter the amount of examples:  ";
	cin >> amount_of_examples;
	cout << endl;
}
void Algebra::output() {
	cout << "Author is: " << author << endl;
	cout << "The amount of pages: " << pages << endl;
	cout << "The grade: " << grade << endl;
	cout << "The cost: " << cost << endl;
	cout << "The amount of examples " << amount_of_examples << endl << endl;
}
void Algebra::outputToFile(ofstream& file) {
	file << "Author is: " << author << endl;
	file << "The amount of pages: " << pages << endl;
	file << "The grade: " << grade << endl; 
	file << "The cost: " << cost << endl;
	file << "The amount of examples " << amount_of_examples << endl << endl;
}