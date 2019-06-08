#pragma once

#include <iostream>
#include <string>
#include <exception>

class MyException : public std::exception {
private:
	std::string error;
public:
	MyException(std::string error);
	const char* what() const noexcept;
};