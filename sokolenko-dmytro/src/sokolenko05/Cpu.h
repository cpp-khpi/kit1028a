/**
* @file Cpu.h
* Оголошення класу Cpu.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include <string>

using std::string;

/**
* Опис класу Cpu з його полями та методами.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class Cpu {
private:
	/** Назва процесору. */
	string title;
	/** Кількість ядер процесору. */
	unsigned int coresNumber;
	/** Частота процесору. */
	unsigned int frequency;
public:
	/**
	* Зчитування поля Cpu::coresNumber.
	* @return поточне значення поля Cpu::coresNumber.
	*/
	string getTitle() const;

	/**
	* Встановлення значння змінної Cpu::coresNumber.
	* @param newCapacity присвоюється Cpu::coresNumber.
	*/
	void setTitle(string newTitle);

	/**
	* Зчитування поля Cpu::coresNumber.
	* @return поточне значення поля Cpu::coresNumber.
	*/
	unsigned int getCoresNumber() const;

	/**
	* Встановлення значння змінної Cpu::coresNumber.
	* @param newCapacity присвоюється Cpu::coresNumber.
	*/
	void setCoresNumber(unsigned int newCoresNumber);

	/**
	* Зчитування поля Cpu::frequency.
	* @return поточне значення поля Cpu::frequency.
	*/
	unsigned int getFrequency() const;

	/**
	* Встановлення значння змінної Cpu::frequency.
	* @param newCapacity присвоюється Cpu::frequency.
	*/
	void setFrequency(unsigned int newFrequency);
	
	/**
	* Конструктор за замовчуванням.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних.
	*/
	Cpu();

	/**
	* Конструктор з параметрами.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних.
	* @param newTitle з використанням бібліотечної функції копіюється у поле Cpu::title.
	* @param newCoresNumber ініціалізує поле Cpu::coresNumber.
	* @param newFrequency ініціалізує поле Cpu::frequency.
	*/
	Cpu(string newTitle,
		unsigned int newCoresNumber,
		unsigned int newFrequency);

	/**
	* Деструктор.
	*/
	~Cpu();
};