#include "InstalledProgram.h"

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
	stringstream infoObj;
	Version version;
	cout << "Enter name of program:" << endl;
	getline(cin, name);
		
	cout << "Enter name of publisher(if you don't know, enter 'Unknown'):" << endl;
	getline(cin, publisher);

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



istream& operator >> (istream &in, InstalledProgram &obj) {
	in.ignore();
	cout << "Enter name of program:" << endl;
	getline(in, obj.name);

	cout << "Enter name of publisher(if you don't know, enter 'Unknown'):" << endl;
	getline(in, obj.publisher);

	cout << "Enter ocupied amount of hard disk memory(Gg):" << endl;
	in >> obj.hDisk;
	
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

ostream& operator<< (ostream &out, const InstalledProgram &obj) {
	out << "Name of program: " << obj.name << endl;
	out << "Publisher: " << obj.publisher << endl;
	out << "Ocupied amount of hard disk memory(Gb): " << obj.hDisk << endl;
	out << "Version: " << obj.version.name << ' ' << obj.version.arr[0] << '.' << obj.version.arr[1] << '.' << obj.version.arr[2] << endl;
	return out;
}

bool operator< (const InstalledProgram &obj1, const InstalledProgram &obj2) {
	return obj1.hDisk < obj2.hDisk;
}

InstalledProgram& InstalledProgram::operator= (const InstalledProgram &obj) {
	this->name = obj.name;
	this->publisher = obj.publisher;
	this->hDisk = obj.hDisk;
	this->version.name = obj.version.name;
	this->version.arr[0] = obj.version.arr[0];
	this->version.arr[1] = obj.version.arr[1];
	this->version.arr[2] = obj.version.arr[2];
	return *this;
}