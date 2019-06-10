#pragma once

#include "Textbook.h"

class Algebra : public Textbook {
private:
	int amount_of_examples;
public:
	friend ostream& operator<< (ostream &out, const Algebra &obj);
	friend ostream& operator<< (ostream &out, const Algebra *obj);
	friend istream& operator>> (istream &in, Algebra &obj);
	friend istream& operator>> (istream &in, Algebra *obj);
	bool operator< (const Algebra obj);
	bool operator> (const Algebra obj);
	/**
	* Algebra class constructors.
	*/
	Algebra();
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param pages initializes Algebra::pages.
	* @param grade initializes Algebra::grade.
	* @param cost initializes Algebra::cost.
	* @param author initializes Algebra::author.
	* @param amount_of_examples initializes Algebra::amount of examples.
	*/
	Algebra(int pages, int grade, int cost, string author, int amount_of_examples);
	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param obj: its fields initialize fields current object.
	*/
	Algebra(const Algebra &obj);
	/**
	* Get copy of field.
	* Return current value.
	*/
	/**
	* Algebra class destructor.
	*/
	~Algebra();
	int getAmountOfExamples();
	/**
	* Virtual function of generating values.
	*/
	virtual void generateData(string s) override;
	/**
	* Virtual data entry and output functions and file recording.
	*/
	virtual void input() override;
	virtual void output() override;
	virtual void outputToFile(ofstream& file) override;
	/**
	* Assignment field value.
	*/
	void setInfo(int amount_of_examples, int pages, int grade, int mark, string author);
};

