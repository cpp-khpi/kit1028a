/**
* @file Controler.h
* Declaration of Controler class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/

#pragma once
#include "InfoWork.h"

/**
* Declaration of functor.
*/
class ForClass {
public:
	bool operator() (int obj, int obj2)
	{
		return obj < obj2;
	}
};

class Controler {
private:
	int size; ///< size of array
	InfoWork **qual; ///< array 
public:
	/**
	* Default constructor
	* Used initialization lists.
	*/
	Controler();
	/**
	* The function determines the % of master's works compared to bachelor's works.
	*/
	float rate();
	/**
	* Function which set size of array.
	*/
	void setSize(int size);
	/**
	* Function which print array information in console.
	*/
	void print();
	/**
	* Function which add element to array.
	* @param newWork: new obj to be add.
	*/
	void addElem(InfoWork* newWork);
	/**
	* Function which delete element from array.
	* @param index: index of element to delete.
	*/
	void delElem(int l);
	/** method of comparing two arrays
		* @param ArrayToTest - pointer to the comparable array.
		* @param otherSize - the size of the array.
		* @return the status of pointers to array objects
	*/
	bool comparisonArray(InfoWork **ArrayToTest, size_t otherSize) const;
	/**
		* @param newSize assigns the InfoWork::size field.
		* @param newArray the transferred array is executed
		* copy the objects of the Class class into the current array.
	*/
	void setArray(size_t newSize, InfoWork** newArray);

	/**
	* Function which print element by index.
	* @param index: index of element to print.
	*/
	void geByIndex(int index);
	/**
	* Function which take information from file.
	* @param Size: number of elements to scun.
	* @param fName: name of the file where program will take information.
	*/
	void readFromFile(int Size,string fName);
	/**
	* Function which print array information in file.
	* @param fName: name of the file where program will print
	*/
	void writeToFile(string fName);
	/**
	* Function which sort array by mark of work.
	*/
	void sortByMark();
	/**
	* Function which sort array by size of work.
	*/
	void sortBySize();
	/**
	* Function which sort array by type of work.
	*/
	void sortByType();
	/**
	* Destructor.
	*/
	~Controler();
};