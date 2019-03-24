#pragma once

#include "Header.h"

class workingProgram {
private:
	string name;
	string publisher;
	float opMemoryMb;
	float memoryGb;
	float timeWorkMin;
public:
	workingProgram();

	stringstream print();

	void setName(string);
	void setPublisher(string);
	void setOpMemoryMb(float);
	void setMemoryGb(float);
	void setTimeWorkMin(float);

	string getName();
	string getPublisher();
	float getOpMemoryMb();
	float getMemoryGb();
	float getTimeWorkMin();
};
