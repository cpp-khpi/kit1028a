/**
* @file PhoneArray.h
* Оголошення класу PhoneArray.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"
#include "IosPhone.h"
#include "AndroidPhone.h"
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
* Опис класу PhoneArray з його полями та методами.
* Містить в собі масив об'єктів Phone і розмір цього масиву.
* Використовуються коментарі в стилі Javadoc для обробки пакетом Doxygen.
*/
class PhoneArray {
private:
	/** Розмір масиву об'єктів. */
	size_t size;
	/** Покажчик на масив покажчиків. */
	Phone** phoneArray;
public:
	/**
	* Конструктор за замовчуванням.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті для масиву об'єктів.
	*/
	PhoneArray();

	/**
	* Конструктор з параметрами.
	* Інізіалізація полів.
	* Використовується список ініціалізації числових змінних,
	* в тілі конструктора виконується виділення пам'яті та копіювання масива
	* за допомогою перевантаженого оператора присвоєння.
	* @param newSize ініціалізує поле PhoneArray::size.
	* @param newPhoneArray. З передаваемого масиву виконується
	* копіювання об'єктів класу Phone у поточний масив
	* за допомогою перевантаженого оператора присвоєння.
	*/
	PhoneArray(size_t newSize, Phone** newPhoneArray);

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
	PhoneArray(const PhoneArray& copiedPhoneDatabase);

	/**
	* Деструктор. Звільнення виділеної пам'яті для масиву.
	*/
	~PhoneArray();

	/**
	* Доступ до потрібного елементу масиву за індексом.
	* @return посилання на об'єкт з i-тим індексом.
	*/
	Phone& operator[] (const unsigned int index);

	/**
	* Оператор вводу, що приймає рядок з інформацією про об'єкт
	* і на його основі заповнює поля об'єкту.
	* @param out - посилання на потік вводу
	* @param outputPhone - посилання на об'єкт Phone.
	* @return посилання на потік вводу.
	*/
	friend istream& operator>>(istream& in, PhoneArray& inputPhone);

	/**
	* Оператор виводу, що виводить кількість рядків 
	* (яка дорівнює розміру масиву) з інформацією про об'єкти.
	* @param out - посилання на потік виводу
	* @param outputPhoneArray - посилання на об'єкт PhoneArray.
	* @return посилання на потік виводу.
	*/
	friend ostream& operator<<(ostream& out, const PhoneArray& outputPhoneArray);

	/**
	* Присвоєння полів класу PhoneArray.
	* @param newSize присвоюєтьяс полю PhoneArray::size.
	* @param newPhoneArray. З передаваемого масиву виконується
	* копіювання об'єктів класу Phone у поточний масив
	* за допомогою перевантаженого оператора присвоєння.
	*/
	void setPhoneDatabaseInfo(size_t newSize, Phone* newPhoneArray);

	/**
	* Метод порівняння окремого масиву об'єктів класу Phone і масиву,
	* що є полем об'єкта класу PhoneArray.
	* @param otherPhoneArr - вказівник на порівнюваний масив.
	* @param otherSize - розмір масиву.
	* @return статус вказівників на масива об'єктів
	* класу Phone: рівні чи ні.
	*/
	bool comparisonPhoneArray(const Phone* otherPhoneArr, size_t otherSize) const;

	/**
	* Зчитування поля PhoneArray::size.
	* @return поточне значення поля PhoneArray::size.
	*/
	size_t getSize() const;

	/**
	* Зчитування поля PhoneArray::phoneArray.
	* @return поточне значення поля PhoneArray::phoneArray.
	*/
	Phone** getPhoneArray() const;

	/**
	* Метод, що перевіряє рядок на коректність за допомогою регулярних виразів.
	* @param checkString - рядок, що перевіряється.
	* @return статус коректності рядку.
	*/
	bool isCorrectCheckRegex(string& checkString) const;

	/**
	* Метод, що виводить на екран список усіх
	* об’єктів, які мають одне або більше полів з  
	* щонайменше двома словами.
	*/
	void printPhonesMoreTwoWords() const;

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
	* @param addedPhone - вказівник на додаваємий об'єкт.
	*/
	void addPhone(Phone* addedPhone);

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
	void removePhone(const unsigned int index);

	/**
	* Виведення на екран інформаціі про усі
	* елементи масиву PhoneArray::phoneArray.
	*/
	void showAll() const;

	/**
	* Отримання посилання на елемент масиву об'єктів
	* класу Phone з найменшою щільністю пікселів.
	* @return посилення на елемент масиву.
	*/
	Phone* getSmallestResolutPhone() const;

	/**
	* Метод, що сортирує масив елементів
	* типу Phone за ознакою, яка передається вказівником на функцію.
	* @param comparFunc: логічная функція, що визначає 
	* параметри сортування.
	*/
	void sort(function<bool(Phone*, Phone*)> comparFunc);
};
