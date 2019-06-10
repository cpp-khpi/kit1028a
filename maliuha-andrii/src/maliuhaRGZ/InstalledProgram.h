#pragma once
#include "Main.h"


class InstalledProgram : public Program{
private:
	string name;
	string publisher;
	float hDisk;
	Version version;
public:
	InstalledProgram();
	string print();
	void setInfoObj(string &info);
	void setObj(string &info);
	const void show();
	
	void setName(string name);
	void setPublisher(string publisher);
	void setHDisk(float hDisk);
	void setVersion(Version version);

	string getName();
	string getPublisher();
	float getHDisk();
	Version getVersion();

	InstalledProgram& operator= (const InstalledProgram &obj);
	friend bool operator< (const InstalledProgram &obj1, const InstalledProgram &obj2);
	friend istream& operator>> (istream &in, InstalledProgram &obj);
	friend ostream& operator<< (ostream &in, const InstalledProgram &obj);
};