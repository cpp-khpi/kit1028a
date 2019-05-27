/**
* @file TestPhoneArray.h
* Оголошення класу TestPhoneArray.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"
#include "PhoneArray.h"

/**
* Опис тестового класу TestPhoneArray з його полями та методами. 
* Його основна функція - протестувати методи класу PhoneArray.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class TestPhoneArray {
private:
	/** Об'єкт тестованого класу. */
	PhoneArray phoneDatabase;

	/** 
	* Метод тестування функції PhoneArray::addPhone.
	* @return статус працездатності функції PhoneArray::addPhone.
	*/
	bool testAddPhone();

	/**
	* Метод тестування функції PhoneArray::removePhone() при
	* видаленні елементу з кінця.
	* @return статус працездатності  функції PhoneArray::removePhone() при
	* видаленні елементу з кінця.
	*/
	bool isRemoveFromEnd();

	/**
	* Метод тестування функції PhoneArray::removePhone() при
	* видаленні елементу з початку.
	* @return статус працездатності  функції PhoneArray::removePhone() при
	* видаленні елементу з початку.
	*/
	bool isRemoveFromBegin();

	/**
	* Метод тестування функції PhoneArray::removePhone() при
	* видаленні єдиного елементу.
	* @return статус працездатності  функції PhoneArray::removePhone() при
	* видаленні єдиного елементу.
	*/
	bool isSingleRemove();


	/** 
	* Метод тестування функції PhoneArray::removePhone.
	* @return статус працездатності функції PhoneArray::removePhone.
	*/
	bool testRemovePhone();

	/** 
	* Метод тестування функції PhoneArray::getPhone.
	* @return статус працездатності функції PhoneArray::getPhone.
	*/
	bool testGetPhone();

	/** 
	* Метод тестування функції PhoneArray::getSmallestResolutPhone.
	* @return статус працездатності функції PhoneArray::getSmallestResolutPhone.
	*/
	bool testGetSmallestResolutPhone();
public:
	/** 
	* Метод виклику усіх функцій класу TestPhoneArray.
	* @return статус працездатності усіх функцій класу PhoneArray.
	*/
	bool testAll();
};
