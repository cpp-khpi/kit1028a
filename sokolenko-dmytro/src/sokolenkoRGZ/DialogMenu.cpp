#include "DialogMenu.h"

void DialogMenu::startProgram()
{
	system("color B");
	cout << "Hello! Welcome to Lab #7 programm!" << endl;

	phoneShop.readFromFile(fileName);

	char choice = 0;
	cout << endl << "Database with phone datas is read from " << fileName << endl <<
		"Press ENTER to continue.";
	cin.get();
}

char DialogMenu::printMenue()
{
	system("cls");
	cout << "Choose, what do you want do?" << endl << endl <<
		"1 - Add new data." << endl <<
		"2 - Delete phone data by index." << endl <<
		"3 - Get phone by index." << endl <<
		"4 - Display all items on screen." << endl <<
		"5 - Display current size of Phone array." << endl <<
		"6 - Get phone with the smallest resulotion." << endl <<
		"7 - Sort phone array." << endl <<
		endl << "0 - Exit the program." << endl;

	char choice = 0;
	while (choice != '0' &&
		choice != '1' &&
		choice != '2' &&
		choice != '3' &&
		choice != '4' &&
		choice != '5' &&
		choice != '6' &&
		choice != '7') {
		cout << endl << "Option: ";
		cin >> choice;
	}

	return choice;
}

void DialogMenu::addPhone()
{
	char choice = 0;
	cout << "Choose what Phone type do you want to add:" <<
		endl << endl << "1 - phone with Android." << endl << "2 - phone with IOS." << endl;

	while (choice != '1' &&
		choice != '2') {
		cout << endl << "Option: ";
		cin >> choice;
	}

	switch (choice) {
	case '1': {
		changeablePhone = new AndroidPhone;
		changeablePhone->input();
		phoneShop.addPhone(changeablePhone);
		break;
	}
	case '2': {
		changeablePhone = new IosPhone;
		changeablePhone->input();
		phoneShop.addPhone(changeablePhone);
		break;
	}
	}

	cout << endl << "Done! New element was added!" << endl <<
		endl << "Press ENTER to continue.";

	cin.get();
	cin.get();
}

void DialogMenu::deletePhone()
{
	int index;
	index = phoneShop.inputIndex();
	phoneShop.removePhone(index);
	cout << "Done! Element with index " << index << " was removed!" << endl <<
		endl << "Press ENTER to continue.";

	cin.get();
	cin.get();
}

void DialogMenu::getByIndex()
{
	int index;
	index = phoneShop.inputIndex();
	*changeablePhone = phoneShop[index];
	cout << endl << "Phone with index: " << index << endl <<
		endl << *changeablePhone << endl <<
		endl << "Press ENTER to continue.";

	cin.get();
	cin.get();
}

void DialogMenu::displayAllElements()
{
	phoneShop.showAll();

	cout << endl << "Press ENTER to continue.";
	cin.get();
	cin.get();
}

void DialogMenu::displayCurrentSize()
{
	cout << "Current size of Phone array: " << phoneShop.getSize() << endl <<
		endl << "Press ENTER to continue.";

	cin.get();
	cin.get();
}

void DialogMenu::displaySmallestResolutPhone()
{
	changeablePhone = phoneShop.getSmallestResolutPhone();
	cout << endl << "Phone with the smallest resulotion:" << endl << endl <<
		*changeablePhone << endl <<
		endl << "Press ENTER to continue.";

	cin.get();
	cin.get();
}

void DialogMenu::writeToFile()
{
	phoneShop.writeToFile(fileName);
	cout << "All data was written to " << fileName << endl << endl <<
		"Press ENTER to exit.";

	cin.get();
	cin.get();
}

void DialogMenu::allActions()
{
	startProgram();

	char choice = 0;

	while (printMenue() != '0') {
		switch (choice) {
		case '1': {
			addPhone();
			break;
		}
		case '2': {
			deletePhone();
			break;
		}
		case '3': {
			getByIndex();
			break;
		}
		case '4': {
			displayAllElements();
			break;
		}
		case '5': {
			displayCurrentSize();
			break;
		}
		case '6': {
			displaySmallestResolutPhone();
			break;
		}
		}
		writeToFile();
	}
}