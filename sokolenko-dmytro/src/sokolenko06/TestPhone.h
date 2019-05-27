/**
* @file TestPhone.h
* Оголошення класу TestPhone.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"

/**
* Опис тестового класу TestPhoneArray з його полями та методами.
* Його основна функція - протестувати методи класу PhoneArray.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class TestPhone {
private:
	/** Об'єкт тестованого класу. */
	Phone phone;

	/**
	* Метод тестування функції Phone::phoneToString.
	* @return статус працездатності функції Phone::phoneToString.
	*/
	bool testPhoneToString();

	/**
	* Метод тестування функції Phone::stringToPhone.
	* @return статус працездатності функції Phone::stringToPhone.
	*/
	bool testStringToPhone();
public:
	/**
	* Метод виклику усіх функцій класу TestPhone.
	* @return статус працездатності усіх функцій класу Phone.
	*/
	bool testAll();
};