#include "Header.h"

//setter
void programOn::setName(string n) {
	programOn::name = n;
}

void programOn::setOpMemoryMb(float om) {
	programOn::opMemoryMb = om;
}

void programOn::setMemoryGb(float mg) {
	programOn::memoryGb = mg;
}

void programOn::setTimeWorkMin(float twm) {
	programOn::timeWorkMin = twm;
}


//getter
string programOn::getName(string n) {
	n = programOn::name;
	return n;
}

float programOn::getOpMemoryMb(float om) {
	om = programOn::opMemoryMb;
	return om;
}

float programOn::getMemoryGb(float mg) {
	mg = programOn::memoryGb;
	return mg;
}
float programOn::getTimeWorkMin(float twm) {
	twm = programOn::timeWorkMin;
	return twm;
}