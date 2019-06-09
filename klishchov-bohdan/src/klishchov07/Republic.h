#pragma once
#include "Country.h"

class Republic : public Country {
private:
	string president;
public:
	string getPresident();
	void setPresident(string president);
	void Info() override;
};
