/**
* @file MyException.h
* Declaration MyException class.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.06.01
*/

#pragma once

#include <exception>
#include <string>

using std::string;
using std::exception;

/**
* Description of the MyException class with its fields and methods.
* Used Javadoc style comments to handle Doxygen.
*/
class MyException : public exception {
private:
	/** Error description. */
	string error;
	/** Function name where the error occurred */
	string nameErrorFunc;
public:
	/** 
	* Default constructor 
	* Used initialization lists.
	*/
	MyException();

	/** 
	* Used initialization lists.
	* @param newError initializes error.
	* @param newNameErrorFunc initializes nameErrorFunc.
	*/
	MyException(string newError, string newNameErrorFunc);

	/**
	* Receipt of function name where the error occurred.
	* @return function name where the error occurred
	*/
	string getFunction();

	/**
	* Makes information about the error.
	* @return C-style string with information about
	* error and functionw here the error occurred.
	*/
	virtual const char* what() const noexcept override;
};