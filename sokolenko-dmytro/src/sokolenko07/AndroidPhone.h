/**
* @file AndroidPhone.h
* Оголошення базового класу AndroidPhone.
* @author Sokolenko Dmytro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"

/**
* Опис класу AndroidPhone з його полями та методами.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class AndroidPhone : public Phone {
private:
	/** Назва компанії виробника. */
	string manufacturer;
	/** Чи є OS Android стандартною. */
	bool isStandardAndroid;
	/** Версія операційною системи Android. */
	float androidVersion;
public:
	/**
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних.
	*/
	AndroidPhone();

	/**
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param newTitle ініціалізує поле AndroidPhone::title.
	* @param newPrice ініціалізує поле AndroidPhone::price.
	* @param newSimNum ініціалізує поле AndroidPhone::simCardsNumber.
	* @param newResolution ініціалізує поле AndroidPhone::resolution.
	* @param newCapacity ініціалізує поле AndroidPhone::capacity.
	* @param newAndroidVersion ініціалізує поле AndroidPhone::androidVersion.
	*/
	AndroidPhone(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		string newManufacturer,
		bool newIsStandAndr,
		float newAndroidVersion);

	/**
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param copiedAndroidPhone: ініціалізація полів нового об'єкту значеннями полів передаваємого.
	*/
	AndroidPhone(const AndroidPhone& copiedPhone);

	/**
	* Деструктор.
	*/
	virtual ~AndroidPhone() override;

	/**
	* Присвоювання полям классу нових значень.
	* @param newTitle, @param newPrice, @param newSimNum, @param newResolution,
	* @param newCapacity передаються у функцію Phone::setPhoneInfo,
	* де присвоюються відповідним полям.
	* @param newManufacturer присвоюється полю AndroidPhone::manufacturer,
	* @param newIsStandAndr присвоюється полю AndroidPhone::isStandardAndroid,
	* @param newAndroidVersion присвоюється полю AndroidPhone::androidVersion.
	*/
	void setPhoneInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		string newManufacturer,
		bool newIsStandAndr,
		float newAndroidVersion);

	/**
	* Перевантажений оператор присваювання.
	* @param copiedAndroidPhone: значення його полів присвоюються полям поточного об'єкту.
	* @return вказівник на поточний об'єкт.
	*/
	AndroidPhone& operator= (const AndroidPhone& copiedPhone);

	/**
	* Зчитання з консолі та заповнення полів об'єкту AndroidPhone.
	*/
	virtual void input() override;

	/**
	* Конвертування інформації про поточний об'єкт у рядок.
	* Перевантаження методу класу AndroidPhone.
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
	* Встановлення значння змінної IosPhone::iosVersion.
	* @param newIosVersion присвоюється полю IosPhone::iosVersion.
	*/
	void setManufacturer(string newManufacturer);

	/**
	* Зчитування поля AndroidPhone::manufacturer.
	* @return поточне значення поля Phone::manufacturer.
	*/
	string getManufacturer() const;

	/**
	* Встановлення значння змінної AndroidPhone::isStandardAndroid.
	* @param newIsStandAndr присвоюється полю AndroidPhone::isStandardAndroid.
	*/
	void setIsStandardAndroid(bool newIsStandAndr);

	/**
	* Зчитування поля AndroidPhone::isStandardAndroid.
	* @return поточне значення поля AndroidPhone::isStandardAndroid.
	*/
	bool getIsStandardAndroid() const;

	/**
	* Встановлення значння змінної AndroidPhone::androidVersion.
	* @param newIosVersion присвоюється полю AndroidPhone::androidVersion.
	*/
	void setAndroidVersion(float newAndroidVersion);

	/**
	* Зчитування поля AndroidPhone::androidVersion.
	* @return поточне значення поля AndroidPhone::androidVersion.
	*/
	float getAndroidVersion() const;
};