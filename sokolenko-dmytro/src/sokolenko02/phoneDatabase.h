#pragma once

#include <iostream>
#include "phone.h"

using std::cin;
using std::cout;
using std::endl;


/**
* Опис класу PhoneDatabase з його полями та методами.
* Містить в собі масив об'єктів Phone і розмір цього масиву.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class PhoneDatabase {
	/** Розмір масиву об'єктів. */
	int size;
	/** Покажчик на масив об'єктів. */
	Phone * phoneArray;
public:
	PhoneDatabase();
	PhoneDatabase(int, Phone *);
	PhoneDatabase(const PhoneDatabase &);
	~PhoneDatabase();
	
	/**
	* Зчитування поля PhoneDatabase::size.
	* @return поточне значення поля PhoneDatabase::size.
	*/
	int getSize();

	/**
	* Встановлення значння змінної PhoneDatabase::size.
	* @param newSize присвоюється PhoneDatabase::size.
	*/
	void setSize(unsigned int);

	/**
	* Зчитування поля PhoneDatabase::phoneArray.
	* @return поточне значення поля PhoneDatabase::phoneArray.
	*/
	Phone * getPhoneArray();

	/**
	* Встановлення значння змінної PhoneDatabase::phoneArray.
	* @param newSize присвоюється PhoneDatabase::phoneArray.
	*/
	void setPhoneArray(Phone *);

	/**
	* @brief Зчитування розміру масива з клавіатури.
	* Зчитування розміру масиву з клавіатури та запис значення у поле PhoneDatabase::size.
	* @return зчитане значення поля PhoneDatabase::size.
	*/
	int inputSize();

	void readPhone(Phone &) const;


	void addPhone(Phone &);

	int inputIndex() const;

	void removePhone(const int);

	Phone& getPhone(const int);

	void printPhone(Phone &) const;

	void showAll() const;

	void deleteArray();
};

