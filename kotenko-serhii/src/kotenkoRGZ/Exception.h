#pragma once
#include <exception>
#include <string>

class Exception : public std::exception {
private:
	std::string error;
	std::string func_error;
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
	Exception(std::string error, std::string func_error);
	/**
	* Get copy of field.
	* Return current value.
	*/
	std::string get_func();
	/**
	* Makes information about the error.
	*/
	virtual const char* what() const noexcept override;
};
