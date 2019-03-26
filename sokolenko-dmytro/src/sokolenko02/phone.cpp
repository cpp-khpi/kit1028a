#include "phone.h"

Phone::Phone() : price(1000), simCardsNumber(1), resolution(4032), capacity(900)
{
	const int TITLELEN = 50;
	const char * stdTitle = "Nokia 3310";
	title = new char[TITLELEN];
	strncpy_s(title, TITLELEN, stdTitle, strlen(stdTitle));

	cout << "Default constructor! Phone" << endl;
}

Phone::Phone(char * newTitle, unsigned int newPrice, unsigned int newSimNum,
	unsigned int newResolution, unsigned int newCapacity) :
	price(newPrice),
	simCardsNumber(newSimNum),
	resolution(newResolution),
	capacity(newCapacity)
{
	const int TITLELEN = 50;
	title = new char[TITLELEN];
	strncpy_s(title, TITLELEN, newTitle, strlen(newTitle));

	cout << "Constructor with param. Phone" << endl;
}

Phone::Phone(const Phone & copiedPhone) : 
	price(copiedPhone.price),
	simCardsNumber(copiedPhone.simCardsNumber),
	resolution(copiedPhone.resolution),
	capacity(copiedPhone.capacity)
{

	const int TITLELEN = 50;
	title = new char[TITLELEN];
	strncpy_s(title, TITLELEN, copiedPhone.title, strlen(copiedPhone.title));

	cout << "Copy constructor. Phone" << endl;
}

Phone::~Phone()
{
	delete[] title;
	title = nullptr;

	cout << "Destructor. Phone" << endl;
}

Phone& Phone::operator= (const Phone & copiedPhone)
{
	if (this == &copiedPhone) {
		return *this;

		cout << "Self assignment!" << endl;
	}

	const int TITLELEN = 50;
	delete[] title;
	title = new char[TITLELEN];
	strncpy_s(title, TITLELEN, copiedPhone.title, strlen(copiedPhone.title));

	price = copiedPhone.price;
	simCardsNumber = copiedPhone.simCardsNumber;
	resolution = copiedPhone.resolution;
	capacity = copiedPhone.capacity;

	cout << "Assignment" << endl;

	return *this;
}

bool Phone::operator==(const Phone& otherPhone) const
{
	bool isEqualTitle = strcmp(this->getTitle(), otherPhone.getTitle()) == 0;
	bool isEqualPrice = this->getPrice() == otherPhone.getPrice();
	bool isEqualSimNumb = this->getSimCardsNumber() == otherPhone.getSimCardsNumber();
	bool isEqualResol = this->getResolution() == otherPhone.getResolution();
	bool isEqualCapac = this->getCapacity() == otherPhone.getCapacity();

	if (isEqualPrice && isEqualSimNumb && isEqualResol && isEqualCapac && isEqualTitle)
		return true;
	else
		return false;
}

bool Phone::operator!=(const Phone& otherPhone) const
{
	return !(*this == otherPhone);
}


void Phone::setPhoneInfo(char * newTitle, unsigned int newPrice, unsigned int newSimNum,
	unsigned int newResolution, unsigned int newCapacity)
{
	const int TITLELEN = 50;
	strncpy_s(title, TITLELEN, newTitle, strlen(newTitle));

	price = newPrice;
	simCardsNumber = newSimNum;
	resolution = newResolution;
	capacity = newCapacity;
}

char * Phone::getTitle() const { return title; }
void Phone::setTitle(char * newTitle) { title = newTitle; }

unsigned int Phone::getPrice() const { return price; }
void Phone::setPrice(unsigned int newPrice) { price = newPrice; }

unsigned int Phone::getSimCardsNumber() const { return simCardsNumber; }
void Phone::setSimCardsNumber(unsigned int newsimCardsNumber) { simCardsNumber = newsimCardsNumber; }

unsigned int Phone::getResolution() const { return resolution; }
void Phone::setResolution(unsigned int newResolution) { resolution = newResolution; }

unsigned int Phone::getCapacity() const { return capacity; }
void Phone::setCapacity(unsigned int newCapacity) { capacity = newCapacity; }