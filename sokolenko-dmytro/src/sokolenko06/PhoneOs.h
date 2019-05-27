/**
* @file PhoneOs.h
* Оголошення базового класу PhoneOs.
* @author Sokolenko Dmytro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"

/**
* Опис класу PhoneOs з його полями та методами.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class PhoneOs : public Phone {
private:
	/** Назва операційної системи. */
	string osTitle;
public:
	/**
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних.
	*/
	PhoneOs();

	/**
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param newTitle ініціалізує поле Phone::title.
	* @param newPrice ініціалізує поле Phone::price.
	* @param newSimNum ініціалізує поле Phone::simCardsNumber.
	* @param newResolution ініціалізує поле Phone::resolution.
	* @param newCapacity ініціалізує поле Phone::capacity.
	* @param newProcessor ініціалізує поле Phone::processor.
	*/
	PhoneOs(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		string newOsTitle);

	/**
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param copiedPhone: ініціалізація полів нового об'єкту значеннями полів передаваємого.
	*/
	PhoneOs(const PhoneOs& copiedPhoneOs);

	/**
	* Присвоювання полям классу нових значень.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param newTitle ініціалізує поле Phone::title через функцію копіювання.
	* @param newPrice ініціалізує поле Phone::price.
	* @param newSimNum ініціалізує поле Phone::simCardsNumber.
	* @param newResolution ініціалізує поле Phone::resolution.
	* @param newCapacity ініціалізує поле Phone::capacity.
	*/
	void setPhoneOsInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		string newOsTitle);

	/**
	* Конвертування інформації про поточний об'єкт у рядок.
	* Перевантаження методу класу Phone.
	* @return рядок з інформацією про поточний об'єкт.
	*/
	virtual string phoneToString() const override;

	/**
	* Заповнення полів поточного об'єкту із
	* інформації, яка міститься у рядку.
	* @param phoneString - вихідний рядок з інформацією про об'єкт.
	*/
	virtual void stringToPhone(const string phoneString) override;

	/**
	* Деструктор.
	*/
	~PhoneOs();

	/**
	* Перевантажений оператор присваювання.
	* @param copiedPhoneOs: значення його полів присвоюються полям поточного об'єкту.
	* @return вказівник на поточний об'єкт.
	*/
	PhoneOs& operator= (const PhoneOs& copiedPhoneOs);

	/**
	* Зчитування поля Phone::title.
	* @return поточне значення поля Phone::title.
	*/
	string getOsTitle() const;

	/**
	* Встановлення значння змінної Phone::title.
	* @param newTitle: рядок з пам'яті, на яку вказує newTitle,
	* копіюється у пам'ять, на яку вказує Phone::title.
	*/
	void setOsTitle(string newOsTitle);
};