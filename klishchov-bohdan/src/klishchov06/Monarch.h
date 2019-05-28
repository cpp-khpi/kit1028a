#pragma once
#include "Country.h"

class Monarch : public Country {			// класс наследник
private:
	std::string kind;
public:
	std::string getKind();
	void setKind(std::string kind);

};
