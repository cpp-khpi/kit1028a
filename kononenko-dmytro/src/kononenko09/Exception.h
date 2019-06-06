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
	Exception(string pMsg, string pFile, int nLine, string funcName) : msg(pMsg), file(pFile), lineNum(nLine), func(funcName) {}
	virtual string display() {
		ostringstream out;
		out << "Error: " << msg
			<< " Function: " << func
			<< endl;
		out << " @" << file << "-" << lineNum << endl;
		return out.str();
	}
protected:
	string msg;
	string file;
	int lineNum;
	string func;
};