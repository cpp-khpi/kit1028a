/**
* @file workingProgram.h
* объявление класса workingProgram
* @author Maliuga Andrey
* @version 0.6
* @date 30.03.2019
*/



#pragma once
#include "Header.h"

/**
* Описание класса workingProgram с его полями и методами.
* Класс workingProgram создан для описания работающей программы.
*/
class workingProgram {
private:
	
	/** Название программы */
	string name;

	/** Компания или разработчик программы. */
	string publisher;
	
	/** Количество оперативной памяти, которое требует программа. */
	float opMemoryMb;
	
	/** Количество физической памяти, которое занимает программа. */
	float memoryGb;
	
	/** Время работы программы в данный момент. */
	float timeWorkMin;

public:
	
	/**
	* Конструктор по умолчанию.
	* Используется список иницализации.
	*/
	workingProgram();

	/** 
	* Метод, который выводит значение полей объекта на экран.
	*/
	stringstream print();


	/**
	* Метод, который заполняет значения полей объекта.
	* @param info хранит информацию о новом объекте.
	*/
	void setObj(string &info);

	/**
	* Установка поля workingProgram::name.
	* @param name присваивается полю workingProgram::name.
	*/
	void setName(string name);

	/**
	* Установка поля workingProgram::publisher.
	* @param publisher присваивается полю workingProgram::publisher.
	*/
	void setPublisher(string publisher);

	/** 
	* Установка поля workingProgram::opMemoryMd.
	* @param opMemoryMd присваивается полю workingProgram::opMemoryMd.
	*/
	void setOpMemoryMb(float opMemoryMb);

	/**
	* Установка поля workingProgram::memoryGd.
	* @param memoryGd присваивается полю workingProgram::memoryGd.
	*/
	void setMemoryGb(float memoryGd);

	/**
	* Установка поля workingProgram::timeWorkMin.
	* @param timeWorkMin присваивается полю workingProgram::timeWorkMin.
	*/
	void setTimeWorkMin(float timeWorkMin);

	/**
	* Чтение поля workingProgram::name.
	* @return текущее значение поля workingProgram::name.
	*/
	string getName();

	/**
	* Чтение поля workingProgram::publisher.
	* @return текущее значение поля workingProgram::publisher.
	*/
	string getPublisher();

	/**
	* Чтение поля workingProgram::opMemoryMd.
	* @return текущее значение поля workingProgram::opMemoryMd.
	*/
	float getOpMemoryMb();

	/**
	* Чтение поля workingProgram::memoryGd.
	* @return текущее значение поля workingProgram::memoryGd.
	*/
	float getMemoryGb();

	/**
	* Чтение поля workingProgram::timeWorkMin.
	* @return текущее значение поля workingProgram::timeWorkMin.
	*/
	float getTimeWorkMin();
};
