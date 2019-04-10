#include "Phone.h"

Phone::Phone() : title("Nokia 3310"), price(1000), simCardsNumber(1), resolution(4032), capacity(900)
{
	cout << "Default constructor! Phone" << endl;
}

Phone::Phone(string newTitle, unsigned int newPrice, unsigned int newSimNum,
	unsigned int newResolution, unsigned int newCapacity) :
	title(newTitle),
	price(newPrice),
	simCardsNumber(newSimNum),
	resolution(newResolution),
	capacity(newCapacity)
{
	cout << "Constructor with param. Phone" << endl;
}

Phone::Phone(const Phone & copiedPhone) : 
	title(copiedPhone.title),
	price(copiedPhone.price),
	simCardsNumber(copiedPhone.simCardsNumber),
	resolution(copiedPhone.resolution),
	capacity(copiedPhone.capacity)
{
	cout << "Copy constructor. Phone" << endl;
}

Phone::~Phone() { }

Phone& Phone::operator= (const Phone & copiedPhone)
{
	if (this == &copiedPhone) {
		return *this;

		cout << "Self assignment!" << endl;
	}

	title = copiedPhone.title;
	price = copiedPhone.price;
	simCardsNumber = copiedPhone.simCardsNumber;
	resolution = copiedPhone.resolution;
	capacity = copiedPhone.capacity;

	cout << "Assignment" << endl;

	return *this;
}

bool Phone::operator==(const Phone& otherPhone) const
{
	bool isEqualTitle = this->title == title;
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

void Phone::setPhoneInfo(string newTitle, unsigned int newPrice, unsigned int newSimNum,
	unsigned int newResolution, unsigned int newCapacity)
{
	title = newTitle;
	price = newPrice;
	simCardsNumber = newSimNum;
	resolution = newResolution;
	capacity = newCapacity;
}

string Phone::convertPhone() const
{
	stringstream phoneStream;
	string phoneString;

	phoneStream << "Phone title: " << title << " | ";
	phoneStream << "Cost, UAN: " << price << " | ";
	phoneStream << "Number of SIM-cards: " << simCardsNumber << " | ";
	phoneStream << "Screen resolution, pixeles: " << resolution << " | ";
	phoneStream << "Batery capacity, mAh: " << capacity << " |";

	getline(phoneStream, phoneString);
	phoneStream.str("");

	return phoneString;
}

string Phone::getTitle() const { return title; }
void Phone::setTitle(string newTitle) { title = newTitle; }

unsigned int Phone::getPrice() const { return price; }
void Phone::setPrice(unsigned int newPrice) { price = newPrice; }

unsigned int Phone::getSimCardsNumber() const { return simCardsNumber; }
void Phone::setSimCardsNumber(unsigned int newsimCardsNumber) { simCardsNumber = newsimCardsNumber; }

unsigned int Phone::getResolution() const { return resolution; }
void Phone::setResolution(unsigned int newResolution) { resolution = newResolution; }

unsigned int Phone::getCapacity() const { return capacity; }
void Phone::setCapacity(unsigned int newCapacity) { capacity = newCapacity; }