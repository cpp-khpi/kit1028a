#pragma once
#include "MathTI.h"

class MathWorks
{
public:
	MathWorks(int SIZE);
	~MathWorks();

	int getSIZE();

	void infoArguments(const int num);

	void addStud(const int num);
	void removeStud(const int num);
	void sortMarkStud(bool(*comp)(int x, int y));

	void getStud(const int num)const;
	void getNewStud();
	void setNewStud();

	void showAll()const;

private:
	MathTI* list;
	MathTI newStudent;
	int SIZE;
};

