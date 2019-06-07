#pragma once
#include "Library.h"

class ElectronicTextbook :public Textbook {
private:
	string link;
public:
	string getLink();
	void setLink(string link);
};