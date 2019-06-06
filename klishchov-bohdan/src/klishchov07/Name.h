#pragma once
#include "Country.h"

class Name : public Country
{
	string name;
public:
	void setName(string name);
	void Info() override;
	string getName();
};