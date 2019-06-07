/**
* @file Dialog.cpp
* Implementation of all functions of Dialog class.
* @author Kononenko Dmytro
* @version 1.0
* @date 2019.06.06
*/

#include "Dialog.h"

void Dialog::getRate() {
	cout << "The percentage of graduate work compared to undergraduate work: ";
	cout << obj.rate();
}

void Dialog::print(){
	string address;
	cout << "Input address of file: ";
	cin >> address;

	obj.print();
	obj.writeToFile(address);
}

void Dialog::createArr() {
	int size;
	string address;
	cout << "Input address of file: ";
	cin >> address;
	cout << "Number of elements you want to read: ";
	cin >> size;
	obj.readFromFile(size, address);
}

void Dialog::sortArr() {
	int choose;
	cout << "By what criteria do you want to sort: " << endl;
	cout << "1. By mark" << endl;
	cout << "2. By size" << endl;
	cout << "3. By type" << endl;
	cout << "Choose: ";
	cin >> choose;

	switch (choose) {
	case 1:
		obj.sortByMark();
		break;
	case 2:
		obj.sortBySize();
		break;
	case 3:
		obj.sortByType();
		break;
	}
}

void Dialog::Del() {
	int index;
	cout << "Input index of elemen which you want to delete: ";
	cin >> index;
	obj.delElem(index);
}

void Dialog::Add() {
	int choose;
	InfoWork *temp;

	cout << "Input type of new element: ";
	cout << "1. CourseWork" << endl;
	cout << "2. DetailInfo" << endl;
	cin >> choose;

	switch (choose) {
	case 1:
		temp = new CourseWork;
		temp->input();
		obj.addElem(temp);
		delete temp;
		break;
	case 2:
		temp = new DetailInfo;
		temp->input();
		obj.addElem(temp);
		delete temp;
		break;
	}
}
