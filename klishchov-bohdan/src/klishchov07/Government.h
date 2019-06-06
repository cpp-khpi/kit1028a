#pragma once
#include "Country.h"

class Government : public Country
{
private:
	string gover;
public:
	void setGover(string gover);
	void Info() override;
	string getGover();
};