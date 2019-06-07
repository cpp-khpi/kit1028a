#include"MyException.h"

MyException::MyException() : 
	error(""), nameErrorFunc("") {}

MyException::MyException(string newError, string newNameErrorFunc) :
	error(newError), nameErrorFunc(newNameErrorFunc) {}

string MyException::getFunction() { return nameErrorFunc; }

const char* MyException::what() const noexcept 
{
	return error.c_str(); 
}