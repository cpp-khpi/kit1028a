/**
* @file Tester.h
* Declaration of Tester class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/
#pragma once
#include "InfoWork.h"
#include "Controler.h"

class Tester {
public:
	
	Controler testingArray; ///< array for testing
	/**
	* Test method for Controler::addElem.
	* @return the status of the function Controler::addElem.
	*/
	bool testAdd();

	/**
	* Test method for Controler::delEleme () function at
	* remove the item from the end.
	* @return the status of the Controler::delEleme () function at
	* remove the item from the end.
	*/
	bool isDelFromEnd();
	/**
	* Test method for Controler::delElem.
	* @return the status of the function Controler::delElem.
	*/
	bool testDel();
public:
	/**
	* The method of calling all the functions of the class Tester.
	* @return the status of all functions of the Tester class.
	*/
	bool testAll();
};
