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
	void show();
	
	void setName(string name);
	void setPublisher(string publisher);
	void setHDisk(float hDisk);
	void setVersion(Version version);

	string getName();
	string getPublisher();
	float getHDisk();
	Version getVersion();
};