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

string workingProgram::print() {
	stringstream lineObj;
	lineObj << name << "|";
	lineObj << publisher << "|";
	lineObj << opMemoryMb << " ";
	lineObj << memoryGb << " ";
	lineObj << timeWorkMin << " ";
	string infoObj;
	getline(lineObj, infoObj);
	return infoObj;
}

void workingProgram::setObj(string &info) {
	stringstream timeLine;

	timeLine << info;
	getline(timeLine, name, '|');
	getline(timeLine, publisher, '|');
	timeLine >> opMemoryMb;
	timeLine >> memoryGb;
	timeLine >> timeWorkMin;
}