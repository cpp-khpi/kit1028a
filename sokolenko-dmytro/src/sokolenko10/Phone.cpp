#include "Phone.h"

Phone::Phone() : 
	title(""), 
	price(0), 
	simCardsNumber(0), 
	resolution(0), 
	capacity(0) {}

Phone::Phone(string newTitle,
	unsigned int newPrice,
	unsigned int newSimNum,
	unsigned int newResolution,
	unsigned int newCapacity) :
	title(newTitle),
	price(newPrice),
	simCardsNumber(newSimNum),
	resolution(newResolution),
	capacity(newCapacity) {}

Phone::Phone(const Phone & copiedPhone) : 
	title(copiedPhone.title),
	price(copiedPhone.price),
	simCardsNumber(copiedPhone.simCardsNumber),
	resolution(copiedPhone.resolution),
	capacity(copiedPhone.capacity) {}

Phone::~Phone() {}

Phone& Phone::operator= (const Phone & copiedPhone)
{
	if (this == &copiedPhone) {
		return *this;
	}

	title = copiedPhone.title;
	price = copiedPhone.price;
	simCardsNumber = copiedPhone.simCardsNumber;
	resolution = copiedPhone.resolution;
	capacity = copiedPhone.capacity;

	return *this;
}

bool Phone::operator==(const Phone& otherPhone) const
{
	bool isEqualTitle = this->title == title;
	bool isEqualPrice = this->price == otherPhone.price;
	bool isEqualSimNumb = this->simCardsNumber == otherPhone.simCardsNumber;
	bool isEqualResol = this->resolution == otherPhone.resolution;
	bool isEqualCapac = this->capacity == otherPhone.capacity;

	bool result = isEqualTitle && isEqualPrice && isEqualSimNumb && isEqualResol && isEqualCapac;

	return result;
}

bool Phone::operator>(const Phone& otherPhone) const
{
	return (this->price > otherPhone.price) ? true : false;
}

bool Phone::operator<(const Phone& otherPhone) const
{
	return (this->price < otherPhone.price) ? true : false;
}

ostream& operator<<(ostream& out, const Phone& outputPhone)
{
	out << outputPhone.title << " | " << outputPhone.price << " | " << outputPhone.simCardsNumber <<
		" | " << outputPhone.resolution << " | " << outputPhone.capacity;

	return out;
}

void Phone::setPhoneInfo(string newTitle, 
	unsigned int newPrice, 
	unsigned int newSimNum,
	unsigned int newResolution, 
	unsigned int newCapacity)
{
	title = newTitle;
	price = newPrice;
	simCardsNumber = newSimNum;
	resolution = newResolution;
	capacity = newCapacity;
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