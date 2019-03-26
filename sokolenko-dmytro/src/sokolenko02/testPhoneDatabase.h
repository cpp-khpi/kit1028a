/**
* @file testPhoneDatabase.h
* Оголошення класу TestPhoneDatabase.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "phone.h"
#include "phoneDatabase.h"

/**
* Опис тестового класу TestPhoneDatabase з його полями та методами. 
* Його основна функція - протестувати методи класу PhoneDatabase.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class TestPhoneDatabase {
private:
	/** Об'єкт тестованого класу. */
	PhoneDatabase phoneDatabase;

	/** Метод тестування функції PhoneDatabase::addPhone. 
	* @return статус працездатності функції PhoneDatabase::addPhone.
	*/
	bool testAddPhone();
	
	/** Метод тестування функції PhoneDatabase::removePhone.
	* @return статус працездатності функції PhoneDatabase::removePhone.
	*/
	bool testRemovePhone();

	/** Метод тестування функції PhoneDatabase::getPhone.
	* @return статус працездатності функції PhoneDatabase::getPhone.
	*/
	bool testGetPhone();

	/** Метод тестування функції PhoneDatabase::getSmallestResolutPhone.
	* @return статус працездатності функції PhoneDatabase::getSmallestResolutPhone.
	*/
	bool testGetSmallestResolutPhone();
public:
	/** Метод виклику усіх функцій класу TestPhoneDatabase.
	* @return статус працездатності усіх функцій класу PhoneDatabase.
	*/
	bool testAll();
};
