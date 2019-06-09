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