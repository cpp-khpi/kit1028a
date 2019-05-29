#include "Main.h"

//setter
void WorkingProgram::setName(string name) {
	this->name = name;
}

void WorkingProgram::setPublisher(string publisher) {
	this->publisher = publisher;
}

void WorkingProgram::setRAM(float opMemoryMb) {
	this->RAM = opMemoryMb;
}

void WorkingProgram::setHDisk(float memoryGb) {
	this->hDisk = memoryGb;
}

void WorkingProgram::setTimer(Time *timeWorkMin) {
	this->timer = timeWorkMin;
}

void WorkingProgram::setVersion(Version version) {
	this->version = version;
}

//getter
string WorkingProgram::getName() {
	return name;
}

string WorkingProgram::getPublisher() {
	return publisher;
}

float WorkingProgram::getRAM() {
	return RAM;
}

float WorkingProgram::getHDisk() {
	return hDisk;
}

Time *WorkingProgram::getTimer() {
	return timer;
}

Version WorkingProgram::getVersion() {
	return version;
}



WorkingProgram::WorkingProgram() : name(""), publisher(""), RAM(0), hDisk(0) {
	timer = new Time;
	timer->hours = 0;
	timer->minutes = 0;
	timer->seconds = 0;
	version.name = "";
	version.arr[0] = 0;
	version.arr[1] = 0;
	version.arr[2] = 0;
}

string WorkingProgram::print() {
	stringstream lineObj;
	lineObj << name << "|";
	lineObj << publisher << "|";
	lineObj << RAM << " ";
	lineObj << hDisk << " ";
	lineObj << timer->hours << " ";
	lineObj << timer->minutes << " ";
	lineObj << timer->seconds;
	lineObj << version.name << "|";
	lineObj << version.arr[0] << " " << version.arr[1] << " " << version.arr[2];
	string infoObj;
	getline(lineObj, infoObj);
	return infoObj;
}

void WorkingProgram::setObj(string &info) {
	stringstream timeLine;
	
	timeLine << info;
	getline(timeLine, name, '|');
	getline(timeLine, publisher, '|');	
	timeLine >> RAM;
	timeLine >> hDisk;
	timeLine >> timer->hours;
	timeLine >> timer->minutes;
	timeLine >> timer->seconds;
	getline(timeLine, version.name, '|');
	timeLine >> version.arr[0];
	timeLine >> version.arr[1];
	timeLine >> version.arr[2];
}