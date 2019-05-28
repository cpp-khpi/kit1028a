#include "AndroidPhone.h"

AndroidPhone::AndroidPhone() :
	manufacturer(""),
	isStandardAndroid(false),
	androidVersion(0.1) {}

AndroidPhone::AndroidPhone(string newTitle,
	unsigned int newPrice,
	unsigned int newSimNum,
	unsigned int newResolution,
	unsigned int newCapacity,
	string newManufacturer,
	bool newIsStandAndr,
	float newAndroidVersion) : 

	Phone(newTitle,
		newPrice,
		newSimNum,
		newResolution,
		newCapacity),
	manufacturer(newManufacturer),
	isStandardAndroid(newIsStandAndr),
	androidVersion(newAndroidVersion) {}

AndroidPhone::AndroidPhone(const AndroidPhone& copiedPhone) : 
	Phone(copiedPhone.title,
		copiedPhone.price,
		copiedPhone.simCardsNumber,
		copiedPhone.resolution,
		copiedPhone.capacity),
	manufacturer(copiedPhone.manufacturer),
	isStandardAndroid(copiedPhone.isStandardAndroid),
	androidVersion(copiedPhone.androidVersion) {}

AndroidPhone::~AndroidPhone() {}

void AndroidPhone::setPhoneInfo(string newTitle,
	unsigned int newPrice,
	unsigned int newSimNum,
	unsigned int newResolution,
	unsigned int newCapacity,
	string newManufacturer,
	bool newIsStandAndr,
	float newAndroidVersion)
{
	Phone::setPhoneInfo(newTitle, newPrice, newSimNum, newResolution, newCapacity);
	manufacturer = newManufacturer;
	isStandardAndroid = newIsStandAndr;
	androidVersion = newAndroidVersion;
}

AndroidPhone& AndroidPhone::operator= (const AndroidPhone& copiedPhone)
{
	if (this == &copiedPhone) {
		return *this;
	}

	setPhoneInfo(copiedPhone.title,
		copiedPhone.price,
		copiedPhone.simCardsNumber,
		copiedPhone.resolution,
		copiedPhone.capacity,
		copiedPhone.manufacturer,
		copiedPhone.isStandardAndroid,
		copiedPhone.androidVersion);

	return *this;
}

void AndroidPhone::input()
{
	Phone::input();

	rewind(stdin);
	cout << "Manufacturer: ";
	getline(cin, manufacturer);

	rewind(stdin);
	cout << "Is the OS Android standard? (1 - Yes, 0 - No): ";
	cin >> isStandardAndroid;

	rewind(stdin);
	cout << "Android version: ";
	cin >> androidVersion;

	cout << endl << endl;
}

string AndroidPhone::phoneToString() const
{
	stringstream phoneStream;
	string phoneString;

	phoneStream << "A# " << title << " | " << price << " | " << simCardsNumber <<
		" | " << resolution << " | " << capacity << " | " << manufacturer << " | " <<
		isStandardAndroid << " | " << androidVersion;

	getline(phoneStream, phoneString);

	return phoneString;
}

void AndroidPhone::stringToPhone(const string phoneString)
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
	phoneStream.ignore(3);

	getline(phoneStream, manufacturer, '|');
	manufacturer.erase(manufacturer.end() - 1);
	phoneStream.ignore(1);

	phoneStream >> isStandardAndroid;
	phoneStream.ignore(3);

	phoneStream >> androidVersion;
}

string AndroidPhone::getManufacturer() const { return manufacturer; }
void AndroidPhone::setManufacturer(string newManufacturer) { manufacturer = newManufacturer; }

void AndroidPhone::setIsStandardAndroid(bool newIsStandAndr) { isStandardAndroid = newIsStandAndr; }
bool AndroidPhone::getIsStandardAndroid() const { return isStandardAndroid; }

void AndroidPhone::setAndroidVersion(float newAndroidVersion) { androidVersion = newAndroidVersion; }
float AndroidPhone::getAndroidVersion() const { return androidVersion; }