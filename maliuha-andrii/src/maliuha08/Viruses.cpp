#include "Main.h"


Viruses::Viruses() :amountV(0) {
}

void Viruses::setAmountV(int amountV) {
	this->amountV = amountV;
}

int Viruses::getAmountV() {
	return amountV;
}

bool Viruses::operator== (Viruses &obj) {
	if (this->amountV != obj.amountV) {
		return false;
	}
	return true;
}

ostream& operator<< (ostream &out, Viruses &obj) {
	out << obj.amountV;
	return out;
}

void Viruses::operator = (Viruses &obj) {
	this->amountV = obj.amountV;
}
