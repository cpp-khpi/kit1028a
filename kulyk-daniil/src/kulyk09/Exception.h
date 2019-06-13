#pragma once

#include <exception>
#include <string>

using std::string;
using std::exception;

class Exception : public exception {
private:
	string error;
public:
	Exception(std::string error);
	const char* what() const noexcept;
};