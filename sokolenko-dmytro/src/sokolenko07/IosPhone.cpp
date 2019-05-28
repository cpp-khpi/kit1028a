#include "IosPhone.h"

IosPhone::IosPhone() :
	iosVersion(10.0) {}

IosPhone::IosPhone(string newTitle,
	unsigned int newPrice,
	unsigned int newSimNum,
	unsigned int newResolution,
	unsigned int newCapacity,
	float newIosVersion) :

	Phone(newTitle,
		newPrice, 
		newSimNum, 
		newResolution, 
		newCapacity),
		iosVersion(newIosVersion) {}

IosPhone::IosPhone(const IosPhone& copiedPhone) :
	Phone(copiedPhone.title,
		copiedPhone.price,
		copiedPhone.simCardsNumber,
		copiedPhone.resolution,
		copiedPhone.capacity),
	iosVersion(copiedPhone.iosVersion) {}

IosPhone::~IosPhone() {}

void IosPhone::setPhoneInfo(string newTitle,
	unsigned int newPrice,
	unsigned int newSimNum,
	unsigned int newResolution,
	unsigned int newCapacity,
	float newIosVersion)
{
	Phone::setPhoneInfo(newTitle, newPrice, newSimNum, newResolution, newCapacity);
	iosVersion = newIosVersion;
}

IosPhone& IosPhone::operator= (const IosPhone& copiedPhone)
{
	if (this == &copiedPhone) {
		return *this;
	}

	setPhoneInfo(copiedPhone.title,
		copiedPhone.price,
		copiedPhone.simCardsNumber,
		copiedPhone.resolution,
		copiedPhone.capacity,
		copiedPhone.iosVersion);

	return *this;
}

void IosPhone::input()
{
	Phone::input();

	cout << "Manufacturer: Apple" << endl;

	rewind(stdin);
	cout << "Ios version: ";
	cin >> iosVersion;

	cout << endl << endl;
}

string IosPhone::phoneToString() const
{
	stringstream phoneStream;
	string phoneString;

	phoneStream << "I# " << title << " | " << price << " | " << simCardsNumber << 
		" | " << resolution << " | " << capacity << " | " << manufacturer << " | " <<
		iosVersion;

	getline(phoneStream, phoneString);

	return phoneString;
}

void IosPhone::stringToPhone(const string phoneString)
{
	stringstream phoneStream;
	phoneStream << phoneString;

	phoneStream.ignore(3);

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
	phoneStream.ignore(11);

	phoneStream >> iosVersion;
}

string IosPhone::getManufacturer() const { return manufacturer; }

void IosPhone::setIosVersion(float newIosVersion) { iosVersion = newIosVersion; }
float IosPhone::getIosVersion() const { return iosVersion; }