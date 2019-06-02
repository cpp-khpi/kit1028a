#include "Main.h"

//setter
//setter
void InstalledProgram::setName(string name) {
	this->name = name;
}

void InstalledProgram::setPublisher(string publisher) {
	this->publisher = publisher;
}


void InstalledProgram::setHDisk(float memoryGb) {
	this->hDisk = memoryGb;
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

float InstalledProgram::getHDisk() {
	return hDisk;
}

Version InstalledProgram::getVersion() {
	return version;
}



InstalledProgram::InstalledProgram() : name(""), publisher(""), hDisk(0) {
	version.name = "";
	version.arr[0] = 0;
	version.arr[1] = 0;
	version.arr[2] = 0;
}

string InstalledProgram::print() {
	stringstream lineObj;
	lineObj << name << "|";
	lineObj << publisher << "|";
	lineObj << hDisk << " ";
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
	timeLine >> hDisk;
	getline(timeLine, version.name, '|');
	timeLine >> version.arr[0];
	timeLine >> version.arr[1];
	timeLine >> version.arr[2];
}

void InstalledProgram::setInfoObj(string &info) {
	string name;
	string publisher;
	float RAM, hDisk;
	Time *timer = new Time;
	stringstream infoObj;
	Version version;
	Array ops;
	while (true) {
		cout << "Enter name of program:" << endl;
		getline(cin, name);
		if (ops.inputCheck(name) == true) {
			break;
		}
	}
	while (true) {
		cout << "Enter name of publisher(if you don't know, enter 'Unknown'):" << endl;
		getline(cin, publisher);
		if (ops.inputCheck(publisher) == true) {
			break;
		}
	}

	infoObj << name << "|";
	infoObj << publisher << "|";

	cout << "Enter ocupied amount of hard disk memory(Gg):" << endl;
	cin >> hDisk;
	infoObj << hDisk << " ";

	cin.ignore();
	cout << "Enter version:" << endl;
	cout << "Name of version - ";
	getline(cin, version.name);
	infoObj << version.name << '|';

	cout << "First number - ";
	cin >> version.arr[0];
	infoObj << version.arr[0] << " ";

	cout << "Second number - ";
	cin >> version.arr[1];
	infoObj << version.arr[1] << " ";

	cout << "Third number - ";
	cin >> version.arr[2];
	infoObj << version.arr[2];

	getline(infoObj, info);
}

void InstalledProgram::show() {
	cout << "Name of program: " << name << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "Ocupied amount of hard disk memory(Gb): " << hDisk << endl;
	cout << "Version: " << version.name << ' ' << version.arr[0] << '.' << version.arr[1] << '.' << version.arr[2] << endl;
	cout << "------------------------------------------------------" << endl;
}