#pragma once

using namespace std;

#include <iostream>
#include <string>

using namespace std;

class Phone {
private:
	unsigned int cost;
	unsigned int numberOfSim;
	float display;
	unsigned int permission;
	unsigned int capacity;
public:
	unsigned int getCost() { return cost; }
	void setCost(unsigned int new_cost) { cost = new_cost; }

	unsigned int getNumberOfSim() { return numberOfSim; }
	void setNumberOfSim(unsigned int new_numberOfSim) { numberOfSim = new_numberOfSim; }

	float getDisplay() { return display; }
	void setDisplay(float new_display) { display = new_display; }

	unsigned int getPermission() { return permission; }
	void setPermission(unsigned int new_permission) { permission = new_permission; }

	unsigned int getCapacity() { return capacity; }
	void setCapacity(unsigned int new_capacity) { capacity = new_capacity; }
};

class Processing {
protected:
	int size;
	Phone * database;
public:
	int getSize() { return size; }
	void setSize(unsigned int new_size) { size = new_size; }

	Phone * getDatabase() { return database; }
	void setDatabase(Phone * new_database) { database = new_database; } //возврат указателя

	void inputSize();
	void readPhone(Phone *) const;
	void createArray();
	void addPhone(Phone *); //нужен тест
	int inputIndex() const;
	void removePhone(const int);//test nuzhen
	void getPhone(const int) const;//??
	void showAll() const;//??
	void deleteArray();
};