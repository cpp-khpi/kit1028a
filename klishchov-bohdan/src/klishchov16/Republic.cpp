/**
* @file Republic.cpp
* Implementation of all functions of Republic class.
* @author Klishchov Bohdan
* @version 1.0
* @date 2019.09.06
*/
#include "Republic.h"

string Republic::getPresident() {
	return president;
}
void Republic::setPresident(string president) {
	this->president = president;
}

void Republic::Info() {
	cout << "The president is: " << president << endl;
}