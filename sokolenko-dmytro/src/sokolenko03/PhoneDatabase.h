/**
* @file PhoneDatabase.h
* ���������� ����� PhoneDatabase.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/


#pragma once

#include "phone.h"

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
	* ��������� ���� ����� PhoneDatabase.
	* @param newSize ������������ ���� PhoneDatabase::size.
	* @param newPhoneArray. � ������������� ������ ����������
	* ��������� ��'���� ����� Phone � �������� �����
	* �� ��������� ��������������� ��������� ���������.
	*/
	void setPhoneDatabaseInfo(int, Phone *);

	/**
	* ����� ��������� �������� ������ ��'���� ����� Phone � ������,
	* �� � ����� ��'���� ����� PhoneDatabase.
	* @param otherPhoneArr - �������� �� ����������� �����.
	* @param otherSize - ����� ������.
	* @return ������ ��������� �� ������ ��'����
	* ����� Phone: ��� �� �.
	*/
	bool comparisonPhoneArray(const Phone*, int) const;

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
	* ���������� � ������ ���������� �� �� �����
	* � ���� ������������ ��'����.
	* @param newPhone - � ���� ��'���� ���������� �����
	* ���������� � ������.
	*/
	void readFromConsole(Phone &) const;

	/**
	* ���������� � ����� ���������� ��� ����� ��'����.
	* @param fileName - ����� � ������ �����.
	*/
	void readFromFile(string);

	/**
	* ����� � ���� ���������� � ������ PhoneDatabase::phoneArray.
	* @param fileName - ����� � ������ �����.
	*/
	void writeToFile(string);

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

