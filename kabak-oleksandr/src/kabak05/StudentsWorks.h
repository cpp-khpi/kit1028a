/**
* @file StudentsWorks.h
* File assignment				| Header file with StudentsWorks class
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/

#pragma once
#include "TestsInfo.h"


/**
* A class containing an array of student works and the size of this array
*/
class StudentsWorks {
private:
	int SIZE;					// Group size
	TestsInfo newStudent;	    // New Student
	TestsInfo* list;			// Group

public:
	StudentsWorks(string s);
	~StudentsWorks();

	void setNewStud();
	int getSIZE();
	void infoWorks(const int num);

	void removeStud(const int num);
	void addStud(const int num);
	void sortMarkStud(bool(*comp)(int x, int y));

	void getStud(const int num)const;
	void getNewStud();
	void showAll()const;
	void showAll2()const;
};
