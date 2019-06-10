#pragma once

#include "Textbook.h"

class English : public Textbook {
private:
	int amount_of_exercises;
public:
	friend ostream& operator<< (ostream &out, const English &obj);
	friend ostream& operator<< (ostream &out, const English *obj);
	friend istream& operator>> (istream &in, English &obj);
	friend istream& operator>> (istream &in, English *obj);
	bool operator< (const English obj);
	bool operator> (const English obj);
	/**
	* English class constructors.
	*/
	English();
	/**
	* Constructor with parameters.
	* Used initialization lists.
	* @param pages initializes English::pages.
	* @param grade initializes English::grade.
	* @param cost initializes English::cost.
	* @param author initializes English::author.
	* @param amount_of_examples initializes English::amount of examples.
	*/
	English(int pages, int grade, int cost, string author, int amount_of_exercises);
	/**
	* Copie-constructor.
	* Used initialization lists.
	* @param obj: its fields initialize fields current object.
	*/
	English(const English &obj);
	/**
	* Get copy of field.
	* Return current value.
	*/
	/**
	* English class destructor.
	*/
	~English();
	int getAmountOfExercises();
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
	void setInfo(int amount_of_exercises, int pages, int grade, int mark, string author);
};
