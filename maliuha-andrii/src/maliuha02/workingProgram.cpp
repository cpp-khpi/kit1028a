#include "Header.h"

//setter
void workingProgram::setName(char* n) {
	strcpy (name, n);
}

void workingProgram::setPublisher(char* p) {
	strcpy(publisher, p);
}

void workingProgram::setOpMemoryMb(float om) {
	opMemoryMb = om;
}

void workingProgram::setMemoryGb(float mg) {
	memoryGb = mg;
}

void workingProgram::setTimeWorkMin(float twm) {
	timeWorkMin = twm;
}


//getter
char* workingProgram::getName() {
	return name;
}

char* workingProgram::getPublisher() {
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

workingProgram::workingProgram() : name(NULL), publisher(NULL), opMemoryMb(0), memoryGb(0), timeWorkMin(0) {
	name = new char[50];
	publisher = new char[50];
}

void const workingProgram::print() {
	cout << "Name of program: " << name << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "Amount of consumed RAM(Mb): " << opMemoryMb << endl;
	cout << "Ocupied amount of hard disk memory(Gb): " << memoryGb << endl;
	cout << "Time of work (in minutes): " << timeWorkMin << endl << endl;
}

workingProgram::workingProgram(const workingProgram &obj) {
	strcpy(name, obj.name);
	strcpy(publisher, obj.publisher);
	opMemoryMb = obj.opMemoryMb;
	memoryGb = obj.memoryGb;
	timeWorkMin = obj.timeWorkMin;
}

workingProgram::~workingProgram() {
	delete[] name;
	delete[] publisher;
	name = NULL;
	publisher = NULL;
}

workingProgram::workingProgram(char *name, char* publisher, float opMemoryMb, float memoryGb, float timeWorkMin) {
	strcpy(this->name, name);
	strcpy(this->publisher, publisher);
	this->opMemoryMb = opMemoryMb;
	this->memoryGb = memoryGb;
	this->timeWorkMin = timeWorkMin;
}