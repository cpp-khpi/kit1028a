#pragma once
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

// конструкторы ведь в хедере?

class Phone {
	char * title;
	unsigned int price;
	unsigned int simCardsNumber;
	unsigned int resolution;
	unsigned int capacity;
public:
	Phone()
	{
		const int TITLELEN = 50;
		const char * stdTitle = "Nokia 3310";
		title = new char[TITLELEN];
		strncpy_s(title, TITLELEN, stdTitle, strlen(stdTitle));

		price = 1000;
		simCardsNumber = 1;
		resolution = 4032;
		capacity = 900;

		cout << "Default constructor! Phone" << endl;
	}

	Phone(char * newTitle, unsigned int newPrice, unsigned int newSimNum, unsigned int newResolution, unsigned int newCapacity)
	{
		const int TITLELEN = 50;
		title = new char[TITLELEN];
		strncpy_s(title, TITLELEN, newTitle, strlen(newTitle));

		price = newPrice;
		simCardsNumber = newSimNum;
		resolution = newResolution;
		capacity = newCapacity;

		cout << "Constructor with param. Phone" << endl;
	}

	Phone(const Phone & copiedPhone)
	{
		const int TITLELEN = 50;
		title = new char[TITLELEN];
		strncpy_s(title, TITLELEN, copiedPhone.title, strlen(copiedPhone.title));

		price = copiedPhone.price;
		simCardsNumber = copiedPhone.simCardsNumber;
		resolution = copiedPhone.resolution;
		capacity = copiedPhone.capacity;

		cout << "Copy constructor. Phone" << endl;
	}

	~Phone()
	{
		delete[] title;

		cout << "Destructor. Phone" << endl;
	}

	void setData(char *, unsigned int, unsigned int, unsigned int, unsigned int);

	char * getTitle();
	void setTitle(char *);

	unsigned int getPrice();
	void setPrice(unsigned int);

	unsigned int getSimCardsNumber();
	void setSimCardsNumber(unsigned int);

	unsigned int getResolution();
	void setResolution(unsigned int);

	unsigned int getCapacity();
	void setCapacity(unsigned int);
};