/**
* @file phoneDatabase.h
* ���������� ����� PhoneDatabase.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/


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
	PhoneDatabase(int, Phone *);

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
	PhoneDatabase(const PhoneDatabase &);

	/**
	* ����������. ��������� ������� ���'�� ��� ������.
	*/
	~PhoneDatabase();

	/**
	* ����� ��������� ���� ������ ��'���� ����� Phone.
	* @param firstPhoneArr - �������� �� ������ ����������� �����.
	* @param secondPhoneArr - �������� �� ������ ����������� �����.
	* @return ������ ��������� �� ������ ��'����
	* ����� Phone: ��� �� �.
	*/
	bool comparisonPhoneArray(const Phone*, const Phone*, int, int) const;

	/**
	* ���������� ���� PhoneDatabase::size.
	* @return ������� �������� ���� PhoneDatabase::size.
	*/
	int getSize() const;

	/**
	* ������������ ������� ����� PhoneDatabase::size.
	* @param newSize ������������ PhoneDatabase::size.
	*/
	void setSize(int);

	/**
	* ���������� ���� PhoneDatabase::phoneArray.
	* @return ������� �������� ���� PhoneDatabase::phoneArray.
	*/
	Phone * getPhoneArray() const;

	/**
	* ������������ ������� ����� PhoneDatabase::phoneArray.
	* @param newSize ������������ PhoneDatabase::phoneArray.
	*/
	void setPhoneArray(Phone *);

	/**
	* ���������� ������ ������ � ��������� �� ����� �������� � ���� PhoneDatabase::size.
	* @return ������� �������� ���� PhoneDatabase::size.
	*/
	int inputSize();


	/**
	* ���������� � ������ ���������� �� �� �����
	* � ���� ������������ ��'����.
	* @param newPhone - � ���� ��'���� ���������� �����
	* ���������� � ������.
	*/
	void readPhone(Phone &) const;

	/**
	* ��������� ��'���� ����� Phone �
	* ����� PhoneDatabase::phoneArray.
	* @param addedPhone - ��������� ��'���.
	*/
	void addPhone(Phone &);

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
	void removePhone(const int);

	/**
	* ��������� �� ������� ��������� �� ������� ������
	* PhoneDatabase::phoneArray.
	* @param index - ������ ���������� ��'����.
	* @return ��������� �� ������� ������.
	*/
	Phone& getPhone(const int);

	/**
	* ��������� �� ����� ������ �������� ����
	* ������������ ��'���� ����� Phone.
	* @param printedPhone - ���� ��'���� ���������� �� �����.
	*/
	void printPhone(Phone &) const;

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

