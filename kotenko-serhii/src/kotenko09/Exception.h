#pragma once
#include <exception>
#include <string>

class Exception : public std::exception {
private:
	std::string error;
	std::string func_error;
public:
	Exception();
	Exception(std::string error, std::string func_error);
	std::string get_func();
	virtual const char* what() const noexcept override;
};

struct Arrays {
	size_t size;
	int* array_of_sizes = nullptr;
	int** array = nullptr;
};