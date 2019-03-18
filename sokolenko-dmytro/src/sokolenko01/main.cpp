#include "Phone.h"
#include "PhoneDatabase.h"

int main()
{
	cout << "Hello! Please, choose what do you want to do:" << endl;
	cout << "1 - Enter in the database phones datas." << endl;
	cout << "0 - Exit the program." << endl;

	char choice = 0;
	for (; choice != '0' && choice != '1'; ) {
		cout << "Option: ";
		cin >> choice;
	}
	switch (choice) {
	case '0': {
		cout << "Press any key to exit.";
		cin.get();
		cin.get();
		exit(0);
	}
	case '1': {
		cout << endl << endl << "!START PROGRAM!" << endl << endl;
		system("color B");
		break;
	}
	}

	PhoneDatabase comfyShop;
	int size = comfyShop.inputSize();
	comfyShop.createArray(size);

	cout << endl << endl << "Database with phone datas is created." << endl;
	while (true) {
		cout << endl << endl << "Choose, what do you want do?" << endl << endl;
		cout << "1 - Add new data." << endl;
		cout << "2 - Delete phone data by index." << endl;
		cout << "3 - Get phone data by index." << endl;
		cout << "4 - Display all items on screen." << endl;
		cout << endl << "0 - Exit the program." << endl;

		choice = 0;
		int index;
		for (; choice != '0' && choice != '1' && choice != '2' && choice != '3' && choice != '4'; ) {
			cout << endl << "Option: ";
			cin >> choice;
		}
		switch (choice) {
		case '0': {
			cout << "Press any key to exit.";

			comfyShop.deleteArray();

			_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
			_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
			_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
			_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
			_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
			_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
			_CrtDumpMemoryLeaks();

			cin.get();
			cin.get();

			return 0;
		}
		case '1': {
			Phone * tmpPhone = new Phone;
			comfyShop.readPhone(*tmpPhone);
			comfyShop.addPhone(*tmpPhone);
			cout << "Done! New element was added!" << endl;
			delete tmpPhone;
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
			Phone tmp = comfyShop.getPhone(index);
			cout << endl << endl << "Phone with index: " << index << endl << endl;
			comfyShop.printPhone(&tmp);
			break;
		}
		case '4': {
			comfyShop.showAll();
			break;
		}
		}
	}
}