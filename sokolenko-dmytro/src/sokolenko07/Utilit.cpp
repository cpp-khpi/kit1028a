#include "Utilit.h"

bool ascendingPrice(Phone* firstPhone, Phone* secondPhone)
{
	return firstPhone->getPrice() > secondPhone->getPrice();
}

bool ascendingResolution(Phone* firstPhone, Phone* secondPhone)
{
	return firstPhone->getResolution() > secondPhone->getResolution();
}

bool ascendingCapacity(Phone* firstPhone, Phone* secondPhone)
{
	return firstPhone->getCapacity() > secondPhone->getCapacity();
}

bool descendingPrice(Phone* firstPhone, Phone* secondPhone)
{
	return firstPhone->getPrice() < secondPhone->getPrice();
}

bool descendingResolution(Phone* firstPhone, Phone* secondPhone)
{
	return firstPhone->getResolution() < secondPhone->getResolution();
}

bool descendingCapacity(Phone* firstPhone, Phone* secondPhone)
{
	return firstPhone->getCapacity() < secondPhone->getCapacity();
}