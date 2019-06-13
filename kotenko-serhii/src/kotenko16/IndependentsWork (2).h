#pragma once

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdio>
#include <regex>

class IndependentsWork {
protected:
	int amount;
	int written;
	int mark;
public:
	/**
	* InfoIndependentsWork class constructors.
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
	*/
	IndependentsWork(int amount, int written, int mark);
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
	/**
	* Overloading of the new operator.
	*/
	void* operator new(size_t size);
	/**
	* Overloading of the delete operator.
	*/
	void operator delete(void *pointer);
	/**
	* Overloading of the new[] operator.
	*/
	void* operator new[](size_t size);
	/**
	* Overloading of the delete[] operator.
	*/
	void operator delete[](void *pointer);
	/**
	* Function to generate values.
	*/
	void generation_values();
	/**
	* Get copy of field.
	* Return current value.
	*/
	int get_amount();
	int get_written();
	int get_mark();
	/**
	* Assignment field value.
	*/
	void set_data(int amount, int written, int mark);
	/**
	* IndependentsWork class destructor.
	*/
	~IndependentsWork();
};