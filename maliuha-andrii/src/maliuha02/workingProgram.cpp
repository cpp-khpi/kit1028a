#include "Header.h"

//setter
void workingProgram::setName(char* n) {
	strcpy (name, n);
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

workingProgram::workingProgram() {
	name = (char*)calloc(50,sizeof(char));
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

workingProgram::workingProgram(const workingProgram &obj) {
	strcpy(name, obj.name);
	opMemoryMb = obj.opMemoryMb;
	memoryGb = obj.memoryGb;
	timeWorkMin = obj.timeWorkMin;
}
