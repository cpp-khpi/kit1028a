#pragma once
#include <exception>
#include <string>

using std::string;
using std::exception;

class Exception : public exception {
private:
	string error;
	string func_error;
public:
	/**
	* Exception class constructors.
	*/
	Exception();
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param error initializes Exception::error.
	* @param func_error initializes Exception::func_error.
	*/
	Exception(string error, string func_error);
	/**
	* Get copy of field.
	* Return current value.
	*/
	string getFunc();
	/**
	* Makes information about the error.
	*/
	virtual const char* what() const noexcept override;
};
