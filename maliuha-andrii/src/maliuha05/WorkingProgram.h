#pragma once
#include "Main.h"



class WorkingProgram {
private:
	string program;
	string publisher;
	float RAM;
	float HDisk;
	float timeWorkMin;

public:
	WorkingProgram();
	string print();

	void setObj(string &info);
	void setName(string name);
	void setPublisher(string publisher);
	void setOpMemoryMb(float opMemoryMb);
	void setMemoryGb(float memoryGd);
	void setTimeWorkMin(float timeWorkMin);

	string getProgram();
	string getPublisher();
	float getRAM();
	float getMemoryGb();
	float getTimeWorkMin();
};

