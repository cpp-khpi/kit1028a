/**
* @file InfoWork.h
* Declaration of InfoWork class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/

#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
using namespace std;

class InfoWork {
protected:
	int pages; ///< size of student`s work
	int mark; ///< mark which student got
	int type; ///< type of work such as (Bacalavr or Magistr)
	string name; ///< student`s name
public:
	/**
	* Default constructor
	* Used initialization lists.
	*/
	InfoWork();
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param size initializes InfoWork::pages.
	* @param points initializes InfoWork::mark.
	* @param type initializes InfoWork::type.
	* @param creator initializes InfoWork::name.
	*/
	InfoWork(int size, int points, int type, string creator);
	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param obj: its fields initialize fields current object.
	*/
	InfoWork(const InfoWork &obj);
	/**
	* Destructor.
	*/
	~InfoWork();
	/**
	* Set the value of the variable InfoWork::pages.
	* Set the value of the variable InfoWork::mark.
	* Set the value of the variable InfoWork::type.
	* Set the value of the variable InfoWork::name.
	* @param pages is assigned the InfoWork::pages field.
	* @param mark is assigned the InfoWork::mark field.
	* @param type is assigned the InfoWork::type field.
	* @param name is assigned the InfoWork::name field.
	*/
	void set_n(int pages, int mark, int type, string name);
	/**
	* Virtual function to generate values.
	*/
	virtual void set(string creator);
	/**
	* Get copy of field InfoWork::pages.
	* @return current value InfoWork::pages.
	*/
	int getPages();
	/**
	* Get copy of field InfoWork::mark.
	* @return current value InfoWork::mark.
	*/
	int getMark();
	/**
	* Get copy of field InfoWork::type.
	* @return current value InfoWork::type.
	*/
	int getType();
	/**
	* Get copy of field InfoWork::name.
	* @return current value InfoWork::name.
	*/
	string getName();
	/**
	* Virtual data entry and output functions and file recording.
	*/
	virtual void input() = 0;
	virtual void output() = 0;
	virtual void output_to_file(ofstream& file) = 0;
	/**
	* Overloaded comparison operator.
	* @param obj its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator== (const InfoWork &obj);
	/**
	* Overloaded comparison operator.
	* @param obj: its fields compare with fields current object.
	* @return result of comparison.
	*/
	bool operator!= (const InfoWork &obj);
	InfoWork& operator= (const InfoWork &obj);
	/**
	* Overloaded output operator.
	* @param out - reference to output stream.
	* @param obj - reference to InfoWork object.
	* @return reference to output stream.
	*/
	friend ostream& operator<< (ostream &out, const InfoWork &obj);
	/**
	* Overloaded input operator.
	* @param in - reference to input stream.
	* @param obj - reference to InfoWork object.
	* @return reference to input stream.
	*/
	friend istream& operator>> (istream &in, InfoWork &obj);
};