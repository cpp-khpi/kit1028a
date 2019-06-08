#include "MyException.h"


MyException::MyException(std::string error): error(error) {}

const char* MyException::what() const noexcept {
	return error.c_str();
}

