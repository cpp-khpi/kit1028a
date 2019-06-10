/**
* @file Exception.h
* File assignment				| Header file with Exception class
* @author						| Kabak A. R.
* @version 1.0
* @date 2019.05.31
*/
#include <exception>
#include <string>

using std::string;
using std::exception;

class Exception : public std::exception {
private:
	string err;
	string funcErr;
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
	Exception(string err, string funcErr);
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