#include "MemoryCard.h"

string MemoryCard::getTitle() const { return title; }
void MemoryCard::setTitle(string newTtitle) { title = newTtitle; }

unsigned int MemoryCard::getCapacity() const { return capacity; }
void MemoryCard::setCapacity(unsigned int newCapacity) { capacity = newCapacity; }

MemoryCard::MemoryCard() :
	title(""),
	capacity(0) {}

MemoryCard::MemoryCard(string newTitle,
	unsigned int newCapacity) : 
	title(newTitle),
	capacity(newCapacity) {}

MemoryCard::MemoryCard(const MemoryCard& copiedMemCard) :
	title(copiedMemCard.title),
	capacity(copiedMemCard.capacity) {}

MemoryCard::~MemoryCard() {}