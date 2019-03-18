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
char* workingProgram::getName(char* n) {
	strcpy(n, name);
	return n;
}

char* workingProgram::getPublisher(char* p) {
	strcpy(p, publisher);
	return p;
}

float workingProgram::getOpMemoryMb(float om) {
	om = opMemoryMb;
	return om;
}

float workingProgram::getMemoryGb(float mg) {
	mg = memoryGb;
	return mg;
}
float workingProgram::getTimeWorkMin(float twm) {
	twm = timeWorkMin;
	return twm;
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
	cout << "Time of work (in minutes): " << timeWorkMin << endl;
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
}

workingProgram::workingProgram(char *name, char* publisher, float opMemoryMb, float memoryGb, float timeWorkMin) {
	strcpy(this->name, name);
	strcpy(this->publisher, publisher);
	this->opMemoryMb = opMemoryMb;
	this->memoryGb = memoryGb;
	this->timeWorkMin = timeWorkMin;
}