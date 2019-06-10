/**
* @file Exception.cpp
* File assignment				| Ñlass methods
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/
#include"Exception.h"

Exception::Exception() : err(), funcErr() {
}

Exception::Exception(string err, string funcErr) : err(err), funcErr(funcErr) {
}

std::string Exception::getFunc() {
	return funcErr;
}

const char* Exception::what() const noexcept {
	return err.c_str();
}