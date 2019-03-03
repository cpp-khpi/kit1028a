#pragma once

class Phone {
private:
	unsigned int cost;
	unsigned int numberOfSim;
	float display;
	unsigned int permission;
	unsigned int capacity;
public:
	unsigned int getCost();
	void setCost(unsigned int);

	unsigned int getNumberOfSim();
	void setNumberOfSim(unsigned int);

	float getDisplay();
	void setDisplay(float);

	unsigned int getPermission();
	void setPermission(unsigned int);

	unsigned int getCapacity();
	void setCapacity(unsigned int);
};