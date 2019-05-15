#include "Phone.h"
#include "PhoneDatabase.h"

int main()
{
	{
		system("color B");
		cout << "Hello! Welcome to Lab #4 programm!" << endl;

		string fileName = "PhoneDatabaseFile.txt";
		PhoneDatabase comfyShop;
		comfyShop.readFromFile(fileName);

		Phone changeablePhone;
		function<bool(unsigned int, unsigned int)> direction;

		char choice = 0;
		cout << endl << "Database with phone datas is read from " << fileName << endl;

		cout << "Press ENTER to continue.";
		cin.get();

		while (choice != '0') {
			system("cls");
			cout << "Choose, what do you want do?" << endl << endl;
			cout << "1 - Add new data." << endl;
			cout << "2 - Delete phone data by index." << endl;
			cout << "3 - Get phone by index." << endl;
			cout << "4 - Display all items on screen." << endl;
			cout << "5 - Display current size of Phone array." << endl;
			cout << "6 - Get phone with the smallest resulotion." << endl;
			cout << "7 - Display all phones with two or more words in the title." << endl;
			cout << "8 - Sort phone array." << endl;
			cout << endl << "0 - Exit the program." << endl;

			choice = 0;
			int index;
			while (choice != '0' &&
				choice != '1' &&
				choice != '2' &&
				choice != '3' &&
				choice != '4' &&
				choice != '5' &&
				choice != '6' &&
				choice != '7' &&
				choice != '8') {
				cout << endl << "Option: ";
				cin >> choice;
			}

			switch (choice) {
			case '1': {
				comfyShop.readFromConsole(changeablePhone);
				comfyShop.addPhone(changeablePhone);
				cout << endl << "Done! New element was added!" << endl;

				cout << endl << "Press ENTER to continue.";
				cin.get();
				cin.get();
				break;
			}
			case '2': {
				index = comfyShop.inputIndex();
				comfyShop.removePhone(index);
				cout << "Done! Element with index " << index << " was removed!" << endl;

				cout << endl << "Press ENTER to continue.";
				cin.get();
				cin.get();
				break;
			}
			case '3': {
				index = comfyShop.inputIndex();
				changeablePhone = comfyShop.getPhone(index);
				cout << endl << "Phone with index: " << index << endl << endl;
				cout << changeablePhone.phoneToString() << endl;

				cout << endl << "Press ENTER to continue.";
				cin.get();
				cin.get();
				break;
			}
			case '4': {
				comfyShop.showAll();

				cout << endl << "Press ENTER to continue.";
				cin.get();
				cin.get();
				break;
			}
			case '5': {
				cout << "Current size of Phone array: " << comfyShop.getSize() << endl;

				cout << endl << "Press ENTER to continue.";
				cin.get();
				cin.get();
				break;
			}
			case '6': {
				changeablePhone = comfyShop.getSmallestResolutPhone();
				cout << endl << "Phone with the smallest resulotion:" << endl << endl;
				cout << changeablePhone.phoneToString() << endl;

				cout << endl << "Press ENTER to continue.";
				cin.get();
				cin.get();
				break;
			}
			case '7': {
				comfyShop.printPhonesMoreTwoWords();

				cout << endl << "Press ENTER to continue.";
				cin.get();
				cin.get();
				break;
			}
			case '8': {
				choice = 0;
				cout << "Choose how do you want to sort array:" << endl << endl <<
					"1 - Ascending." << endl << "0 - Descending." << endl;
				while (choice != '1' &&
					choice != '0') {
					cout << endl << "Option: ";
					cin >> choice;
				}

				switch (choice) {
				case '1': {
					direction = ascending;
					break;
				}
				case '0': {
					direction = descending;
					break;
				}
				}

				cout << "Choose the field to sort array:" << endl << endl <<
					"1 - Price." << endl << "2 - Resolution" << endl << "3 - Capacity" << endl;
				choice = 0;
				while (choice != '1' &&
					choice != '2' &&
					choice != '3') {
					cout << endl << "Option: ";
					cin >> choice;
				}
				switch (choice) {
				case '1': {
					comfyShop.sortByPrice(direction);
					break;
				}
				case '2': {
					comfyShop.sortByResolution(direction);
					break;
				}
				case'3': {
					comfyShop.sortByCapacity(direction);
				}
				}

				cout << "The array was sorted." << endl;

				cout << endl << "Press ENTER to continue.";
				cin.get();
				cin.get();
				break;
			}
			}
		}
		comfyShop.writeToFile(fileName);
		cout << "All data was written to " << fileName << endl << endl;

	}
	cout << "Press ENTER to exit.";

	cin.get();
	cin.get();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	return _CrtDumpMemoryLeaks();
}