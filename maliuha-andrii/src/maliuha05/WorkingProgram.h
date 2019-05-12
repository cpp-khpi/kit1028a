#pragma once
#include "Main.h"

class WorkingProgram {
private:
	string name;
	string publisher;
	float opMemoryMb;
	float memoryGb;
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

	string getName();
	string getPublisher();
	float getOpMemoryMb();
	float getMemoryGb();
	float getTimeWorkMin();
};
