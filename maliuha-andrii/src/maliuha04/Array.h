/**
* @file workingProgram.h
* объявление класса workingProgram
* @author Maliuga Andrey
* @version 0.6
* @date 30.03.2019
*/

#pragma once
#include "Main.h"

/**
* Описание класса Arry с его полями и методами.
* Класс Array создан для хранения указателя на массив и использование методов для его обработки.
*/
class Array {
private:
	/** Размер массива. */
	int size;

	/** Указатель на массив. */
	WorkingProgram *mas;
public:
	Array();
	void writeToFile();
	void readFromFile(ifstream &objects, string &info, string &n);
	void setInfoObj(string &info);
	void addProgram(WorkingProgram &newObj, int ind);
	void showAll();
	void removeProgram(int ind);
	void getProgram(int ind);
	void nameSearch(string n);
	void findProgram(float memoryGB);
	void removeViruses();
	void delMas();
	int getSize();


	bool inputCheck(string str);
	void sortOutput();
};
