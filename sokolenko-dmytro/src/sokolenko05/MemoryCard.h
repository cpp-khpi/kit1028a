/**
* @file MemoryCard.h
* Оголошення класу MemoryCard.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include <string>

using std::string;

/**
* Опис класу MemoryCard з його полями та методами.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class MemoryCard {
private:
	/** Назва карти пам'яті. */
	string title;
	/** Ємність карти пам'яті, GB. */
	unsigned int capacity;
public:
	/**
	* Зчитування поля MemoryCard::coresNumber.
	* @return поточне значення поля MemoryCard::coresNumber.
	*/
	string getTitle() const;

	/**
	* Встановлення значння змінної MemoryCard::coresNumber.
	* @param newTitle присвоюється MemoryCard::coresNumber.
	*/
	void setTitle(string newTitle);

	/**
	* Зчитування поля MemoryCard::capacity.
	* @return поточне значення поля MemoryCard::capacity.
	*/
	unsigned int getCapacity() const;

	/**
	* Встановлення значння змінної MemoryCard::capacity.
	* @param newCapacity присвоюється MemoryCard::capacity.
	*/
	void setCapacity(unsigned int newFrequency);

	/**
	* Конструктор за замовчуванням.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних.
	*/
	MemoryCard();

	/**
	* Конструктор з параметрами.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних.
	* @param newTitle з копіюється у поле Cpu::title.
	* @param newCapacity ініціалізує поле MemoryCard::capacity.
	*/
	MemoryCard(string newTitle,
		unsigned int newCapacity);

	/**
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання рядка.
	* @param copiedMemCard: ініціалізація полів нового об'єкту значеннями полів передаваємого.
	*/
	MemoryCard(const MemoryCard& copiedMemCard);

	/**
	* Деструктор.
	*/
	~MemoryCard();
};