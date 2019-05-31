#include "Phone.h"
#include "PhoneArray.h"
#include "IosPhone.h"
#include "AndroidPhone.h"
#include "Utilit.h"

int main()
{
	{
		system("color B");
		cout << "Hello! Welcome to Lab #7 programm!" << endl;

		string fileName = "PhoneDatabaseFile.txt";
		PhoneArray comfyShop;
		Phone* changeablePhone = nullptr;
		comfyShop.readFromFile(fileName);

		char choice = 0;
		cout << endl << "Database with phone datas is read from " << fileName << endl <<
		"Press ENTER to continue.";
		cin.get();

		while (choice != '0') {
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

			choice = 0;
			int index;
			while (choice != '0' &&
				choice != '1' &&
				choice != '2' &&
				choice != '3' &&
				choice != '4' &&
				choice != '5' &&
				choice != '6' &&
				choice != '7' ) {
				cout << endl << "Option: ";
				cin >> choice;
			}

			switch (choice) {
			case '1': {
				choice = 0;
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
					comfyShop.addPhone(changeablePhone);
					break;
				}
				case '2': {
					changeablePhone = new IosPhone;
					changeablePhone->input();
					comfyShop.addPhone(changeablePhone);
					break;
				}
				}

				cout << endl << "Done! New element was added!" << endl <<
					endl << "Press ENTER to continue.";

				cin.get();
				cin.get();
				break;
			}
			case '2': {
				index = comfyShop.inputIndex();
				comfyShop.removePhone(index);
				cout << "Done! Element with index " << index << " was removed!" << endl <<
					endl << "Press ENTER to continue.";

				cin.get();
				cin.get();
				break;
			}
			case '3': {
				index = comfyShop.inputIndex();
				*changeablePhone = comfyShop[index];
				cout << endl << "Phone with index: " << index << endl << 
					endl << *changeablePhone << endl <<
					endl << "Press ENTER to continue.";

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
				cout << "Current size of Phone array: " << comfyShop.getSize() << endl <<
					endl << "Press ENTER to continue.";
				
				cin.get();
				cin.get();
				break;
			}
			case '6': {
				changeablePhone = comfyShop.getSmallestResolutPhone();
				cout << endl << "Phone with the smallest resulotion:" << endl << endl <<
					*changeablePhone << endl <<
					endl << "Press ENTER to continue.";
				
				cin.get();
				cin.get();
				break;
			}
			case '7': {
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
					choice = 0;
					cout << "Choose according to what field do you want to sort ascending array:" <<
						endl << endl << "1 - Price." << endl << "2 - Resolution." <<
						endl << "3 - Capacity" << endl;

					while (choice != '1' &&
						choice != '2' &&
						choice != '3') {
						cout << endl << "Option: ";
						cin >> choice;
					}

					switch (choice) {
					case '1': {
						comfyShop.sort(ascendingPrice);
						break;
					}
					case '2': {
						comfyShop.sort(ascendingResolution);
						break;
					}
					case '3': {
						comfyShop.sort(ascendingCapacity);
						break;
					}
					}
					break;
				}
				case '2': {
					choice = 0;
					cout << "Choose according to what field do you want to sort descending array:" <<
						endl << endl << "1 - Price." << endl << "2 - Resolution." <<
						endl << "3 - Capacity" << endl;

					while (choice != '1' &&
						choice != '2' &&
						choice != '3') {
						cout << endl << "Option: ";
						cin >> choice;
					}

					switch (choice) {
					case '1': {
						comfyShop.sort(descendingPrice);
						break;
					}
					case '2': {
						comfyShop.sort(descendingResolution);
						break;
					}
					case '3': {
						comfyShop.sort(descendingCapacity);
						break;
					}
					}
					break;
				}
				}

				cout << endl << "Press ENTER to continue.";
				cin.get();
				cin.get();
				break;
			}
			}
		}
		comfyShop.writeToFile(fileName);
		cout << "All data was written to " << fileName << endl << endl <<
			"Press ENTER to exit.";

		cin.get();
		cin.get();
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	return _CrtDumpMemoryLeaks();
}