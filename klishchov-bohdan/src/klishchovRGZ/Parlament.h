/**
* @file Parlament.h
* Declaration of Parlament class.
* @author Klishchov Bohdan
* @version 1.0
* @date 2019.09.06
*/

#pragma once
#include "Republic.h"

class Parlament : public Republic {
private:
	string parlament;
public:
	/**
	* Function to get information about parlament class.
	*/
	string getParlament();
	/**
	* Function setter.
	* \param string parlament.
	*/
	void setParlament(string parlament);
};