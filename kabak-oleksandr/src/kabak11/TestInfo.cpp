#include "TestInfo.h"

TestInfo::TestInfo() : mark(0) {
}
TestInfo::TestInfo(int mark) : mark(mark) {
}
TestInfo::TestInfo(const TestInfo& obj) : mark(obj.mark) {
}
TestInfo::~TestInfo() {
}

TestInfo& TestInfo::operator= (const TestInfo& obj) {
	mark = obj.mark;
	return *this;
}
std::ostream& operator<< (std::ostream& out, const TestInfo& obj) {
	out << obj.mark << std::endl;
	return out;
}
std::istream& operator>> (std::istream& in, TestInfo& obj) {
	in >> obj.mark;
	return in;
}
bool TestInfo::operator== (const TestInfo obj) {
	return (mark == obj.mark);
}


int TestInfo::getMark() {
	return this->mark;
}
void TestInfo::randValues() {
	mark = rand() % 5 + 1;
}
void TestInfo::setInfo(int mark) {
	this->mark = mark;
}