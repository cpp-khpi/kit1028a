#pragma once

#include "PhoneArray.h"
#include "Utilit.h"

class DialogMenu {
private:
	/** PhoneArray object. */
	PhoneArray phoneShop;
	/** Temporary pointer. */
	Phone* changeablePhone = nullptr;
	/** File name for reading and writing. */
	string fileName = "PhoneDatabaseFile.txt";

	/** Color setting, reading from file. */
	void startProgram();

	/** Print menu, choose option. */
	char printMenue();

	/** Reading Phone from console, add to array. */
	void addPhone();

	/** Entering index, delete element by index. */
	void deletePhone();

	/** Get by index. */
	void getByIndex();

	/** Display all elements on the screen. */
	void displayAllElements();

	/** Display current size of array. */
	void displayCurrentSize();

	/** Display phone with smallest resolution */
	void displaySmallestResolutPhone();

	/** Write to file all data. */
	void writeToFile();
public:
	/** Method with all DialogMenu methods. */
	void allActions();
};