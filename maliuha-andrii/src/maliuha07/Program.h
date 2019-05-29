#pragma once
#include "Main.h"

class Program {
public:
	virtual string print() = 0;

	virtual void setObj(string &info) = 0;

	virtual void setName(string name) = 0;
	virtual void setPublisher(string publisher) = 0;
	virtual void setRAM(float RAM) = 0;
	virtual void setHDisk(float hDisk) = 0;
	virtual void setTimer(Time *timer) = 0;
	virtual void setVersion(Version version) = 0;

	virtual string getName() = 0;
	virtual string getPublisher() = 0;
	virtual float getRAM() = 0;
	virtual float getHDisk() = 0;
	virtual Time *getTimer() = 0;
	virtual Version getVersion() = 0;
};