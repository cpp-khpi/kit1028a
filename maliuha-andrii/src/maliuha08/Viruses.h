#pragma once
#include "Main.h"

class Viruses :public WorkingProgram {
private:
	int amountV;
public:
	Viruses();
	void setAmountV(int amountV);
	int getAmountV();
	

	void operator = (Viruses &obj);
	bool operator== (Viruses &obj);
	friend ostream& operator<< (ostream &out, Viruses &obj);
};