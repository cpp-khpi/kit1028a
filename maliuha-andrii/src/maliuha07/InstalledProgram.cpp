#include "Main.h"

//setter
//setter
void InstalledProgram::setName(string name) {
	this->name = name;
}

void InstalledProgram::setPublisher(string publisher) {
	this->publisher = publisher;
}

void InstalledProgram::setRAM(float opMemoryMb) {
	this->RAM = opMemoryMb;
}

void InstalledProgram::setHDisk(float memoryGb) {
	this->hDisk = memoryGb;
}

void InstalledProgram::setTimer(Time *timeWorkMin) {
	this->timer = timeWorkMin;
}

void InstalledProgram::setVersion(Version version) {
	this->version = version;
}

//getter
string InstalledProgram::getName() {
	return name;
}

string InstalledProgram::getPublisher() {
	return publisher;
}

float InstalledProgram::getRAM() {
	return RAM;
}

float InstalledProgram::getHDisk() {
	return hDisk;
}

Time *InstalledProgram::getTimer() {
	return timer;
}

Version InstalledProgram::getVersion() {
	return version;
}



InstalledProgram::InstalledProgram() : name(""), publisher(""), RAM(0), hDisk(0) {
	timer = new Time;
	timer->hours = 0;
	timer->minutes = 0;
	timer->seconds = 0;
	version.name = "";
	version.arr[0] = 0;
	version.arr[1] = 0;
	version.arr[2] = 0;
}

string InstalledProgram::print() {
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

void InstalledProgram::setObj(string &info) {
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