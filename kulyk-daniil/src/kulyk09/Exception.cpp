#include"Exception.h"

Exception::Exception(string error) : error(error) {
}

const char* Exception::what() const noexcept {
	return error.c_str();
}