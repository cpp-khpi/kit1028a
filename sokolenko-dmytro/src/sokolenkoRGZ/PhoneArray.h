/**
* @file PhoneArray.h
* Declaration PhoneArray class.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.06.06
*/

#pragma once

#include "Phone.h"
#include "IosPhone.h"
#include "AndroidPhone.h"
#include "MyException.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::swap;
using std::function;

/**
* Description of the PhoneArray class with its fields and methods.
* Contains an array of Phone objects and the size of this array.
* Used Javadoc style comments to handle Doxygen.
*/
class PhoneArray {
private:
	/** Size of Phone array  */
	size_t size;
	/** Pointer to Phone pointer's array. */
	Phone** data;
public:
	/**
	* Default constructor
	* Used initialization lists.
	*/
	PhoneArray();

	/**
	* Destructor. Releasing the allocated memory for an array.
	*/
	~PhoneArray();

	/**
	* Access to the desired array element by index.
	* @return reference to an object with the i-th index.
	*/
	Phone& operator[] (const unsigned int index);

	/**
	* Output operator that outputs the number of rows
	* (which is the size of the array) with information about the objects.
	* @param out - link to output stream
	* @param outputPhoneArray - link to the PhoneArray object.
	* @return link to output stream.
	*/
	friend ostream& operator<<(ostream& out, const PhoneArray& outputPhoneArray);

	/**
	* Assigning PhoneArray classes.
	* @param newSize assigns the PhoneArray::size field.
	* @param newPhoneArray the transferred array is executed
	* copy the objects of the Class class into the current array.
	*/
	void setPhoneArrayInfo(size_t newSize, Phone** newPhoneArray);

	/**
	* A method of comparing a separate array of pointers to the Phone and array,
	* what is the PhoneArray class object field.
	* @param otherPhoneArr - pointer to the comparable array.
	* @param otherSize - the size of the array.
	* @return the status of pointers to array objects
	* Phone class: level or not.
	*/
	bool comparisonPhoneArray(Phone** otherPhoneArr, size_t otherSize) const;

	/**
	* Get copy of field PhoneArray::size.
	* @return current value PhoneArray::size.
	*/
	size_t getSize() const;

	/**
	* Reading from the file information about the array of objects.
	* @param fileName - the file name string.
	*/
	void readFromFile(string fileName);

	/**
	* Write in the file information from the PhoneArray :: data array.
	* @param fileName - the file name string.
	*/
	void writeToFile(string fileName);

	/**
	* Adding a Class object to a
	* the PhoneArray :: data array.
	* @param addedPhone - pointer to add object.
	*/
	void addPhone(Phone* addedPhone);

	/**
	* Reading the size of the index of the array object being processed.
	* @return read the index value.
	*/
	int inputIndex() const;

	/**
	* Removing the object from the Phone class with
	* the PhoneArray :: data array.
	* @param index - the index of the object to be deleted.
	*/
	void removePhone(const unsigned int index);

	/**
	* Display information about all
	* elements of the PhoneArray :: data array.
	*/
	void showAll() const;

	/**
	* Getting a link to an item in an array of objects
	* Class Phone with the lowest pixel density.
	* @return gain on the array element.
	*/
	Phone* getSmallestResolutPhone() const;

	/**
	* A method that sorts an array of elements
	* type Phone on the basis of which the pointer to the function is passed.
	* @param comparFunc: A logical function that defines
	* sorting options.
	*/
	void sort(function<bool(Phone*, Phone*)> comparFunc);
};
