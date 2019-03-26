/**
* @file phoneDatabase.h
* Оголошення класу PhoneDatabase.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/


#pragma once

#include <iostream>
#include "phone.h"

using std::cin;
using std::cout;
using std::endl;


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
	PhoneDatabase(int, Phone *);

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
	PhoneDatabase(const PhoneDatabase &);

	/**
	* Деструктор. Звільнення виділеної пам'яті для масиву.
	*/
	~PhoneDatabase();

	/**
	* Метод порівняння двох масивів об'єктів класу Phone.
	* @param firstPhoneArr - вказівник на перший порівнюваний масив.
	* @param secondPhoneArr - вказівник на другий порівнюваний масив.
	* @return статус вказівників на масива об'єктів
	* класу Phone: рівні чи ні.
	*/
	bool comparisonPhoneArray(const Phone*, const Phone*, int, int) const;

	/**
	* Зчитування поля PhoneDatabase::size.
	* @return поточне значення поля PhoneDatabase::size.
	*/
	int getSize() const;

	/**
	* Встановлення значння змінної PhoneDatabase::size.
	* @param newSize присвоюється PhoneDatabase::size.
	*/
	void setSize(int);

	/**
	* Зчитування поля PhoneDatabase::phoneArray.
	* @return поточне значення поля PhoneDatabase::phoneArray.
	*/
	Phone * getPhoneArray() const;

	/**
	* Встановлення значння змінної PhoneDatabase::phoneArray.
	* @param newSize присвоюється PhoneDatabase::phoneArray.
	*/
	void setPhoneArray(Phone *);

	/**
	* Зчитування розміру масиву з клавіатури та запис значення у поле PhoneDatabase::size.
	* @return зчитане значення поля PhoneDatabase::size.
	*/
	int inputSize();


	/**
	* Зчитування з консолі інформації та її запис
	* у поля передаваємого об'єкту.
	* @param newPhone - у поля об'єкту відбувається запис
	* інформації з консолі.
	*/
	void readPhone(Phone &) const;

	/**
	* Додавання об'єкту класу Phone у
	* масив PhoneDatabase::phoneArray.
	* @param addedPhone - додаваємий об'єкт.
	*/
	void addPhone(Phone &);

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
	void removePhone(const int);

	/**
	* Отримання по індексу посилання на елемент масиву
	* PhoneDatabase::phoneArray.
	* @param index - індекс отримуємого об'єкту.
	* @return посилення на елемент масиву.
	*/
	Phone& getPhone(const int);

	/**
	* Виведення на екран поточні значення полів
	* передаваємого об'єкту класу Phone.
	* @param printedPhone - поля об'єкту виводяться на екран.
	*/
	void printPhone(Phone &) const;

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

