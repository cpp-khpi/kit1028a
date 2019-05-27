#include "PhoneOs.h"

PhoneOs::PhoneOs() :
	osTitle("") {}

PhoneOs::PhoneOs(string newTitle,
	unsigned int newPrice,
	unsigned int newSimNum,
	unsigned int newResolution,
	unsigned int newCapacity,
	string newOsTitle) :

	Phone(newTitle,
		newPrice, 
		newSimNum, 
		newResolution, 
		newCapacity),

	osTitle(newOsTitle) {}

PhoneOs::PhoneOs(const PhoneOs& copiedPhoneOs) :
	Phone(copiedPhoneOs.title,
		copiedPhoneOs.price,
		copiedPhoneOs.simCardsNumber,
		copiedPhoneOs.resolution,
		copiedPhoneOs.capacity),
	osTitle(copiedPhoneOs.osTitle) {}

PhoneOs::~PhoneOs() {}

PhoneOs& PhoneOs::operator= (const PhoneOs& copiedPhoneOs)
{
	if (this == &copiedPhoneOs) {
		return *this;
	}

	title = copiedPhoneOs.title;
	price = copiedPhoneOs.price;
	simCardsNumber = copiedPhoneOs.simCardsNumber;
	resolution = copiedPhoneOs.resolution;
	capacity = copiedPhoneOs.capacity;
	osTitle = osTitle;

	return *this;
}

void PhoneOs::setPhoneOsInfo(string newTitle,
	unsigned int newPrice,
	unsigned int newSimNum,
	unsigned int newResolution,
	unsigned int newCapacity,
	string newOsTitle)
{
	setPhoneInfo(newTitle, newPrice, newSimNum, newResolution, newCapacity);
	osTitle = newOsTitle;
}

string PhoneOs::phoneToString() const
{
	stringstream phoneStream;
	string phoneString;

	phoneStream << title << " | " << price << " | " << simCardsNumber << 
		" | " << resolution << " | " << capacity << " | " << osTitle;

	getline(phoneStream, phoneString);

	return phoneString;
}

void PhoneOs::stringToPhone(const string phoneString)
{
	stringstream phoneStream;
	phoneStream << phoneString;

	getline(phoneStream, title, '|');
	title.erase(title.end() - 1);
	phoneStream.ignore(1);

	phoneStream >> price;
	phoneStream.ignore(3);

	phoneStream >> simCardsNumber;
	phoneStream.ignore(3);

	phoneStream >> resolution;
	phoneStream.ignore(3);

	phoneStream >> capacity;
	phoneStream.ignore(3);

	getline(phoneStream, osTitle);
}

string PhoneOs::getOsTitle() const { return osTitle; }
void PhoneOs::setOsTitle(string newOsTitle) { osTitle = newOsTitle; }