#pragma once
#include "Main.h"



class WorkingProgram : public Program {
private:
	string name;
	string publisher;
	float RAM;
	float hDisk;
	Time *timer;
	Version version;
public:
	WorkingProgram();
	string print();

	void setObj(string &info);
	void setName(string name);
	void setPublisher(string publisher);
	void setRAM(float RAM);
	void setHDisk(float hDisk);
	void setTimer(Time *timer);
	void setVersion(Version version);

	string getName();
	string getPublisher();
	float getRAM();
	float getHDisk();
	Time *getTimer();
	Version getVersion();
};

