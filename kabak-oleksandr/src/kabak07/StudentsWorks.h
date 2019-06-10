/**
* @file StudentsWorks.h
* File assignment				| Header file with StudentsWorks class
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.06.06
*/

#pragma once

#include "EconomicTI.h"
#include "MathTI.h"

class StudentsWorks
{
private:
	int SIZE;					// Group size
	TestsInfo *newStudent;	    // New Student
	TestsInfo **list;			// Group

public:
	StudentsWorks(string s);
	~StudentsWorks();

	void setNewStud(string s);
	int  getSIZE();
	void infoWorks(const int num);

	void removeStud(const int num);
	void addStud(const int num);
	void sortMarkStud(bool(*comp)(int x, int y));

	void getStud(const int num)const;
	void getNewStud();
	void showAll()const;
	void showAll2()const;
};

