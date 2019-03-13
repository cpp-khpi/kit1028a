#include "phone.h"

void Phone::setData(char * newTitle, unsigned int newPrice, unsigned int newSimNum, unsigned int newResolution, unsigned int newCapacity)
{
	const int TITLELEN = 50;
	strncpy_s(title, TITLELEN, newTitle, strlen(newTitle));

	price = newPrice;
	simCardsNumber = newSimNum;
	resolution = newResolution;
	capacity = newCapacity;
}

char * Phone::getTitle() { return title; }
void Phone::setTitle(char * newTitle) { title = newTitle; }

unsigned int Phone::getPrice() { return price; }
void Phone::setPrice(unsigned int newPrice) { price = newPrice; }

unsigned int Phone::getSimCardsNumber() { return simCardsNumber; }
void Phone::setSimCardsNumber(unsigned int newsimCardsNumber) { simCardsNumber = newsimCardsNumber; }

unsigned int Phone::getResolution() { return resolution; }
void Phone::setResolution(unsigned int newResolution) { resolution = newResolution; }

unsigned int Phone::getCapacity() { return capacity; }
void Phone::setCapacity(unsigned int newCapacity) { capacity = newCapacity; }