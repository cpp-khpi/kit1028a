#include"Exception.h"

Exception::Exception() : error(), func_error() {
}

Exception::Exception(string error, string func_error) : error(error), func_error(func_error) {
}

string Exception::getFunc() {
	return func_error;
}

const char* Exception::what() const noexcept {
	return error.c_str();
}