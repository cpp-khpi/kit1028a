#pragma once
#include "Country.h"

class Population : public Country
{
private:
	int popul;
public:
	void setPopul(int popul);
	void Info() override;
	int getPopul();
};