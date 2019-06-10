/**
* @file StudentsWorks.h
* File assignment				| Header file with StudentsWorks class
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/

#pragma once
#include "TestsInfo.h"

class StudentsWorks{
	
	public:
		StudentsWorks(string s);
		~StudentsWorks();

		int getSIZE();

		void infoWorks(const int num);

		void addStud(const int num);
		void removeStud(const int num);
		void sortMarkStud(bool(*comp)(int x, int y));

		void getStud(const int num)const;
		void getNewStud();
		void setNewStud();

		void showAll()const;
		void showAll2()const;


	private:
		int SIZE;					// Group size
		TestsInfo newStudent;	    // New Student
		TestsInfo* list;			// Group
	};

