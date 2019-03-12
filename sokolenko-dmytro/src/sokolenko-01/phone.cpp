#include "phone.h"

unsigned int Phone::getPrice() { return price; }
void Phone::setPrice(unsigned int newPrice) { price = newPrice; }

unsigned int Phone::getSimCardsNumber() { return simCardsNumber; }
void Phone::setSimCardsNumber(unsigned int newsimCardsNumber) { simCardsNumber = newsimCardsNumber; }

float Phone::getDisplay() { return display; }
void Phone::setDisplay(float newDisplay) { display = newDisplay; }

unsigned int Phone::getPermission() { return permission; }
void Phone::setPermission(unsigned int newPermission) { permission = newPermission; }

unsigned int Phone::getCapacity() { return capacity; }
void Phone::setCapacity(unsigned int newCapacity) { capacity = newCapacity; }