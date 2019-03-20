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
	void setStud(const int num);
	void del_Stud(const int num);
	void add_Stud(const int num);

	void print_stud(const int num)const;
	void print_new_stud()const;
	void print_all()const;
};
