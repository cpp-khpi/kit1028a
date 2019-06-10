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

void WorkingProgram::setTimer(Time timeWorkMin) {
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

Time WorkingProgram::getTimer() {
	return timer;
}

Version WorkingProgram::getVersion() {
	return version;
}



WorkingProgram::WorkingProgram() : name(""), publisher(""), RAM(0), hDisk(0) {
	timer.hours = 0;
	timer.minutes = 0;
	timer.seconds = 0;
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
	lineObj << timer.hours << " ";
	lineObj << timer.minutes << " ";
	lineObj << timer.seconds;
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
	timeLine >> timer.hours;
	timeLine >> timer.minutes;
	timeLine >> timer.seconds;
	getline(timeLine, version.name, '|');
	timeLine >> version.arr[0];
	timeLine >> version.arr[1];
	timeLine >> version.arr[2];
}

void WorkingProgram::setInfoObj(string &info) {
	string name;
	string publisher;
	float RAM, hDisk;
	Time timer;
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
	cout << "Enter amount of consumed RAM(Mb):" << endl;
	cin >> RAM;
	infoObj << RAM << " ";

	cout << "Enter ocupied amount of hard disk memory(Gg):" << endl;
	cin >> hDisk;
	infoObj << hDisk << " ";

	cout << "Enter time of work:" << endl;

	cout << "Hours - ";
	cin >> timer.hours;
	infoObj << timer.hours << " ";

	while (true) {
		cout << "(0-59)Minutes - ";
		cin >> timer.minutes;
		infoObj << timer.minutes << " ";
		if (timer.minutes < 0 || timer.minutes >= 60) {
			cout << "You must enter from 0 to 59 minutes, try again" << endl;
		}
		else {
			break;
		}
	}
	while (true) {
		cout << "(0-59)Seconds - ";
		cin >> timer.seconds;
		infoObj << timer.seconds << " ";
		if (timer.seconds < 0 || timer.seconds >= 60) {
			cout << "You must enter from 0 to 59 minutes, try again" << endl;
		}
		else {
			break;
		}
	}

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

const void WorkingProgram::show() {
	cout << "Name of program: " << name << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "Amount of consumed RAM(Mb): " << RAM << endl;
	cout << "Ocupied amount of hard disk memory(Gb): " << hDisk << endl;
	cout << "Time of work: " << timer.hours << "(h) " << timer.minutes << "(m) " << timer.seconds << "(s)" << endl;
	cout << "Version: " << version.name << ' ' << version.arr[0] << '.' << version.arr[1] << '.' << version.arr[2] << endl;
	cout << "------------------------------------------------------" << endl;
}




void WorkingProgram::operator = (WorkingProgram& obj) {
	this->name = obj.name;
	this->publisher = obj.publisher;
	this->RAM = obj.RAM;
	this->hDisk = obj.hDisk;
	this->timer = obj.timer;
	this->version = obj.version;
}

bool WorkingProgram::operator == (WorkingProgram& obj) {
	if (this->name != obj.name) {
		return false;
	}
	if (this->publisher != obj.publisher) {
		return false;
	}
	if (this->RAM != obj.RAM) {
		return false;
	}
	if (this->hDisk != obj.hDisk) {
		return false;
	}
	if (this->timer.hours != obj.timer.hours) {
		return false;
	}
	if (this->timer.minutes != obj.timer.minutes) {
		return false;
	}
	if (this->timer.seconds != obj.timer.seconds) {
		return false;
	}
	if (this->version.name != obj.version.name) {
		return false;
	}
	for (int i = 0; i < 3; i++) {
		if (this->version.arr[i] != obj.version.arr[i]) {
			return false;
		}
	}
	return true;
}

istream& operator >> (istream &in, WorkingProgram &obj) {
	in.ignore();
	cout << "Enter name of program:" << endl;
	getline(in, obj.name);

	cout << "Enter name of publisher(if you don't know, enter 'Unknown'):" << endl;
	getline(in, obj.publisher);

	cout << "Enter amount of consumed RAM(Mb):" << endl;
	in >> obj.RAM;

	cout << "Enter ocupied amount of hard disk memory(Gg):" << endl;
	in >> obj.hDisk;

	cout << "Enter time of work:" << endl;
	cout << "Hours - ";
	in >> obj.timer.hours;

	while (true) {
		cout << "(0-59)Minutes - ";
		in >> obj.timer.minutes;
		if (obj.timer.minutes < 0 || obj.timer.minutes > 60) {
			cout << "You must enter from 0 to 59 minutes, try again" << endl;
		}
		else {
			break;
		}
	}
	while (true) {
		cout << "(0-59)Seconds - ";
		in >> obj.timer.seconds;
		if (obj.timer.seconds < 0 || obj.timer.seconds > 60) {
			cout << "You must enter from 0 to 59 minutes, try again" << endl;
		}
		else {
			break;
		}
	}
	in.ignore();
	cout << "Enter version:" << endl;
	cout << "Name of version - ";
	getline(in, obj.version.name);
	cout << "First number - ";
	in >> obj.version.arr[0];
	cout << "Second number - ";
	in >> obj.version.arr[1];
	cout << "Third number - ";
	in >> obj.version.arr[2];
	return in;
}

ostream& operator<< (ostream &out, WorkingProgram &obj) {
	out << "Name of program: " << obj.name << endl;
	out << "Publisher: " << obj.publisher << endl;
	out << "Amount of consumed RAM(Mb): " << obj.RAM << endl;
	out << "Ocupied amount of hard disk memory(Gb): " << obj.hDisk << endl;
	out << "Time of work: " << obj.timer.hours << "(h) " << obj.timer.minutes << "(m) " << obj.timer.seconds << "(s)" << endl;
	out << "Version: " << obj.version.name << ' ' << obj.version.arr[0] << '.' << obj.version.arr[1] << '.' << obj.version.arr[2] << endl;
	out << endl;
	return out;
}