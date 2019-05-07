/**
* @file PhoneDatabase.h
* ���������� ����� PhoneDatabase.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "phone.h"
#include <iostream>
#include <fstream>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::regex;
using std::regex_match;
using std::regex_search;

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
	/**
	* ����������� �� �������������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� ��� ������ ��'����.
	*/
	PhoneDatabase();

	/**
	* ����������� � �����������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� ������
	* �� ��������� ��������������� ��������� ���������.
	* @param newSize �������� ���� PhoneDatabase::size.
	* @param newPhoneArray. � ������������� ������ ����������
	* ��������� ��'���� ����� Phone � �������� �����
	* �� ��������� ��������������� ��������� ���������.
	*/
	PhoneDatabase(int newSize, Phone* newPhoneArray);

	/**
	* ����������� ���������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� ������
	* ��'���� ����� Phone � �������� �����
	* �� ��������� ��������������� ��������� ���������.
	* @param copiedPhoneDatabase: ����������� ���� ������ ��'���� 
	* ���������� ���� ������������.
	*/
	PhoneDatabase(const PhoneDatabase& copiedPhoneDatabase);

	/**
	* ����������. ��������� ������� ���'�� ��� ������.
	*/
	~PhoneDatabase();

	/**
	* ��������� ���� ����� PhoneDatabase.
	* @param newSize ������������ ���� PhoneDatabase::size.
	* @param newPhoneArray. � ������������� ������ ����������
	* ��������� ��'���� ����� Phone � �������� �����
	* �� ��������� ��������������� ��������� ���������.
	*/
	void setPhoneDatabaseInfo(int newSize, Phone* newPhoneArray);

	/**
	* ����� ��������� �������� ������ ��'���� ����� Phone � ������,
	* �� � ����� ��'���� ����� PhoneDatabase.
	* @param otherPhoneArr - �������� �� ����������� �����.
	* @param otherSize - ����� ������.
	* @return ������ ��������� �� ������ ��'����
	* ����� Phone: ��� �� �.
	*/
	bool comparisonPhoneArray(const Phone* otherPhoneArr, int otherSize) const;

	/**
	* ���������� ���� PhoneDatabase::size.
	* @return ������� �������� ���� PhoneDatabase::size.
	*/
	int getSize() const;

	/**
	* ���������� ���� PhoneDatabase::phoneArray.
	* @return ������� �������� ���� PhoneDatabase::phoneArray.
	*/
	const Phone * getPhoneArray() const;

	/**
	* �������� ����� �� ���������� �� ��������� ���������� ������.
	* @param checkString - ��������� �� �����, �� ������������.
	*/
	void correctCheckRegex(string& checkString) const;

	/**
	* �������� ����� �� ���������� �� ��������� ���������� ������.
	* @param checkString - �����, �� ������������.
	* @return ������ ���������� �����.
	*/
	bool isCorrectCheckRegex(string checkString) const;

	/**
	* ���������� � ������ ���������� �� �� �����
	* � ���� ������������ ��'����.
	* @param newPhone - � ���� ��'���� ���������� �����
	* ���������� � ������.
	*/
	void readFromConsole(Phone& newPhone) const;

	/**
	* ���������� � ����� ���������� ��� ����� ��'����.
	* @param fileName - ����� � ������ �����.
	*/
	void readFromFile(string fileName);

	/**
	* ����� � ���� ���������� � ������ PhoneDatabase::phoneArray.
	* @param fileName - ����� � ������ �����.
	*/
	void writeToFile(string fileName);

	/**
	* ��������� ��'���� ����� Phone �
	* ����� PhoneDatabase::phoneArray.
	* @param addedPhone - ��������� ��'���.
	*/
	void addPhone(Phone& addedPhone);

	/**
	* ���������� ������ ������� ������������ ��'���� ������.
	* @return ������� �������� �������.
	*/
	int inputIndex() const;

	/**
	* ��������� ��'���� ����� Phone �
	* ������ PhoneDatabase::phoneArray.
	* @param index - ������ ����������� ��'����.
	*/
	void removePhone(const int index);

	/**
	* ��������� �� ������� ��������� �� ������� ������
	* PhoneDatabase::phoneArray.
	* @param index - ������ ���������� ��'����.
	* @return ��������� �� ������� ������.
	*/
	Phone& getPhone(const int index);

	/**
	* ��������� �� ����� ���������� ��� ��
	* �������� ������ PhoneDatabase::phoneArray.
	*/
	void showAll() const;

	/**
	* ��������� ��������� �� ������� ������ ��'����
	* ����� Phone � ��������� �������� ������.
	* @return ��������� �� ������� ������.
	*/
	Phone& getSmallestResolutPhone() const;
};

