/**
* @file Parlament.cpp
* Implementation of all functions of Parlament class.
* @author Klishchov Bohdan
* @version 1.0
* @date 2019.09.06
*/

#include "Parlament.h"

string Parlament::getParlament() {
	return this->parlament;
}
void Parlament::setParlament(string parlament) {
	this->parlament = parlament;
}