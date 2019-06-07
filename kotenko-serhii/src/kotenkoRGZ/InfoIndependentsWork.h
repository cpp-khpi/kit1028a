#pragma once

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>
#include <regex>

class InfoIndependentsWork {
protected:
	int amount;
	int written;
	int mark;
	std::string person;
public:
	/**
	* InfoIndependentsWork class constructors.
	*/
	InfoIndependentsWork();
	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param obj: its fields initialize fields current object.
	*/
	InfoIndependentsWork(const InfoIndependentsWork &obj);
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param amount initializes InfoIndependentsWork::amount.
	* @param written initializes InfoIndependentsWork::written.
	* @param mark initializes InfoIndependentsWork::mark.
	* @param person initializes InfoIndependentsWork::person.
	*/
	InfoIndependentsWork(int amount, int written, int mark, std::string person);
	/**
	* Operator overload = .
	*/
	InfoIndependentsWork& operator= (const InfoIndependentsWork &obj);
	/**
	* Overloading of the output operator at the pointer and without. 
	*/
	friend std::ostream& operator<< (std::ostream &out, const InfoIndependentsWork &obj);
	friend std::ostream& operator<< (std::ostream &out, const InfoIndependentsWork *obj);
	/**
	* Overloading of the input operator at the pointer and without. 
	*/
	friend std::istream& operator>> (std::istream &in, InfoIndependentsWork &obj);
	friend std::istream& operator>> (std::istream &in, InfoIndependentsWork *obj);
	/**
	* Virtual data entry and output functions and file recording. 
	*/
	virtual void input() = 0;
	virtual void output() = 0;
	virtual void output_to_file(std::ofstream& file) = 0;
	/**
	* Virtual function to generate values.
	*/
	virtual void generation_values(std::string s);
	/**
	* Get copy of field.
	* Return current value.
	*/
	int get_amount();
	int get_written();
	int get_mark();
	std::string get_person();
	/**
	* Assignment field value.
	*/
	void set_data(int amount, int written, int mark, std::string person);
	/**
	* InfoIndependentsWork class destructor.
	*/
	~InfoIndependentsWork();
};