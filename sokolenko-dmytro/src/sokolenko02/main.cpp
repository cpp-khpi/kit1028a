#include "Phone.h"
#include "PhoneDatabase.h"

int main()
{
	{
		cout << "Hello! Welcome to Lab #2 programm!" << endl;
		system("color B");

		PhoneDatabase comfyShop;
		Phone changeablePhone;

		char choice = 0;
		cout << endl << endl << "Database with phone datas is created." << endl;
		while (choice != '0') {
			cout << endl << endl << "Choose, what do you want do?" << endl << endl;
			cout << "1 - Add new data." << endl;
			cout << "2 - Delete phone data by index." << endl;
			cout << "3 - Get phone by index." << endl;
			cout << "4 - Display all items on screen." << endl;
			cout << "5 - Display current size of Phone array." << endl;
			cout << "6 - Get phone with the smallest resulotion" << endl;
			cout << endl << "0 - Exit the program." << endl;

			choice = 0;
			int index;
			for (; choice != '0' && choice != '1' && choice != '2' && choice != '3'
				&& choice != '4' && choice != '5' && choice != '6'; ) {
				cout << endl << "Option: ";
				cin >> choice;
			}

			switch (choice) {
			case '1': {
				comfyShop.readPhone(changeablePhone);
				comfyShop.addPhone(changeablePhone);
				cout << "Done! New element was added!" << endl;
				break;
			}
			case '2': {
				index = comfyShop.inputIndex();
				comfyShop.removePhone(index);
				cout << "Done! Element with index " << index << " was removed!" << endl;
				break;
			}
			case '3': {
				index = comfyShop.inputIndex();
				changeablePhone = comfyShop.getPhone(index);
				cout << endl << endl << "Phone with index: " << index << endl << endl;
				comfyShop.printPhone(changeablePhone);
				break;
			}
			case '4': {
				comfyShop.showAll();
				break;
			}
			case '5': {
				cout << "Current size of Phone array: " << comfyShop.getSize() << endl;
				break;
			}
			case '6': {
				changeablePhone = comfyShop.getSmallestResolutPhone();
				cout << endl << endl << "Phone with the smallest resulotion:" << endl << endl;
				comfyShop.printPhone(changeablePhone);
				break;
			}
			}
		}
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