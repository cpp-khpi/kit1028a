/**
* @file PhoneArrayOs.h
* Оголошення класу PhoneOsArray.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "PhoneOs.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <utility>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::swap;
using std::function;

/**
* Опис класу PhoneOsArray з його полями та методами.
* Містить в собі масив об'єктів PhoneOs і розмір цього масиву.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class PhoneOsArray {
private:
	/** Розмір масиву об'єктів. */
	size_t size;
	/** Покажчик на масив об'єктів. */
	PhoneOs * phoneOsArray;
public:
	/**
	* Конструктор за замовчуванням.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті для масиву об'єктів.
	*/
	PhoneOsArray();

	/**
	* Конструктор з параметрами.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання масива
	* за допомогою перевантаженого оператора присвоєння.
	* @param newSize ініціалізує поле PhoneOsArray::size.
	* @param newPhoneOsArray. З передаваемого масиву виконується
	* копіювання об'єктів класу PhoneOs у поточний масив
	* за допомогою перевантаженого оператора присвоєння.
	*/
	PhoneOsArray(size_t newSize, PhoneOs* newPhoneOsArray);

	/**
	* Конструктор копіювання.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання масиву
	* об'єктів класу PhoneOs у поточний масив
	* за допомогою перевантаженого оператора присвоєння.
	* @param copiedPhoneOsArray: ініціалізація полів нового об'єкту
	* значеннями полів передаваємого.
	*/
	PhoneOsArray(const PhoneOsArray& copiedPhoneOsArray);

	/**
	* Деструктор. Звільнення виділеної пам'яті для масиву.
	*/
	~PhoneOsArray();

	/**
	* Зчитування поля PhoneArray::size.
	* @return поточне значення поля PhoneArray::size.
	*/
	size_t getSize() const;

	/**
	* Зчитування поля PhoneArray::phoneArray.
	* @return поточне значення поля PhoneArray::phoneArray.
	*/
	const PhoneOs* getPhoneOsArray() const;

	/**
	* Метод, що перевіряє рядок на коректність за допомогою регулярних виразів.
	* @param checkString - рядок, що перевіряється.
	* @return статус коректності рядку.
	*/
	bool isCorrectCheckRegex(string& checkString) const;

	/**
	* Зчитування з консолі інформації та її запис
	* у поля передаваємого об'єкту.
	* @param newPhone - у поля об'єкту відбувається запис
	* інформації з консолі.
	*/
	void readFromConsole(PhoneOs& newPhoneOs) const;

	/**
	* Зчитування з файлу інформації про масив об'єктів.
	* @param fileName - рядок з назвою файлу.
	*/
	void readFromFile(string fileName);

	/**
	* Запис у файл інформації з масиву PhoneArray::phoneArray.
	* @param fileName - рядок з назвою файлу.
	*/
	void writeToFile(string fileName);

	/**
	* Додавання об'єкту класу Phone у
	* масив PhoneArray::phoneArray.
	* @param addedPhone - додаваємий об'єкт.
	*/
	void addPhone(PhoneOs& addedPhoneOs);

	/**
	* Зчитування розміру індексу обробляемого об'єкту масиву.
	* @return зчитане значення індексу.
	*/
	int inputIndex() const;

	/**
	* Видалення об'єкту класу Phone з
	* масиву PhoneArray::phoneArray.
	* @param index - індекс видаляємого об'єкту.
	*/
	void removePhoneOs(const int index);

	/**
	* Отримання по індексу посилання на елемент масиву
	* PhoneArray::phoneArray.
	* @param index - індекс отримуємого об'єкту.
	* @return посилення на елемент масиву.
	*/
	PhoneOs& getPhoneOs(const int index);

	/**
	* Виведення на екран інформаціі про усі
	* елементи масиву PhoneArray::phoneArray.
	*/
	void showAll() const;
};
