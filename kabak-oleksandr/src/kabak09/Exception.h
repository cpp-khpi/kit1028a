
#pragma once
#include <exception>
#include <string>
#include <iostream>

using std::exception;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Exception : public exception {
private:
	string err;
	string funcErr;
public:
	Exception();
	Exception(string err, string funcErr);
	string getFunc();
	virtual const char* what() const noexcept override;
};