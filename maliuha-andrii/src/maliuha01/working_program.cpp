#include "Header.h"

//setter
void workingProgram::setName(string n) {
	workingProgram::name = n;
}

void workingProgram::setOpMemoryMb(float om) {
	workingProgram::opMemoryMb = om;
}

void workingProgram::setMemoryGb(float mg) {
	workingProgram::memoryGb = mg;
}

void workingProgram::setTimeWorkMin(float twm) {
	workingProgram::timeWorkMin = twm;
}


//getter
string workingProgram::getName(string n) {
	n = workingProgram::name;
	return n;
}

float workingProgram::getOpMemoryMb(float om) {
	om = workingProgram::opMemoryMb;
	return om;
}

float workingProgram::getMemoryGb(float mg) {
	mg = workingProgram::memoryGb;
	return mg;
}
float workingProgram::getTimeWorkMin(float twm) {
	twm = workingProgram::timeWorkMin;
	return twm;
}

workingProgram::workingProgram() {
	name = '\0';
	opMemoryMb = 0;
	memoryGb = 0;
	timeWorkMin = 0;
}

void const workingProgram::print() {
	cout << "Name of program: " << name << endl;
	cout << "Amount of consumed RAM(Mb): " << opMemoryMb << endl;
	cout << "Ocupied amount of hard disk memory(Gb): " << memoryGb << endl;
	cout << "Time of work (in minutes): " << timeWorkMin << endl;
}