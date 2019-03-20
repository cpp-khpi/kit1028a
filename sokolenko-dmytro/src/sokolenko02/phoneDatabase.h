#pragma once

#include <iostream>
#include "phone.h"

using std::cin;
using std::cout;
using std::endl;


/**
* ���� ����� PhoneDatabase � ���� ������ �� ��������.
* ̳����� � ��� ����� ��'���� Phone � ����� ����� ������.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class PhoneDatabase {
	/** ����� ������ ��'����. */
	int size;
	/** �������� �� ����� ��'����. */
	Phone * phoneArray;
public:
	PhoneDatabase();
	PhoneDatabase(int, Phone *);
	PhoneDatabase(const PhoneDatabase &);
	~PhoneDatabase();
	
	/**
	* ���������� ���� PhoneDatabase::size.
	* @return ������� �������� ���� PhoneDatabase::size.
	*/
	int getSize();

	/**
	* ������������ ������� ����� PhoneDatabase::size.
	* @param newSize ������������ PhoneDatabase::size.
	*/
	void setSize(unsigned int);

	/**
	* ���������� ���� PhoneDatabase::phoneArray.
	* @return ������� �������� ���� PhoneDatabase::phoneArray.
	*/
	Phone * getPhoneArray();

	/**
	* ������������ ������� ����� PhoneDatabase::phoneArray.
	* @param newSize ������������ PhoneDatabase::phoneArray.
	*/
	void setPhoneArray(Phone *);

	/**
	* @brief ���������� ������ ������ � ���������.
	* ���������� ������ ������ � ��������� �� ����� �������� � ���� PhoneDatabase::size.
	* @return ������� �������� ���� PhoneDatabase::size.
	*/
	int inputSize();

	void readPhone(Phone &) const;


	void addPhone(Phone &);

	int inputIndex() const;

	void removePhone(const int);

	Phone& getPhone(const int);

	void printPhone(Phone &) const;

	void showAll() const;

	void deleteArray();
};

