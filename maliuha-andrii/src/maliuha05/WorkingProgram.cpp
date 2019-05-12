#include "Main.h"

//setter
void WorkingProgram::setName(string name) {
	this->name = name;
}

void WorkingProgram::setPublisher(string publisher) {
	this->publisher = publisher;
}

void WorkingProgram::setOpMemoryMb(float opMemoryMb) {
	this->opMemoryMb = opMemoryMb;
}

void WorkingProgram::setMemoryGb(float memoryGb) {
	this->memoryGb = memoryGb;
}

void WorkingProgram::setTimeWorkMin(float timeWorkMin) {
	this->timeWorkMin = timeWorkMin;
}


//getter
string WorkingProgram::getName() {
	return name;
}

string WorkingProgram::getPublisher() {
	return publisher;
}

float WorkingProgram::getOpMemoryMb() {
	return opMemoryMb;
}

float WorkingProgram::getMemoryGb() {
	return memoryGb;
}

float WorkingProgram::getTimeWorkMin() {
	return timeWorkMin;
}

WorkingProgram::WorkingProgram() : name(""), publisher(""), opMemoryMb(0), memoryGb(0), timeWorkMin(0) {
}

string WorkingProgram::print() {
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

void WorkingProgram::setObj(string &info) {
	stringstream timeLine;
	
	timeLine << info;
	getline(timeLine, name, '|');
	getline(timeLine, publisher, '|');	
	timeLine >> opMemoryMb;
	timeLine >> memoryGb;
	timeLine >> timeWorkMin;
}