#include "Header.h"

//setter
void workingProgram::setName(string name) {
	this->name = name;
}

void workingProgram::setPublisher(string publisher) {
	this->publisher = publisher;
}

void workingProgram::setOpMemoryMb(float opMemoryMb) {
	this->opMemoryMb = opMemoryMb;
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

stringstream workingProgram::print() {
	stringstream lineObj;
	lineObj << "Name of program: " << name << "\n";
	lineObj << "Publisher: " << publisher << "\n";
	lineObj << "Amount of consumed RAM(Mb): " << opMemoryMb << "\n";
	lineObj << "Ocupied amount of hard disk memory(Gb): " << memoryGb << "\n";
	lineObj << "Time of work (in minutes): " << timeWorkMin << "\n";
	return lineObj;
}

