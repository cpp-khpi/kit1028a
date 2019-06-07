#include "Grammarway.h"

Grammarway::Grammarway(int num, int pages, int grade, int cost, int year_of_release, string author, int homework_count) : difficulty(homework_count), Textbook() {
}
Grammarway::Grammarway() : difficulty(0) {
}
Grammarway::Grammarway(const Grammarway &obj) : difficulty(obj.difficulty), Textbook((obj.num), (obj.pages), (obj.grade), (obj.cost),
	(obj.year_of_release), (obj.author)) {
}
Grammarway::~Grammarway() {
}

int Grammarway::getDifficulty() {
	return Grammarway::difficulty;
}
void Grammarway::getInfo(string str) {
	num = num;
	pages = rand() % 100 + 180;
	grade = rand() % 11 + 1;
	cost = rand() % 100 + 220;
	year_of_release = rand() % 15 + 2000;
	author = str;
	difficulty = rand() % 10 + 1;
}
void Grammarway::setData(int num, int pages, int grade, int cost, int year_of_release, string author, int difficulty) {
	Textbook::num = num;
	Textbook::pages = pages;
	Textbook::grade = grade;
	Textbook::cost = cost;
	Textbook::year_of_release = year_of_release;
	Textbook::author = author;
	this->difficulty = difficulty;
}
void Grammarway::input() {
	std::cout << "Enter the textbook number:  ";
	std::cin >> num;
	std::cout << "Enter the number of pages in the textbook:  ";
	std::cin >> pages;
	std::cout << "Enter the grade the textbook for:  ";
	std::cin >> grade;
	std::cout << "Enter the cost of the textbook:  ";
	std::cin >> cost;
	std::cout << "Enter the year of release of the textbook:  ";
	std::cin >> year_of_release;
	std::cout << "Enter the author's name:  ";
	std::cin.ignore();
	getline(cin, author);
	std::cout << "Enter the difficulty of the textbook:  ";
	std::cin >> difficulty;
	std::cout << std::endl;
}
void Grammarway::output() {
	cout << "The textbook number : " << num << endl;
	cout << "The number of pages in the textbook: " << pages << endl;
	cout << "The grade the textbook for: " << grade << endl;
	cout << "The cost of the textbook: " << cost << endl;
	cout << "The year of release of the textbook: " << year_of_release << endl;
	cout << "The author's name: " << author << endl;
	cout << "The difficulty of the textbook: " << difficulty << endl << endl;
}
void Grammarway::output_to_file(std::ofstream& file) {
	file << "The textbook number : " << num << endl;
	file << "The number of pages in the textbook: " << pages << endl;
	file << "The grade the textbook for: " << grade << endl;
	file << "The cost of the textbook: " << cost << endl;
	file << "The year of release of the textbook: " << year_of_release << endl;
	file << "The author's name: " << author << endl;
	file << "The difficulty of the textbook: " << difficulty << endl << endl;
}
