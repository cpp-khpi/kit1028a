#pragma once

class Phone {
	unsigned int price;
	unsigned int simCardsNumber;
	float display;
	unsigned int permission;
	unsigned int capacity;
public:
	unsigned int getPrice();
	void setPrice(unsigned int);

	unsigned int getSimCardsNumber();
	void setSimCardsNumber(unsigned int);

	float getDisplay();
	void setDisplay(float);

	unsigned int getPermission();
	void setPermission(unsigned int);

	unsigned int getCapacity();
	void setCapacity(unsigned int);
};