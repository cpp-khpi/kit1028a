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

string IosPhone::getManufacturer() const { return manufacturer; }

void IosPhone::setIosVersion(float newIosVersion) { iosVersion = newIosVersion; }
float IosPhone::getIosVersion() const { return iosVersion; }