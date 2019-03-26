/**
* @file phone.h
* Оголошення базового класу Phone.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

/** 
* Опис класу Phone з його полями та методами.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class Phone {
private:
	/** Назва телефону. */
	char * title;
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
	* Конструктор за замовчуванням.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	*/
	Phone();

	/** 
	* Конструктор з параметрами. 
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param newTitle з використанням бібліотечної функції копіюється у поле Phone::title.
	* @param newPrice ініціалізує поле Phone::price.
	* @param newSimNum ініціалізує поле Phone::simCardsNumber.
	* @param newResolution ініціалізує поле Phone::resolution.
	* @param newCapacity ініціалізує поле Phone::capacity.
	*/
	Phone(char *, unsigned int, unsigned int, unsigned int, unsigned int);

	/**
	* Конструктор копіювання.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param copiedPhone: ініціалізація полів нового об'єкту значеннями полів передаваємого.
	*/
	Phone(const Phone &);

	/**
	* Деструктор. Звільнення виділеної пам'яті для рядку.
	*/
	~Phone();

	/**
	* Перевантажений оператор присваювання.
	* @param copiedPhone: значення його полів присвоюються полям поточного об'єкту.
	* @return вказівник на поточний об'єкт.
	*/
	Phone& operator= (const Phone &);

	/**
	* Перевантажений оператор порівняння.
	* @param otherPhone об'єкт, з яким відбуваються порівняння.
	* @return статус рівності двох об'єктів класу Phone.
	*/
	bool operator==(const Phone&) const;

	/**
	* Перевантажений оператор порівняння.
	* @param otherPhone об'єкт, з яким відбуваються порівняння.
	* @return статус нерівності двох об'єктів класу Phone.
	*/
	bool operator!=(const Phone&) const;

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
	void setPhoneInfo(char *, unsigned int, unsigned int, unsigned int, unsigned int);

	/**
	* Зчитування поля Phone::title.
	* @return поточне значення поля Phone::title.
	*/
	char * getTitle() const;

	/**
	* Встановлення значння змінної Phone::title.
	* @param newTitle присвоюється Phone::title.
	*/
	void setTitle(char *);

	/**
	* Зчитування поля Phone::price.
	* @return поточне значення поля Phone::price.
	*/
	unsigned int getPrice() const;

	/**
	* Встановлення значння змінної Phone::price.
	* @param newPrice присвоюється Phone::price.
	*/
	void setPrice(unsigned int);

	/**
	* Зчитування поля Phone::simCardsNumber.
	* @return поточне значення поля Phone::simCardsNumber.
	*/
	unsigned int getSimCardsNumber() const;

	/**
	* Встановлення значння змінної Phone::simCardsNumber.
	* @param newSimCardsNumber присвоюється Phone::simCardsNumber.
	*/
	void setSimCardsNumber(unsigned int);

	/**
	* Зчитування поля Phone::resolution.
	* @return поточне значення поля Phone::resolution.
	*/
	unsigned int getResolution() const;

	/**
	* Встановлення значння змінної Phone::resolution.
	* @param newResolution присвоюється Phone::resolution.
	*/
	void setResolution(unsigned int);

	/**
	* Зчитування поля Phone::capacity.
	* @return поточне значення поля Phone::capacity.
	*/
	unsigned int getCapacity() const;

	/**
	* Встановлення значння змінної Phone::capacity.
	* @param newCapacity присвоюється Phone::capacity.
	*/
	void setCapacity(unsigned int);
};