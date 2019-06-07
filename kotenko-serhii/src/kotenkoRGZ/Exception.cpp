#include"Exception.h"

Exception::Exception() : error(), func_error() {
}

Exception::Exception(std::string error, std::string func_error) : error(error), func_error(func_error) {
}

std::string Exception::get_func() {
	return func_error; 
}

const char* Exception::what() const noexcept {
	return error.c_str();
}