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

bool IosPhone::operator==(const IosPhone& otherPhone) const
{
	bool isEqualTitle = this->title == otherPhone.title;
	bool isEqualPrice = this->price == otherPhone.price;
	bool isEqualSimNumb = this->simCardsNumber == otherPhone.simCardsNumber;
	bool isEqualResol = this->resolution == otherPhone.resolution;
	bool isEqualCapac = this->capacity == otherPhone.capacity;
	bool isEqualVersion = this->iosVersion == otherPhone.iosVersion;

	if (isEqualTitle &&
		isEqualPrice &&
		isEqualSimNumb &&
		isEqualResol &&
		isEqualCapac &&
		isEqualVersion)
		return true;
	else
		return false;
}

bool IosPhone::operator!=(const IosPhone& otherPhone) const
{
	return !(*this == otherPhone);
}

bool IosPhone::operator==(const IosPhone* otherPhone) const
{
	bool isEqualTitle = this->title == otherPhone->title;
	bool isEqualPrice = this->price == otherPhone->price;
	bool isEqualSimNumb = this->simCardsNumber == otherPhone->simCardsNumber;
	bool isEqualResol = this->resolution == otherPhone->resolution;
	bool isEqualCapac = this->capacity == otherPhone->capacity;
	bool isEqualVersion = this->iosVersion == otherPhone->iosVersion;

	if (isEqualTitle &&
		isEqualPrice &&
		isEqualSimNumb &&
		isEqualResol &&
		isEqualCapac &&
		isEqualVersion)
		return true;
	else
		return false;
}

bool IosPhone::operator!=(const IosPhone* otherPhone) const
{
	return !(this == otherPhone);
}

istream& operator>>(istream& in, IosPhone& inputPhone)
{
	in.ignore(3);

	getline(in, inputPhone.title, '|');
	inputPhone.title.erase(inputPhone.title.end() - 1);
	in.ignore(1);

	in >> inputPhone.price;
	in.ignore(3);

	in >> inputPhone.simCardsNumber;
	in.ignore(3);

	in >> inputPhone.resolution;
	in.ignore(3);

	in >> inputPhone.capacity;
	in.ignore(11);

	in >> inputPhone.iosVersion;

	return in;
}

istream& operator>>(istream& in, IosPhone* inputPhone)
{
	in.ignore(3);

	getline(in, inputPhone->title, '|');
	inputPhone->title.erase(inputPhone->title.end() - 1);
	in.ignore(1);

	in >> inputPhone->price;
	in.ignore(3);

	in >> inputPhone->simCardsNumber;
	in.ignore(3);

	in >> inputPhone->resolution;
	in.ignore(3);

	in >> inputPhone->capacity;
	in.ignore(11);

	in >> inputPhone->iosVersion;

	return in;
}

ostream& operator<<(ostream& out, const IosPhone& outputPhone)
{
	out << "I# " << outputPhone.title << " | " << outputPhone.price << " | " << outputPhone.simCardsNumber <<
		" | " << outputPhone.resolution << " | " << outputPhone.capacity << " | " << outputPhone.manufacturer <<
		" | " << outputPhone.iosVersion;

	return out;
}

ostream& operator<<(ostream& out, const IosPhone* outputPhone)
{
	out << "I# " << outputPhone->title << " | " << outputPhone->price << " | " << outputPhone->simCardsNumber <<
		" | " << outputPhone->resolution << " | " << outputPhone->capacity << " | " << outputPhone->manufacturer <<
		" | " << outputPhone->iosVersion;

	return out;
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