#include "Phone.h"

Phone::Phone() : 
	title(""), 
	price(0), 
	simCardsNumber(0), 
	resolution(0), 
	capacity(0),
	memCard(nullptr) {}

Phone::Phone(string newTitle,
	unsigned int newPrice,
	unsigned int newSimNum,
	unsigned int newResolution,
	unsigned int newCapacity,
	Cpu newProcessor) :
	title(newTitle),
	price(newPrice),
	simCardsNumber(newSimNum),
	resolution(newResolution),
	capacity(newCapacity),
	processor(newProcessor) {}

Phone::Phone(const Phone & copiedPhone) : 
	title(copiedPhone.title),
	price(copiedPhone.price),
	simCardsNumber(copiedPhone.simCardsNumber),
	resolution(copiedPhone.resolution),
	capacity(copiedPhone.capacity),
	processor(copiedPhone.processor) {}

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
	processor = copiedPhone.processor;


	return *this;
}

bool Phone::operator==(const Phone& otherPhone) const
{
	bool isEqualTitle = this->title == title;
	bool isEqualPrice = this->price == otherPhone.price;
	bool isEqualSimNumb = this->simCardsNumber == otherPhone.simCardsNumber;
	bool isEqualResol = this->resolution == otherPhone.resolution;
	bool isEqualCapac = this->capacity == otherPhone.capacity;
	bool isEqualCpu = this->processor == otherPhone.processor;

	if (isEqualPrice && isEqualSimNumb && isEqualResol && isEqualCapac && isEqualTitle)
		return true;
	else
		return false;
}

bool Phone::operator!=(const Phone& otherPhone) const
{
	return !(*this == otherPhone);
}

void Phone::setPhoneInfo(string newTitle, 
	unsigned int newPrice, 
	unsigned int newSimNum,
	unsigned int newResolution, 
	unsigned int newCapacity,
	Cpu newProccessor)
{
	title = newTitle;
	price = newPrice;
	simCardsNumber = newSimNum;
	resolution = newResolution;
	capacity = newCapacity;
	processor = newProccessor;
}

string Phone::phoneToString() const
{
	stringstream phoneStream;
	string phoneString;

	phoneStream << title << " | ";
	phoneStream << price << " | ";
	phoneStream << simCardsNumber << " | ";
	phoneStream << resolution << " | ";
	phoneStream << capacity;

	getline(phoneStream, phoneString);

	return phoneString;
}

void Phone::stringToPhone(const string phoneString)
{
	stringstream phoneStream;
	phoneStream << phoneString;

	getline(phoneStream, title, '|');
	title.erase(title.end()-1);
	phoneStream.ignore(1);

	phoneStream >> price;
	phoneStream.ignore(3);

	phoneStream >> simCardsNumber;
	phoneStream.ignore(3);

	phoneStream >> resolution;
	phoneStream.ignore(3);

	phoneStream >> capacity;
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

const MemoryCard* Phone::getMemoryCard() const { return memCard; }
void Phone::setMemoryCard(MemoryCard* newMemCard) { memCard = newMemCard; }