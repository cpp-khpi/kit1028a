#pragma once
#include "TestsInfo.h"

class StudentsWorks {
private:
	int SIZE;
	TestsInfo new_student;
	TestsInfo *list;

public:
	StudentsWorks(int SIZE);
	~StudentsWorks();

	int getSIZE()const;
	void setNewStud();
	void addStud(const int num);
	void removeStud(const int num);

	void getStud(const int num)const;
	void getNewStud()const;
	void showAll()const;
};
