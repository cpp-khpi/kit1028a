/**
* @file Exception.h
* Declaration of Exception class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/

#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Exception
{
public:
	/**
	* Destructor.
	*/
	~Exception() {};
	/**
	* Default constructor
	* Used initialization lists.
	*/
	Exception() : msg(), file(), lineNum(), func() {};
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param msg initializes Exception::msg.
	* @param file initializes Exception::file.
	* @param lineNum initializes Exception::lineNum.
	* @param func initializes Exception::func.
	*/
	Exception(string pMsg, string pFile, int nLine, string funcName) : msg(pMsg), file(pFile), lineNum(nLine), func(funcName) {}
	/**
	* For output error.
	*/
	virtual string display() {
		ostringstream out;
		out << "Error: " << msg
			<< " Function: " << func
			<< endl;
		out << " @" << file << "-" << lineNum << endl;
		return out.str();
	}
protected:
	string msg;///< message about error
	string file;///< file where error occurred
	int lineNum;///< line in file where error occurred
	string func;///< func where error occurred
};