#include "Main.h"

//setter
void WorkingProgram::setName(string name) {
	this->program = name;
}

void WorkingProgram::setPublisher(string publisher) {
	this->publisher = publisher;
}

void WorkingProgram::setOpMemoryMb(float opMemoryMb) {
	this->RAM = opMemoryMb;
}

void WorkingProgram::setMemoryGb(float memoryGb) {
	this->HDisk = memoryGb;
}

void WorkingProgram::setTimeWorkMin(float timeWorkMin) {
	this->timeWorkMin = timeWorkMin;
}


//getter
string WorkingProgram::getProgram() {
	return program;
}

string WorkingProgram::getPublisher() {
	return publisher;
}

float WorkingProgram::getRAM() {
	return RAM;
}

float WorkingProgram::getMemoryGb() {
	return HDisk;
}

float WorkingProgram::getTimeWorkMin() {
	return timeWorkMin;
}

WorkingProgram::WorkingProgram() : program(""), publisher(""), RAM(0), HDisk(0), timeWorkMin(0) {
}

string WorkingProgram::print() {
	stringstream lineObj;
	lineObj << program << "|";
	lineObj << publisher << "|";
	lineObj << RAM << " ";
	lineObj << HDisk << " ";
	lineObj << timeWorkMin << " ";
	string infoObj;
	getline(lineObj, infoObj);
	return infoObj;
}

void WorkingProgram::setObj(string &info) {
	stringstream timeLine;
	
	timeLine << info;
	getline(timeLine, program, '|');
	getline(timeLine, publisher, '|');	
	timeLine >> RAM;
	timeLine >> HDisk;
	timeLine >> timeWorkMin;
}