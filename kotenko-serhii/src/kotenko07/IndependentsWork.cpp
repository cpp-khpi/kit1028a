#include "IndependentsWork.h"
#include "Homework.h"
#include "Classwork.h"

IndependentsWork::IndependentsWork() : size(0) {
	arr = nullptr;
}
IndependentsWork::~IndependentsWork() {
	for (int i = 0; i < size; i++) {
		delete arr[i];
	}
	delete[] arr;
}
void IndependentsWork::set_size(int size) {
	IndependentsWork::size = size;
}
void IndependentsWork::read_from_file(int new_size) {
	srand(time(NULL));
	std::string *person = new std::string[new_size];
	std::regex regex_firstSymbol("^[A-Z]");
	std::regex regex_spaces("[\\s]{2,}");
	std::ifstream fin;
	fin.open("StudentsSurname.txt");
	InfoIndependentsWork* new_work;
	int choice;
	for (int k = 0; k < new_size; k++) {
		getline(fin, person[k]);
		if (!(regex_search(person[k], regex_firstSymbol)) || regex_search(person[k], regex_spaces)) {
			std::cout << "Incorrect entry, writing with large letters(A - Z): " << person[k] << std::endl;
			std::cin.ignore();
			getline(std::cin, person[k]);
		}	
		choice = rand() % 2;
		switch (choice) {
		case 0: 
			new_work = new Homework;
			new_work->generation_values(person[k]);
			add_elem(new_work);
			break;
		case 1: 
			new_work = new Classwork;
			new_work->generation_values(person[k]);
			add_elem(new_work);
			break;
	    }
	}

	delete[] person;
	fin.close();
}
void IndependentsWork::print() {
	for (int i = 0; i < size; i++) {
		arr[i]->output();
	}
}
void IndependentsWork::add_elem(InfoIndependentsWork* new_work) {

	InfoIndependentsWork **mas = new InfoIndependentsWork*[size + 1];

	for (int i = 0; i < size; i++) {
		mas[i] = arr[i];
	}

	size++;

	mas[size - 1] = new_work;

	delete[] arr;
	arr = mas;
}
void IndependentsWork::delete_elem(int l) {
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
	InfoIndependentsWork** mas = new InfoIndependentsWork*[size];

	int j = 0;
	for (int i = 0; i < l - 1; i++) {
		mas[i] = arr[j];
		j++;
	}
	j++;
	for (int i = l - 1; i < size; i++) {
		mas[i] = arr[j];
		j++;
	}
	delete arr[l - 1];
	delete[]arr;
	arr = mas;
}
void IndependentsWork::get_by_index(int index) {
	if (index - 1 >= size) {
		std::cout << std::endl << "Error" << std::endl << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	arr[index - 1]->output();
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl << std::endl;
}
void IndependentsWork::write_to_file() {
	std::ofstream fout;
	fout.open("InfoStud.txt");
	for (int i = 0; i < size; i++) {
		arr[i]->output_to_file(fout);
	}
	fout.close();
}
void IndependentsWork::search_by_surname(std::string search_person) {
	for (int i = 0; i < size; i++) {
		if (search_person == arr[i]->get_person()) {
			std::cout << std::endl;
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
			arr[i]->output();
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
		}
	}
}
void IndependentsWork::sort_by_mark(bool(*sort)(int a, int b)) {
	InfoIndependentsWork *temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sort(arr[i]->get_mark(), arr[j]->get_mark())) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void IndependentsWork::sort_by_amount(bool(*sort)(int a, int b)) {
	InfoIndependentsWork *temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sort(arr[i]->get_amount(), arr[j]->get_amount())) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void IndependentsWork::sort_by_written(bool(*sort)(int a, int b)) {
	InfoIndependentsWork *temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sort(arr[i]->get_written(), arr[j]->get_written())) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}