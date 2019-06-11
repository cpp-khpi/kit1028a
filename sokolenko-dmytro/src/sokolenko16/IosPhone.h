/**
* @file IosPhone.h
* Оголошення базового класу IosPhone.
* @author Sokolenko Dmytro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"

/**
* Опис класу IosPhone з його полями та методами.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class IosPhone : public Phone {
private:
	/** Назва компанії виробника. */
	const string manufacturer = "Apple";
	/** Версія операційною системи IOS. */
	float iosVersion;
public:
	/**
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних.
	*/
	IosPhone();

	/**
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param newTitle ініціалізує поле IosPhone::title.
	* @param newPrice ініціалізує поле IosPhone::price.
	* @param newSimNum ініціалізує поле IosPhone::simCardsNumber.
	* @param newResolution ініціалізує поле IosPhone::resolution.
	* @param newCapacity ініціалізує поле IosPhone::capacity.
	* @param newIosVersion ініціалізує поле IosPhone::iosVersion.
	*/
	IosPhone(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		float newIosVersion);

	/**
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param copiedIosPhone: ініціалізація полів нового об'єкту значеннями полів передаваємого.
	*/
	IosPhone(const IosPhone& copiedPhone);

	/**
	* Деструктор.
	*/
	virtual ~IosPhone() override;

	/**
	* Перевантажений оператор присваювання.
	* @param copiedPhone: значення його полів присвоюються полям поточного об'єкту.
	* @return вказівник на поточний об'єкт.
	*/
	IosPhone& operator= (const IosPhone& copiedPhone);

	/**
	* Перевантажений оператор порівняння.
	* @param otherPhone об'єкт, з яким відбуваються порівняння.
	* @return статус рівності двох об'єктів класу Phone.
	*/
	bool operator==(const IosPhone& otherPhone) const;

	/**
	* Оператор вводу, що приймає рядок з інформацією про об'єкт
	* і на його основі заповнює поля об'єкту.
	* @param out - посилання на потік вводу
	* @param outputPhone - посилання на об'єкт IosPhone.
	* @return посилання на потік вводу.
	*/
	friend istream& operator>>(istream& in, IosPhone& inputPhone);

	/**
	* Оператор виводу, що виводить рядок з інформацією про об'єкт.
	* @param out - посилання на потік виводу
	* @param outputPhone - посилання на об'єкт IosPhone.
	* @return посилання на потік виводу.
	*/
	friend ostream& operator<<(ostream& out, const IosPhone& outputPhone);

	/**
	* Оператор вводу, що приймає рядок з інформацією про об'єкт
	* і на його основі заповнює поля об'єкту.
	* @param out - посилання на потік вводу
	* @param outputPhone - посилання на об'єкт IosPhone.
	* @return посилання на потік вводу.
	*/
	friend istream& operator>>(istream& in, IosPhone* inputPhone);

	/**
	* Оператор виводу, що виводить рядок з інформацією про об'єкт.
	* @param out - посилання на потік виводу
	* @param outputPhone - посилання на об'єкт IosPhone.
	* @return посилання на потік виводу.
	*/
	friend ostream& operator<<(ostream& out, const IosPhone* outputPhone);

	void* operator new(size_t size);

	void operator delete(void *pointer);

	void* operator new[](size_t size);

	void operator delete[](void *pointer);

	/**
	* Присвоювання полям классу нових значень.
	* @param newTitle, @param newPrice, @param newSimNum, @param newResolution,
	* @param newCapacity передаються у функцію Phone::setPhoneInfo,
	* де присвоюються відповідним полям.
	* @param newIosVersion присвоюється полю IosPhone::iosVersion.
	*/
	void setPhoneInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		float newIosVersion);

	/**
	* Зчитання з консолі та заповнення полів об'єкту IosPhone.
	*/
	virtual void input() override;

	/**
	* Конвертування інформації про поточний об'єкт у рядок.
	* Перевантаження методу класу IosPhone.
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
	* Зчитування поля IosPhone::manufacturer.
	* @return поточне значення поля Phone::manufacturer.
	*/
	string getManufacturer() const;


	/**
	* Встановлення значння змінної IosPhone::iosVersion.
	* @param newIosVersion присвоюється полю IosPhone::iosVersion.
	*/
	void setIosVersion(float newIosVersion);

	/**
	* Зчитування поля IosPhone::iosVersion.
	* @return поточне значення поля IosPhone::iosVersion.
	*/
	float getIosVersion() const;
};