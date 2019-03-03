#include "phone.h"

/*
ƒолжны ли гетеры и сетеры записыватьс€ в 1 строку?//
*/

unsigned int Phone::getCost() { return cost; }
void Phone::setCost(unsigned int newCost) { cost = newCost; }

unsigned int Phone::getNumberOfSim() { return numberOfSim; }
void Phone::setNumberOfSim(unsigned int newNumberOfSim) { numberOfSim = newNumberOfSim; }

float Phone::getDisplay() { return display; }
void Phone::setDisplay(float newDisplay) { display = newDisplay; }

unsigned int Phone::getPermission() { return permission; }
void Phone::setPermission(unsigned int newPermission) { permission = newPermission; }

unsigned int Phone::getCapacity() { return capacity; }
void Phone::setCapacity(unsigned int newCapacity) { capacity = newCapacity; }