#pragma once
#include "Main.h"

class Program {
public:
	virtual string print() = 0;
	virtual void setObj(string &info) = 0;
	virtual void setInfoObj(string &info) = 0;
	virtual const void show() = 0;
	virtual string getName() = 0;
	virtual string getPublisher() = 0;
	virtual float getHDisk() = 0;
};