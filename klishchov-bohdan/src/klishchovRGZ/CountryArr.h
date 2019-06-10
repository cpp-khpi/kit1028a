/**
* @file CountryArr.h
* Declaration of StudentArr class.
* @author Klishchov Bohdan
* @version 1.0
* @date 2019.09.06
*/

#pragma once
#include "Republic.h"
#include "Information.h"


class CountryArr {
private:
	vector<Republic> republic;
	Information info;
public:

	/**
	* Function for writing information from file.
	*/
	void print();

	/**
	* Function to add element.
	* @param Republic republic.
	*/
	void addEl(Republic republic);

	/**
	* Function for delleting element.
	* @param int index.
	*/
	void deleteEl(int index);

	/**
	* Function that gets elements by index.
	* @param int index.
	*/
	void getByIndex(int index);

	/**
	* Function that calculating all.
	*/
	void CalculatePopulation();
	/**
	* Function which let us chose type of sort.
	* \param *comp, int x, int y.
	*/
	void sortArea(bool(*comp)(int x, int y));
};

