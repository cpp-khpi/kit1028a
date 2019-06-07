/**
* @file TestPhoneArray.h
* Declaration TestPhoneArray class.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.06.06
*/

#pragma once

#include "PhoneArray.h"

/**
* Description of the TestPhoneArray Test Class with its fields and methods.
* Its main function is to test the methods of the PhoneDatabase class.
* Used Javadoc style comments to handle Doxygen.
*/
class TestPhoneArray {
private:
	/** Object of testing class */
	PhoneArray testingPhoneArray;

	/** 
	* Test method for PhoneArray::addPhone.
	* @return the status of the function PhoneArray::addPhone.
	*/
	bool testAddPhone();

	/**
	* Test method for PhoneArray::removePhone () function at
	* remove the item from the end.
	* @return the status of the PhoneArray::removePhone () function at
	* remove the item from the end.
	*/
	bool isRemoveFromEnd();

	/**
	* Test method for PhoneArray::removePhone () function at
	* remove the element from the beginning.
	* @return the status of the PhoneArray::removePhone () function at
	* remove the element from the beginning.
	*/
	bool isRemoveFromBegin();

	/** 
	* Test method for PhoneArray::removePhone.
	* @return the status of the function PhoneArray::removePhone.
	*/
	bool testRemovePhone();
public:
	/** 
	* The method of calling all the functions of the class TestPhoneArray.
	* @return the status of all functions of the PhoneDatabase class.
	*/
	bool testAll();
};
