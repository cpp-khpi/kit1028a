#pragma once

#include "InfoIndependentsWork.h"
class Classwork : public InfoIndependentsWork {
private:
	int classwork_count;
public:
	friend std::ostream& operator<< (std::ostream &out, const Classwork &obj);
	friend std::ostream& operator<< (std::ostream &out, const Classwork *obj);
	friend std::istream& operator>> (std::istream &in, Classwork &obj);
	friend std::istream& operator>> (std::istream &in, Classwork *obj);
	bool operator< (const Classwork obj);
	bool operator> (const Classwork obj);
	/**
	* Classwork class constructors.
	*/
	Classwork();
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param amount initializes Classwork::amount.
	* @param written initializes Classwork::written.
	* @param mark initializes Classwork::mark.
	* @param person initializes Classwork::person.
	* @param classwork_count initializes Classwork::classwork_count.
	*/
	Classwork(int amount, int written, int mark, std::string person, int classwork_count);
	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param obj: its fields initialize fields current object.
	*/
	Classwork(const Classwork &obj);
	/**
	* Get copy of field.
	* Return current value.
	*/
	int get_classwork();
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
	void set_data(int classwork_count, int amount, int written, int mark, std::string person);
	/**
	* Classwork class destructor.
	*/
	~Classwork();
};


