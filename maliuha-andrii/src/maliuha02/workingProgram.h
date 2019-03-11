#pragma once

#include "Header.h"

class workingProgram {
private:
	char* name;
	float opMemoryMb;
	float memoryGb;
	float timeWorkMin;
public:
	workingProgram();
	workingProgram(char *name, float opMemoryMb, float memoryGb, float timeWorkMin);
	workingProgram(const workingProgram&);

	void const print();

	void setName(char*);
	void setOpMemoryMb(float);
	void setMemoryGb(float);
	void setTimeWorkMin(float);

	char* getName(char*);
	float getOpMemoryMb(float);
	float getMemoryGb(float);
	float getTimeWorkMin(float);

	~workingProgram();
};
