#include "DoHomework.h"

void DoHomework::set_size(int size) {
	DoHomework::size = size;
}
void DoHomework::read_from_file(std::string *person) {
	std::regex regex_firstSymbol("^[A-Z]");
	std::regex regex_spaces("[\\s]{2,}");
	std::ifstream fin;
	fin.open("StudentsSurname.txt");
	for (int k = 0; k < size; k++) {
		getline(fin, person[k]);
		if (!(regex_search(person[k], regex_firstSymbol)) || regex_search(person[k], regex_spaces)) {
			std::cout << "Incorrect entry, writing with large letters(A - Z) : " << person[k] << std::endl;
			std::cin.ignore();
			getline(std::cin, person[k]);
		}
	}
	fin.close();
}
void DoHomework::new_array(std::string *person) {
	arr = new Homework[size];
	for (int i = 0; i < size; i++) {
		arr[i].generation_values(person[i]);
	}
}
void DoHomework::print() {
	for (int i = 0; i < size; i++) {
		std::cout << "Student info: " << arr[i].get_person() << std::endl;
		std::cout << "Amount of independent works: " << arr[i].get_amount() << std::endl;
		std::cout << "Amount of written independent works: " << arr[i].get_written() << std::endl;
		std::cout << "Student mark (average): " << arr[i].get_mark() << std::endl;
		std::cout << "Student homework: " << arr[i].get_homework() << std::endl << std::endl;
	}
}
void DoHomework::add_elem(int amount, int written, int mark, int homework_count, std::string person) {

	Homework *mas = new Homework[size + 1];

	for (int i = 0; i < size; i++) {
		mas[i] = DoHomework::arr[i];
	}

	size++;

	mas[size - 1].set_data(amount, written, mark, homework_count ,person);

	delete[] arr;
	arr = mas;
}
void DoHomework::delete_elem(int l) {
	if (size < 2) {
		std::cout << "                Error              " << std::endl;
		std::cout << " You cant delete last element " << std::endl;
		system("pause");
		return;
	}
	if (l - 1 >= size) {
		std::cout << "                Error              " << std::endl;
		std::cout << " You cant enter index more then size of array " << std::endl;
		system("pause");
		return;
	}

	size--;
	Homework* mas = new Homework[size];

	int j = 0;
	for (int i = 0; i < l - 1; i++) {
		mas[i] = DoHomework::arr[j];
		j++;
	}
	j++;
	for (int i = l - 1; i < size; i++) {
		mas[i] = DoHomework::arr[j];
		j++;
	}
	delete[]arr;
	arr = mas;
}
void DoHomework::get_by_index(int index) {
	if (index - 1 >= size) {
		std::cout << std::endl << "Error" << std::endl << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << "Student info: " << arr[index - 1].get_person() << std::endl;
	std::cout << "Amount of independent works: " << arr[index - 1].get_amount() << std::endl;
	std::cout << "Amount of written independent works: " << arr[index - 1].get_written() << std::endl;
	std::cout << "Student mark (average): " << arr[index - 1].get_mark() << std::endl << std::endl;
	std::cout << "Student homework: " << arr[index - 1].get_homework() << std::endl << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl << std::endl;
}
void DoHomework::write_to_file() {
	std::ofstream fout;
	fout.open("InfoStud.txt");
	for (int i = 0; i < size; i++) {
		fout << "Student info: " << arr[i].get_person() << std::endl;
		fout << "Amount of independent works: " << arr[i].get_amount() << std::endl;
		fout << "Amount of written independent works: " << arr[i].get_written() << std::endl;
		fout << "Student mark (average): " << arr[i].get_mark() << std::endl;
		fout << "Student homework : " << arr[i].get_homework() << std::endl << std::endl;
	}
	fout.close();
}
void DoHomework::delete_array() {
	delete[]arr;
}
void DoHomework::search_by_surname(std::string search_person) {
	for (int i = 0; i < size; i++) {
		if (search_person == arr[i].get_person()) {
			std::cout << std::endl;
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
			std::cout << "Student info: " << arr[i].get_person() << std::endl;
			std::cout << "Amount of independent works: " << arr[i].get_amount() << std::endl;
			std::cout << "Amount of written independent works: " << arr[i].get_written() << std::endl;
			std::cout << "Student mark (average): " << arr[i].get_mark() << std::endl << std::endl;
			std::cout << "Student homework: " << arr[i].get_homework() << std::endl << std::endl;
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
		}
	}
}
void DoHomework::sort_by_mark(bool(*sort)(int a, int b)) {
	Homework temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sort(arr[i].get_mark(), arr[j].get_mark())) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void DoHomework::sort_by_amount(bool(*sort)(int a, int b)) {
	Homework temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sort(arr[i].get_amount(), arr[j].get_amount())) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void DoHomework::sort_by_written(bool(*sort)(int a, int b)) {
	Homework temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sort(arr[i].get_written(), arr[j].get_written())) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void DoHomework::sort_by_homework(bool(*sort)(int a, int b)) {
	Homework temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sort(arr[i].get_homework(), arr[j].get_homework())) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}