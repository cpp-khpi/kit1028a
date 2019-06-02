#include "Classwork.h"

Classwork::Classwork(int amount, int written, int mark, std::string person, int homework_count) : classwork_count(classwork_count), InfoIndependentsWork() {
}
Classwork::Classwork() : classwork_count(0) {
}
Classwork::Classwork(const Classwork &obj) : classwork_count(obj.classwork_count), InfoIndependentsWork(obj.amount, obj.written, obj.mark, obj.person) {
}
Classwork::~Classwork() {
}
int Classwork::get_classwork() {
	return Classwork::classwork_count;
}
void Classwork::generation_values(std::string s) {
	classwork_count = rand() % 16;
	amount = 8 + rand() % 8;
	written = amount - rand() % 8;
	mark = 1 + rand() % 5;
	person = s;
}
void Classwork::set_data(int classwork_count, int amount, int written, int mark, std::string person) {
	this->classwork_count = classwork_count;
	this->person = person;
	this->amount = amount;
	this->written = written;
	this->mark = mark;
}
void Classwork::input() {
	std::cout << "Enter student person: ";
	std::cin.ignore();
	getline(std::cin, person);
	std::cout << "Enter amount of independent works:  ";
	std::cin >> amount;
	std::cout << "Enter amount of written independent works:  ";
	std::cin >> written;
	std::cout << "Enter student mark (average):  ";
	std::cin >> mark;
	std::cout << "Enter student classwork:  ";
	std::cin >> classwork_count;
	std::cout << std::endl;
}
void Classwork::output() {
	std::cout << "Student info: " << person << std::endl;
	std::cout << "Amount of independent works: " << amount << std::endl;
	std::cout << "Amount of written independent works: " << written << std::endl;
	std::cout << "Student mark (average): " << mark << std::endl;
	std::cout << "Student classwork: " << classwork_count << std::endl << std::endl;
}
void Classwork::output_to_file(std::ofstream& file) {
	file << "Student info: " << person << std::endl;
	file << "Amount of independent works: " << amount << std::endl;
	file << "Amount of written independent works: " << written << std::endl;
	file << "Student mark (average): " << mark << std::endl;
	file << "Student homework : " << classwork_count << std::endl << std::endl;
}