#pragma once
#include "Header.h"

class workingProgram {
private:
	string name;
	float opMemoryMb;
	float memoryGb;
	float timeWorkMin;
public:
	workingProgram();
	void const print();

	void setName(string);
	void setOpMemoryMb(float);
	void setMemoryGb(float);
	void setTimeWorkMin(float);

	string getName(string);
	float getOpMemoryMb(float);
	float getMemoryGb(float);
	float getTimeWorkMin(float);
};
