/**
* @file PhoneDatabase.h
* Оголошення класу PhoneDatabase.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "phone.h"
#include <iostream>
#include <fstream>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::regex;
using std::regex_match;
using std::regex_search;

/**
* Опис класу PhoneDatabase з його полями та методами.
* Містить в собі масив об'єктів Phone і розмір цього масиву.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class PhoneDatabase {
	/** Розмір масиву об'єктів. */
	int size;
	/** Покажчик на масив об'єктів. */
	Phone * phoneArray;
public:
	/**
	* Конструктор за замовчуванням.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті для масиву об'єктів.
	*/
	PhoneDatabase();

	/**
	* Конструктор з параметрами.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання масива
	* за допомогою перевантаженого оператора присвоєння.
	* @param newSize ініціалізує поле PhoneDatabase::size.
	* @param newPhoneArray. З передаваемого масиву виконується
	* копіювання об'єктів класу Phone у поточний масив
	* за допомогою перевантаженого оператора присвоєння.
	*/
	PhoneDatabase(int newSize, Phone* newPhoneArray);

	/**
	* Конструктор копіювання.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання масиву
	* об'єктів класу Phone у поточний масив
	* за допомогою перевантаженого оператора присвоєння.
	* @param copiedPhoneDatabase: ініціалізація полів нового об'єкту 
	* значеннями полів передаваємого.
	*/
	PhoneDatabase(const PhoneDatabase& copiedPhoneDatabase);

	/**
	* Деструктор. Звільнення виділеної пам'яті для масиву.
	*/
	~PhoneDatabase();

	/**
	* Присвоєння полів класу PhoneDatabase.
	* @param newSize присвоюєтьяс полю PhoneDatabase::size.
	* @param newPhoneArray. З передаваемого масиву виконується
	* копіювання об'єктів класу Phone у поточний масив
	* за допомогою перевантаженого оператора присвоєння.
	*/
	void setPhoneDatabaseInfo(int newSize, Phone* newPhoneArray);

	/**
	* Метод порівняння окремого масиву об'єктів класу Phone і масиву,
	* що є полем об'єкта класу PhoneDatabase.
	* @param otherPhoneArr - вказівник на порівнюваний масив.
	* @param otherSize - розмір масиву.
	* @return статус вказівників на масива об'єктів
	* класу Phone: рівні чи ні.
	*/
	bool comparisonPhoneArray(const Phone* otherPhoneArr, int otherSize) const;

	/**
	* Зчитування поля PhoneDatabase::size.
	* @return поточне значення поля PhoneDatabase::size.
	*/
	int getSize() const;

	/**
	* Зчитування поля PhoneDatabase::phoneArray.
	* @return поточне значення поля PhoneDatabase::phoneArray.
	*/
	const Phone * getPhoneArray() const;

	/**
	* Перевірка рядку на коректність за допомогою регулярних виразів.
	* @param checkString - посилання на рядок, що перевіряється.
	*/
	void correctCheckRegex(string& checkString) const;

	/**
	* Перевірка рядку на коректність за допомогою регулярних виразів.
	* @param checkString - рядок, що перевіряється.
	* @return статус коректності рядку.
	*/
	bool isCorrectCheckRegex(string checkString) const;

	/**
	* Зчитування з консолі інформації та її запис
	* у поля передаваємого об'єкту.
	* @param newPhone - у поля об'єкту відбувається запис
	* інформації з консолі.
	*/
	void readFromConsole(Phone& newPhone) const;

	/**
	* Зчитування з файлу інформації про масив об'єктів.
	* @param fileName - рядок з назвою файлу.
	*/
	void readFromFile(string fileName);

	/**
	* Запис у файл інформації з масиву PhoneDatabase::phoneArray.
	* @param fileName - рядок з назвою файлу.
	*/
	void writeToFile(string fileName);

	/**
	* Додавання об'єкту класу Phone у
	* масив PhoneDatabase::phoneArray.
	* @param addedPhone - додаваємий об'єкт.
	*/
	void addPhone(Phone& addedPhone);

	/**
	* Зчитування розміру індексу обробляемого об'єкту масиву.
	* @return зчитане значення індексу.
	*/
	int inputIndex() const;

	/**
	* Видалення об'єкту класу Phone з
	* масиву PhoneDatabase::phoneArray.
	* @param index - індекс видаляємого об'єкту.
	*/
	void removePhone(const int index);

	/**
	* Отримання по індексу посилання на елемент масиву
	* PhoneDatabase::phoneArray.
	* @param index - індекс отримуємого об'єкту.
	* @return посилення на елемент масиву.
	*/
	Phone& getPhone(const int index);

	/**
	* Виведення на екран інформаціі про усі
	* елементи масиву PhoneDatabase::phoneArray.
	*/
	void showAll() const;

	/**
	* Отримання посилання на елемент масиву об'єктів
	* класу Phone з найменшою щільністю пікселів.
	* @return посилення на елемент масиву.
	*/
	Phone& getSmallestResolutPhone() const;
};

