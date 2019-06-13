#include "IndependentsWork.h"

IndependentsWork::IndependentsWork() :amount(0), written(0), mark(0) {
}
IndependentsWork::IndependentsWork(const IndependentsWork &obj) : amount(obj.amount), written(obj.written), mark(obj.mark) {
}
IndependentsWork::IndependentsWork(int amount, int written, int mark) : amount(amount), written(written), mark(mark) {
}
std::ostream& operator<< (std::ostream &out, const IndependentsWork &obj) {
	out << obj.amount << std::endl;
	out << obj.written << std::endl;
	out << obj.mark << std::endl;
	return out;
}
std::istream& operator>> (std::istream &in, IndependentsWork &obj) {
	in >> obj.amount;
	in >> obj.written;
	in >> obj.mark;
	return in;
}
IndependentsWork& IndependentsWork::operator= (const IndependentsWork &obj) {
	amount = obj.amount;
	written = obj.written;
	mark = obj.mark;
	return *this;
}
void* IndependentsWork::operator new(size_t size) {
	void* pointer = malloc(size);
	if (pointer == nullptr) {
		throw std::bad_alloc();
	}
	std::cout << "Memory was allocated for " << size << " elements" << std::endl;
	return pointer;
}
void IndependentsWork::operator delete(void *pointer) {
	free(pointer);
	std::cout << "The memory has been freed" << std::endl;
}
void* IndependentsWork::operator new[](size_t size) {
	void* pointer = malloc(size);
	if (pointer == nullptr) {
		throw std::bad_alloc();
	}
	std::cout << "Memory was allocated for " << size << " elements" << std::endl;
	return pointer;
}
void IndependentsWork::operator delete[](void *pointer) {
	free(pointer);
	std::cout << "The memory has been freed" << std::endl;
}
IndependentsWork::~IndependentsWork() {
};
int IndependentsWork::get_amount() {
	return IndependentsWork::amount;
}
int IndependentsWork::get_written() {
	return IndependentsWork::written;
}
int IndependentsWork::get_mark() {
	return IndependentsWork::mark;
}
void IndependentsWork::generation_values() {
	this->amount = 8 + rand() % 8;
	this->written = amount - rand() % 8;
	this->mark = 1 + rand() % 5;
}
void IndependentsWork::set_data(int amount, int written, int mark) {
	this->amount = amount;
	this->written = written;
	this->mark = mark;
}
