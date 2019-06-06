#pragma once
#include "Country.h"

class Area : public Country
{
private:
	int area;
public:
	void setArea(int area);
	void Info() override;
	int getArea();
};