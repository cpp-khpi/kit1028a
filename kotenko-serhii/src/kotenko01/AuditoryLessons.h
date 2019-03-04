#pragma once
#include "InfoAuditoryLessons.h"

class AuditoryLessons {
private:
	int size;
	InfoAuditoryLessons *arr;
public:
	void getSize(int s);
	void newArray();
	void print();
	void addElem();
	void deleteElem(int l);
	void getByIndex(int index);
	void deleteArray();
};
