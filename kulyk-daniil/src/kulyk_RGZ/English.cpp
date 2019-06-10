#include "English.h"

English::English(int pages, int grade, int cost, string author, int amount_of_exercises) : amount_of_exercises(amount_of_exercises), Textbook() {
}
English::English() : amount_of_exercises(0) {
}
English::English(const English &obj) : amount_of_exercises(obj.amount_of_exercises), Textbook(obj.pages, obj.grade, obj.cost, obj.author) {
}
English::~English() {
}
std::ostream& operator<< (std::ostream &out, const English &obj) {
	out << obj.author << ": " << obj.amount_of_exercises << std::endl;
	return out;
}
std::ostream& operator<< (std::ostream &out, const English *obj) {
	out << obj->author << ": " << obj->amount_of_exercises << std::endl;
	return out;
}
std::istream& operator>> (std::istream &in, English &obj) {
	in >> obj.pages;
	in >> obj.grade;
	in >> obj.cost;
	in >> obj.amount_of_exercises;
	in >> obj.author;
	return in;
}
std::istream& operator>> (std::istream &in, English *obj) {
	in >> obj->pages;
	in >> obj->grade;
	in >> obj->cost;
	in >> obj->amount_of_exercises;
	in >> obj->author;
	return in;
}
bool English::operator< (const English obj) {
	return (pages < obj.pages && grade < obj.grade && cost < obj.cost && amount_of_exercises < obj.amount_of_exercises);
}
bool English::operator> (const English obj) {
	return (pages > obj.pages && grade > obj.grade && cost > obj.cost && amount_of_exercises > obj.amount_of_exercises);
}
int English::getAmountOfExercises() {
	return English::amount_of_exercises;
}
void English::generateData(string s) {
	amount_of_exercises = rand() % 200 + 150;
	pages = 200 + 100;
	grade = rand() % 11 + 1;
	cost = rand() % 300 + 100;
	author = s;
}
void English::setInfo(int amount_of_exercises, int pages, int grade, int cost, string author) {
	this->amount_of_exercises = amount_of_exercises;
	this->author = author;
	this->pages = pages;
	this->grade = grade;
	this->cost = cost;
}
void English::input() {
	cout << "Enter the textbook author: ";
	cin.ignore();
	getline(cin, author);
	cout << "Enter the amount of pages:  ";
	cin >> pages;
	cout << "Enter the grade:  ";
	cin >> grade;
	cout << "Enter the cost:  ";
	cin >> cost;
	cout << "Enter the amount of exercises:  ";
	cin >> amount_of_exercises;
	cout << endl;
}
void English::output() {
	cout << "Author is: " << author << endl;
	cout << "The amount of pages: " << pages << endl;
	cout << "The grade: " << grade << endl;
	cout << "The cost: " << cost << endl;
	cout << "The amount of exercises " << amount_of_exercises << endl << endl;
}
void English::outputToFile(ofstream& file) {
	file << "Author is: " << author << endl;
	file << "The amount of pages: " << pages << endl;
	file << "The grade: " << grade << endl;
	file << "The cost: " << cost << endl;
	file << "The amount of exercises " << amount_of_exercises << endl << endl;
}