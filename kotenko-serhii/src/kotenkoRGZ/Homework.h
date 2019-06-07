#pragma once

#include "InfoIndependentsWork.h"

class Homework : public InfoIndependentsWork {
private:
	int homework_count;
public:
	friend std::ostream& operator<< (std::ostream &out, const Homework &obj);
	friend std::ostream& operator<< (std::ostream &out, const Homework *obj);
	friend std::istream& operator>> (std::istream &in, Homework &obj);
	friend std::istream& operator>> (std::istream &in, Homework *obj);
	bool operator< (const Homework obj);
	bool operator> (const Homework obj);
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
	Homework(int amount, int written, int mark, std::string person, int homework_count);
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
	virtual void generation_values(std::string s) override;
	/**
	* Virtual data entry and output functions and file recording. 
	*/
	virtual void input() override;
	virtual void output() override;
	virtual void output_to_file(std::ofstream& file) override;	
	/**
	* Assignment field value.
	*/
	void set_data(int homework_count, int amount, int written, int mark, std::string person);
	/**
	* InfoIndependentsWork class destructor.
	*/
	~Homework();
};

