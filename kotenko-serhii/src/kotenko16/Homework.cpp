#include "Homework.h"

Homework::Homework(int amount, int written, int mark, int homework_count) : homework_count(homework_count), IndependentsWork() {
}
Homework::Homework() : homework_count(0) {
}
Homework::Homework(const Homework &obj) : homework_count(obj.homework_count), IndependentsWork(obj.amount, obj.written, obj.mark) {
}
Homework::~Homework() {
}
std::ostream& operator<< (std::ostream &out, const Homework &obj) {
	out << obj.homework_count << std::endl;
	return out;
}
std::istream& operator>> (std::istream &in, Homework &obj) {
	in >> obj.amount;
	in >> obj.written;
	in >> obj.mark;
	in >> obj.homework_count;
	return in;
}
bool Homework::operator< (const Homework obj) {
	return (amount < obj.amount && written < obj.written && mark < obj.mark && homework_count < obj.homework_count);
}
bool Homework::operator> (const Homework obj) {
	return (amount > obj.amount && written > obj.written && mark > obj.mark && homework_count > obj.homework_count);
}
void* Homework::operator new(size_t size) {
	void* pointer = malloc(size);
	if (pointer == nullptr) {
		throw std::bad_alloc();
	}
	std::cout << "Memory was allocated for " << size << " elements" << std::endl;
	return pointer;
}
void Homework::operator delete(void *pointer) {
	free(pointer);
	std::cout << "The memory has been freed" << std::endl;
}
void* Homework::operator new[](size_t size) {
	void* pointer = malloc(size);
	if (pointer == nullptr) {
		throw std::bad_alloc();
	}
	std::cout << "Memory was allocated for " << size << " elements" << std::endl;
	return pointer;
}
void Homework::operator delete[](void *pointer) {
	free(pointer);
	std::cout << "The memory has been freed" << std::endl;
}
int Homework::get_homework() {
	return Homework::homework_count;
}
void Homework::generation_values(std::string s) {
	homework_count = rand() % 16;
	amount = 8 + rand() % 8;
	written = amount - rand() % 8;
	mark = 1 + rand() % 5;
}
void Homework::set_data(int homework_count, int amount, int written, int mark) {
	this->homework_count = homework_count;
	this->amount = amount;
	this->written = written;
	this->mark = mark;
}
