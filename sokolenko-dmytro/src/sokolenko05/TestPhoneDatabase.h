/**
* @file TestPhoneDatabase.h
* ���������� ����� TestPhoneDatabase.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"
#include "PhoneDatabase.h"

/**
* ���� ��������� ����� TestPhoneDatabase � ���� ������ �� ��������. 
* ���� ������� ������� - ������������ ������ ����� PhoneDatabase.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class TestPhoneDatabase {
private:
	/** ��'��� ����������� �����. */
	PhoneDatabase phoneDatabase;

	/** 
	* ����� ���������� ������� PhoneDatabase::addPhone.
	* @return ������ ������������� ������� PhoneDatabase::addPhone.
	*/
	bool testAddPhone();

	/**
	* ����� ���������� ������� PhoneDatabase::removePhone() ���
	* ��������� �������� � ����.
	* @return ������ �������������  ������� PhoneDatabase::removePhone() ���
	* ��������� �������� � ����.
	*/
	bool isRemoveFromEnd();

	/**
	* ����� ���������� ������� PhoneDatabase::removePhone() ���
	* ��������� �������� � �������.
	* @return ������ �������������  ������� PhoneDatabase::removePhone() ���
	* ��������� �������� � �������.
	*/
	bool isRemoveFromBegin();

	/**
	* ����� ���������� ������� PhoneDatabase::removePhone() ���
	* ��������� ������� ��������.
	* @return ������ �������������  ������� PhoneDatabase::removePhone() ���
	* ��������� ������� ��������.
	*/
	bool isSingleRemove();


	/** 
	* ����� ���������� ������� PhoneDatabase::removePhone.
	* @return ������ ������������� ������� PhoneDatabase::removePhone.
	*/
	bool testRemovePhone();

	/** 
	* ����� ���������� ������� PhoneDatabase::getPhone.
	* @return ������ ������������� ������� PhoneDatabase::getPhone.
	*/
	bool testGetPhone();

	/** 
	* ����� ���������� ������� PhoneDatabase::getSmallestResolutPhone.
	* @return ������ ������������� ������� PhoneDatabase::getSmallestResolutPhone.
	*/
	bool testGetSmallestResolutPhone();
public:
	/** 
	* ����� ������� ��� ������� ����� TestPhoneDatabase.
	* @return ������ ������������� ��� ������� ����� PhoneDatabase.
	*/
	bool testAll();
};
