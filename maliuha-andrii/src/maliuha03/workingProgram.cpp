#include "Header.h"

//setter
void workingProgram::setName(string name) {
	this->name = name;
}

void workingProgram::setPublisher(string publisher) {
	this->publisher = publisher;
}

void workingProgram::setOpMemoryMb(float opMemory) {
	this->opMemoryMb = opMemory;
}

void workingProgram::setMemoryGb(float memoryGb) {
	this->memoryGb = memoryGb;
}

void workingProgram::setTimeWorkMin(float timeWorkMin) {
	this->timeWorkMin = timeWorkMin;
}


//getter
string workingProgram::getName() {
	return name;
}

string workingProgram::getPublisher() {
	return publisher;
}

float workingProgram::getOpMemoryMb() {
	return opMemoryMb;
}

float workingProgram::getMemoryGb() {
	return memoryGb;
}

float workingProgram::getTimeWorkMin() {
	return timeWorkMin;
}

workingProgram::workingProgram() : name(""), publisher(""), opMemoryMb(0), memoryGb(0), timeWorkMin(0) {
}

void const workingProgram::print() {
	cout << "Name of program: " << name << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "Amount of consumed RAM(Mb): " << opMemoryMb << endl;
	cout << "Ocupied amount of hard disk memory(Gb): " << memoryGb << endl;
	cout << "Time of work (in minutes): " << timeWorkMin << endl << endl;
}

