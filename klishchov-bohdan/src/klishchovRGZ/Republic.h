/**
* @file Republic.h
* Declaration of Republic class.
* @author Klishchov Bohdan
* @version 1.0
* @date 2019.09.06
*/

#pragma once
#include "Country.h"

class Republic : public Country {
private:
	string president; //Строкове поле республіки(Ім'я президента)
public:
	/**
	* Function getter for president.
	*/
	string getPresident();
	/**
	* Function setter.
	* \param string president.
	*/
	void setPresident(string president);
	/**
	* Overloaded function.
	*/
	void Info() override;
};