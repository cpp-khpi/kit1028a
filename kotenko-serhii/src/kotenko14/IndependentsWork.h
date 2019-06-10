#pragma once

#include <iostream>
#include <ctime>
#include <string>

class IndependentsWork {
protected:
	int amount;
	int written;
	int mark;
	std::string person;
public:
	/**
	* IndependentsWork class constructors.
	*/
	IndependentsWork();
	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param obj: its fields initialize fields current object.
	*/
	IndependentsWork(const IndependentsWork &obj);
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param amount initializes IndependentsWork::amount.
	* @param written initializes IndependentsWork::written.
	* @param mark initializes IndependentsWork::mark.
	* @param person initializes IndependentsWork::person.
	*/
	IndependentsWork(int amount, int written, int mark, std::string person);
	/**
	* Operator overload = .
	*/
	IndependentsWork& operator= (const IndependentsWork &obj);
	/**
	* Overloading of the output operator.
	*/
	friend std::ostream& operator<< (std::ostream &out, const IndependentsWork &obj);
	/**
	* Overloading of the input operator.
	*/
	friend std::istream& operator>> (std::istream &in, IndependentsWork &obj);
	void generation_values(std::string s);
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
	* IndependentsWork class destructor.
	*/
	~IndependentsWork();
};