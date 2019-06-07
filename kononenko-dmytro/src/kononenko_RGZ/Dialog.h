/**
* @file Dialog.h
* Declaration of Dialog class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/

#pragma once
#include "Controler.h"
#include "InfoWork.h"
#include "CourseWork.h"
#include "DetailInfo.h"


class Dialog {
private:
	Controler obj; ///< object of class Controler to call methods of class
public:
	/**
	* Function Displays % of graduate work compared to undergraduate work.
	*/
	void getRate();
	/**
	* The function sends a request for the data to be added, and then uses the method to add it.
	*/
	void Add();
	/**
	* The function sends a request for the data to be deleted, and then uses the method to delete it.
	*/
	void Del();
	/**
	* The function outputs to the file and to the console the data contained in the array.
	*/
	void print();
	/**
	* The function sends a request for the data to create array, such as size and name of file.
	*/
	void createArr();
	/**
	* The function sends a request for the data to sort array.
	*/
	void sortArr();
};