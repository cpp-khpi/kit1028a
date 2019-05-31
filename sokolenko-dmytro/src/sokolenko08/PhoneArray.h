/**
* @file PhoneArray.h
* ���������� ����� PhoneArray.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"
#include "IosPhone.h"
#include "AndroidPhone.h"
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
* ���� ����� PhoneArray � ���� ������ �� ��������.
* ̳����� � ��� ����� ��'���� Phone � ����� ����� ������.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class PhoneArray {
private:
	/** ����� ������ ��'����. */
	size_t size;
	/** �������� �� ����� ���������. */
	Phone** phoneArray;
public:
	/**
	* ����������� �� �������������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� ��� ������ ��'����.
	*/
	PhoneArray();

	/**
	* ����������� � �����������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� ������
	* �� ��������� ��������������� ��������� ���������.
	* @param newSize �������� ���� PhoneArray::size.
	* @param newPhoneArray. � ������������� ������ ����������
	* ��������� ��'���� ����� Phone � �������� �����
	* �� ��������� ��������������� ��������� ���������.
	*/
	PhoneArray(size_t newSize, Phone** newPhoneArray);

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
	PhoneArray(const PhoneArray& copiedPhoneDatabase);

	/**
	* ����������. ��������� ������� ���'�� ��� ������.
	*/
	~PhoneArray();

	/**
	* ������ �� ��������� �������� ������ �� ��������.
	* @return ��������� �� ��'��� � i-��� ��������.
	*/
	Phone& operator[] (const unsigned int index);

	/**
	* �������� �����, �� ������ ����� � ����������� ��� ��'���
	* � �� ���� ����� �������� ���� ��'����.
	* @param out - ��������� �� ���� �����
	* @param outputPhone - ��������� �� ��'��� Phone.
	* @return ��������� �� ���� �����.
	*/
	friend istream& operator>>(istream& in, PhoneArray& inputPhone);

	/**
	* �������� ������, �� �������� ������� ����� 
	* (��� ������� ������ ������) � ����������� ��� ��'����.
	* @param out - ��������� �� ���� ������
	* @param outputPhoneArray - ��������� �� ��'��� PhoneArray.
	* @return ��������� �� ���� ������.
	*/
	friend ostream& operator<<(ostream& out, const PhoneArray& outputPhoneArray);

	/**
	* ��������� ���� ����� PhoneArray.
	* @param newSize ������������ ���� PhoneArray::size.
	* @param newPhoneArray. � ������������� ������ ����������
	* ��������� ��'���� ����� Phone � �������� �����
	* �� ��������� ��������������� ��������� ���������.
	*/
	void setPhoneDatabaseInfo(size_t newSize, Phone* newPhoneArray);

	/**
	* ����� ��������� �������� ������ ��'���� ����� Phone � ������,
	* �� � ����� ��'���� ����� PhoneArray.
	* @param otherPhoneArr - �������� �� ����������� �����.
	* @param otherSize - ����� ������.
	* @return ������ ��������� �� ������ ��'����
	* ����� Phone: ��� �� �.
	*/
	bool comparisonPhoneArray(const Phone* otherPhoneArr, size_t otherSize) const;

	/**
	* ���������� ���� PhoneArray::size.
	* @return ������� �������� ���� PhoneArray::size.
	*/
	size_t getSize() const;

	/**
	* ���������� ���� PhoneArray::phoneArray.
	* @return ������� �������� ���� PhoneArray::phoneArray.
	*/
	Phone** getPhoneArray() const;

	/**
	* �����, �� �������� ����� �� ���������� �� ��������� ���������� ������.
	* @param checkString - �����, �� ������������.
	* @return ������ ���������� �����.
	*/
	bool isCorrectCheckRegex(string& checkString) const;

	/**
	* �����, �� �������� �� ����� ������ ���
	* �ᒺ���, �� ����� ���� ��� ����� ���� �  
	* ���������� ����� �������.
	*/
	void printPhonesMoreTwoWords() const;

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
	* @param addedPhone - �������� �� ��������� ��'���.
	*/
	void addPhone(Phone* addedPhone);

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
	void removePhone(const unsigned int index);

	/**
	* ��������� �� ����� ���������� ��� ��
	* �������� ������ PhoneArray::phoneArray.
	*/
	void showAll() const;

	/**
	* ��������� ��������� �� ������� ������ ��'����
	* ����� Phone � ��������� �������� ������.
	* @return ��������� �� ������� ������.
	*/
	Phone* getSmallestResolutPhone() const;

	/**
	* �����, �� ������� ����� ��������
	* ���� Phone �� �������, ��� ���������� ���������� �� �������.
	* @param comparFunc: ������� �������, �� ������� 
	* ��������� ����������.
	*/
	void sort(function<bool(Phone*, Phone*)> comparFunc);
};
