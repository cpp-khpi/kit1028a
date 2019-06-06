#pragma once
#include "Government.h"

class Monarchy : public Government
{
private:
	string monarchy;
public:
	void setMonarchy(string monarchy);
	void Info() override;
	string getMonarchy();
};