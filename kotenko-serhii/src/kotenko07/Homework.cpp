#include "Homework.h"

Homework::Homework(int amount, int written, int mark, std::string person, int homework_count) : homework_count(homework_count), InfoIndependentsWork() {
}
Homework::Homework() : homework_count(0) {
}
Homework::Homework(const Homework &obj) : homework_count(obj.homework_count), InfoIndependentsWork(obj.amount, obj.written, obj.mark, obj.person) {
}
Homework::~Homework() {
}
int Homework::get_homework() {
	return Homework::homework_count;
}
void Homework::generation_values(std::string s) {
	homework_count = rand() % 16;
	amount = 8 + rand() % 8;
	written = amount - rand() % 8;
	mark = 1 + rand() % 5;
	person = s;
}
void Homework::set_data(int homework_count, int amount, int written, int mark, std::string person) {
	this->homework_count = homework_count;
	this->person = person;
	this->amount = amount;
	this->written = written;
	this->mark = mark;
}
void Homework::input() {
	std::cout << "Enter student person: ";
	std::cin.ignore();
	getline(std::cin, person);
	std::cout << "Enter amount of independent works:  ";
	std::cin >> amount;
	std::cout << "Enter amount of written independent works:  ";
	std::cin >> written;
	std::cout << "Enter student mark (average):  ";
	std::cin >> mark;
	std::cout << "Enter student homework:  ";
	std::cin >> homework_count;
	std::cout << std::endl;
}
void Homework::output() {
	std::cout << "Student info: " << person << std::endl;
	std::cout << "Amount of independent works: " << amount << std::endl;
	std::cout << "Amount of written independent works: " << written << std::endl;
	std::cout << "Student mark (average): " << mark << std::endl;
	std::cout << "Student homework: " << homework_count << std::endl << std::endl;
}
void Homework::output_to_file(std::ofstream& file) {
	file << "Student info: " << person << std::endl;
	file << "Amount of independent works: " << amount << std::endl;
	file << "Amount of written independent works: " << written << std::endl;
	file << "Student mark (average): " << mark << std::endl ;
	file << "Student homework : " << homework_count << std::endl << std::endl;
}