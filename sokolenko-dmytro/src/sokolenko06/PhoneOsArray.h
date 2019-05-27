/**
* @file PhoneArrayOs.h
* ���������� ����� PhoneOsArray.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "PhoneOs.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <utility>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::swap;
using std::function;

/**
* ���� ����� PhoneOsArray � ���� ������ �� ��������.
* ̳����� � ��� ����� ��'���� PhoneOs � ����� ����� ������.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class PhoneOsArray {
private:
	/** ����� ������ ��'����. */
	size_t size;
	/** �������� �� ����� ��'����. */
	PhoneOs * phoneOsArray;
public:
	/**
	* ����������� �� �������������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� ��� ������ ��'����.
	*/
	PhoneOsArray();

	/**
	* ����������� � �����������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� ������
	* �� ��������� ��������������� ��������� ���������.
	* @param newSize �������� ���� PhoneOsArray::size.
	* @param newPhoneOsArray. � ������������� ������ ����������
	* ��������� ��'���� ����� PhoneOs � �������� �����
	* �� ��������� ��������������� ��������� ���������.
	*/
	PhoneOsArray(size_t newSize, PhoneOs* newPhoneOsArray);

	/**
	* ����������� ���������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� ������
	* ��'���� ����� PhoneOs � �������� �����
	* �� ��������� ��������������� ��������� ���������.
	* @param copiedPhoneOsArray: ����������� ���� ������ ��'����
	* ���������� ���� ������������.
	*/
	PhoneOsArray(const PhoneOsArray& copiedPhoneOsArray);

	/**
	* ����������. ��������� ������� ���'�� ��� ������.
	*/
	~PhoneOsArray();

	/**
	* ���������� ���� PhoneArray::size.
	* @return ������� �������� ���� PhoneArray::size.
	*/
	size_t getSize() const;

	/**
	* ���������� ���� PhoneArray::phoneArray.
	* @return ������� �������� ���� PhoneArray::phoneArray.
	*/
	const PhoneOs* getPhoneOsArray() const;

	/**
	* �����, �� �������� ����� �� ���������� �� ��������� ���������� ������.
	* @param checkString - �����, �� ������������.
	* @return ������ ���������� �����.
	*/
	bool isCorrectCheckRegex(string& checkString) const;

	/**
	* ���������� � ������ ���������� �� �� �����
	* � ���� ������������ ��'����.
	* @param newPhone - � ���� ��'���� ���������� �����
	* ���������� � ������.
	*/
	void readFromConsole(PhoneOs& newPhoneOs) const;

	/**
	* ���������� � ����� ���������� ��� ����� ��'����.
	* @param fileName - ����� � ������ �����.
	*/
	void readFromFile(string fileName);

	/**
	* ����� � ���� ���������� � ������ PhoneArray::phoneArray.
	* @param fileName - ����� � ������ �����.
	*/
	void writeToFile(string fileName);

	/**
	* ��������� ��'���� ����� Phone �
	* ����� PhoneArray::phoneArray.
	* @param addedPhone - ��������� ��'���.
	*/
	void addPhone(PhoneOs& addedPhoneOs);

	/**
	* ���������� ������ ������� ������������ ��'���� ������.
	* @return ������� �������� �������.
	*/
	int inputIndex() const;

	/**
	* ��������� ��'���� ����� Phone �
	* ������ PhoneArray::phoneArray.
	* @param index - ������ ����������� ��'����.
	*/
	void removePhoneOs(const int index);

	/**
	* ��������� �� ������� ��������� �� ������� ������
	* PhoneArray::phoneArray.
	* @param index - ������ ���������� ��'����.
	* @return ��������� �� ������� ������.
	*/
	PhoneOs& getPhoneOs(const int index);

	/**
	* ��������� �� ����� ���������� ��� ��
	* �������� ������ PhoneArray::phoneArray.
	*/
	void showAll() const;
};
