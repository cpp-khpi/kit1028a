#pragma once

#include "Header.h"

class workingProgram {
private:
	char* name;
	char* publisher;
	float opMemoryMb;
	float memoryGb;
	float timeWorkMin;
public:
	workingProgram();
	workingProgram(char *name, char* publisher, float opMemoryMb, float memoryGb, float timeWorkMin);
	workingProgram(const workingProgram&);
	~workingProgram();

	void const print();

	void setName(char*);
	void setPublisher(char*);
	void setOpMemoryMb(float);
	void setMemoryGb(float);
	void setTimeWorkMin(float);

	char* getName();
	char* getPublisher();
	float getOpMemoryMb();
	float getMemoryGb();
	float getTimeWorkMin();
};
