#pragma once
#include <cstddef>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Teacher
{
private:
	string name;
public:
	~Teacher() {};
	Teacher();
	void setName(string tmp);
	string getName();
};

