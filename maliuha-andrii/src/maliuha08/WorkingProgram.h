#pragma once
#include "Main.h"



class WorkingProgram {
protected:
	string name;
	string publisher;
	float RAM;
	float hDisk;
	Time timer;
	Version version;
public:
	WorkingProgram();
	string print();

	void setObj(string &info);
	void setName(string name);
	void setPublisher(string publisher);
	void setRAM(float RAM);
	void setHDisk(float hDisk);
	void setTimer(Time timer);
	void setVersion(Version version);

	string getProgram();
	string getPublisher();
	float getRAM();
	float getHDisk();
	Time getTimer();
	Version getVersion();

	void operator = (WorkingProgram &obj);
	bool operator == (WorkingProgram &obj);
	friend istream& operator>> (istream &in, WorkingProgram &obj);
	friend ostream& operator<< (ostream &in, WorkingProgram &obj);
};

