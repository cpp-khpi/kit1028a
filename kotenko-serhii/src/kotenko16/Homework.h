#pragma once

#include "IndependentsWork.h"

class Homework : public IndependentsWork {
private:
	int homework_count;
public:
	friend std::ostream& operator<< (std::ostream &out, const Homework &obj);
	friend std::istream& operator>> (std::istream &in, Homework &obj);
	bool operator< (const Homework obj);
	bool operator> (const Homework obj);
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
	* Homework class constructors.
	*/
	Homework();
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param amount initializes Homework::amount.
	* @param written initializes Homework::written.
	* @param mark initializes Homework::mark.
	* @param person initializes Homework::person.
	* @param homework_count initializes Homework::homework_count.
	*/
	Homework(int amount, int written, int mark, int homework_count);
	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param obj: its fields initialize fields current object.
	*/
	Homework(const Homework &obj);
	/**
	* Get copy of field.
	* Return current value.
	*/
	int get_homework();	
	/**
	* Virtual function of generating values.
	*/
	void generation_values(std::string s);
	/**
	* Assignment field value.
	*/
	void set_data(int homework_count, int amount, int written, int mark);
	/**
	* Homework class destructor.
	*/
	~Homework();
};

