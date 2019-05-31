/**
* @file Phone.h
* Оголошення базового класу Phone.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include <string>
#include <sstream>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::getline;
using std::ostream;
using std::istream;

/** 
* Опис класу Phone з його полями та методами.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class Phone {
protected:
	/** Назва телефону. */
	string title;
	/** Ціна телефону. */
	unsigned int price;
	/** Кількість sim-карт у телефоні. */
	unsigned int simCardsNumber;
	/** Щільність пікселів екрану телефону. */
	unsigned int resolution;
	/** Ємкість акумулятору телефону. */
	unsigned int capacity;
public:
	/** 
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних.
	*/
	Phone();

	/** 
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param newTitle ініціалізує поле Phone::title.
	* @param newPrice ініціалізує поле Phone::price.
	* @param newSimNum ініціалізує поле Phone::simCardsNumber.
	* @param newResolution ініціалізує поле Phone::resolution.
	* @param newCapacity ініціалізує поле Phone::capacity.
	*/
	Phone(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity);

	/**
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param copiedPhone: ініціалізація полів нового об'єкту значеннями полів передаваємого.
	*/
	Phone(const Phone& copiedPhone);

	/**
	* Деструктор.
	*/
	virtual ~Phone();

	/**
	* Перевантажений оператор присваювання.
	* @param copiedPhone: значення його полів присвоюються полям поточного об'єкту.
	* @return вказівник на поточний об'єкт.
	*/
	Phone& operator= (const Phone& copiedPhone);

	/**
	* Перевантажений оператор порівняння.
	* @param otherPhone об'єкт, з яким відбуваються порівняння.
	* @return статус рівності двох об'єктів класу Phone.
	*/
	bool operator==(const Phone& otherPhone) const;

	/**
	* Оператор вводу, що приймає рядок з інформацією про об'єкт 
	* і на його основі заповнює поля об'єкту.
	* @param out - посилання на потік вводу
	* @param outputPhone - посилання на об'єкт Phone.
	* @return посилання на потік вводу.
	*/
	friend istream& operator>>(istream& in, Phone& inputPhone);

	/**
	* Оператор виводу, що виводить рядок з інформацією про об'єкт.
	* @param out - посилання на потік виводу
	* @param outputPhone - посилання на об'єкт Phone.
	* @return посилання на потік виводу.
	*/
	friend ostream& operator<<(ostream& out, const Phone& outputPhone);

	/**
	* Присвоювання полям классу нових значень.
	* @param newTitle ініціалізує поле Phone::title через функцію копіювання.
	* @param newPrice ініціалізує поле Phone::price.
	* @param newSimNum ініціалізує поле Phone::simCardsNumber.
	* @param newResolution ініціалізує поле Phone::resolution.
	* @param newCapacity ініціалізує поле Phone::capacity.
	*/
	void setPhoneInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity);

	/**
	* Зчитання з консолі та заповнення полів об'єкту Phone. 
	*/
	virtual void input() = 0;

	/**
	* Конвертування інформації про поточний об'єкт у рядок.
	* @return рядок з інформацією про поточний об'єкт.
	*/
	virtual string phoneToString() const = 0;

	/**
	* Заповнення полів поточного об'єкту із
	* інформації, яка міститься у рядку.
	* @param phoneString - вихідний рядок з інформацією про об'єкт.
	*/
	virtual void stringToPhone(const string phoneString) = 0;
	
	/**
	* Встановлення значння змінної Phone::title.
	* @param newTitle присвоюється полю Phone::title.
	*/
	void setTitle(string newTitle);

	/**
	* Зчитування поля Phone::title.
	* @return поточне значення поля Phone::title.
	*/
	string getTitle() const;

	/**
	* Встановлення значння змінної Phone::price.
	* @param newPrice присвоюється Phone::price.
	*/
	void setPrice(unsigned int newPrice);

	/**
	* Зчитування поля Phone::price.
	* @return поточне значення поля Phone::price.
	*/
	unsigned int getPrice() const;

	/**
	* Встановлення значння змінної Phone::simCardsNumber.
	* @param newSimCardsNumber присвоюється Phone::simCardsNumber.
	*/
	void setSimCardsNumber(unsigned int newsimCardsNumber);

	/**
	* Зчитування поля Phone::simCardsNumber.
	* @return поточне значення поля Phone::simCardsNumber.
	*/
	unsigned int getSimCardsNumber() const;

	/**
	* Встановлення значння змінної Phone::resolution.
	* @param newResolution присвоюється Phone::resolution.
	*/
	void setResolution(unsigned int newResolution);

	/**
	* Зчитування поля Phone::resolution.
	* @return поточне значення поля Phone::resolution.
	*/
	unsigned int getResolution() const;


	/**
	* Встановлення значння змінної Phone::capacity.
	* @param newCapacity присвоюється Phone::capacity.
	*/
	void setCapacity(unsigned int newCapacity);

	/**
	* Зчитування поля Phone::capacity.
	* @return поточне значення поля Phone::capacity.
	*/
	unsigned int getCapacity() const;
};