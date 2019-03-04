#pragma once
#include <iostream>
#include <ctime>

class InfoAuditoryLessons {
private:
	int type;
	int koltype;
	int students;
public:
	InfoAuditoryLessons();
	int getType();
	int getKoltype();
	int getStudents();
	void setData(int x, int y, int z);
};