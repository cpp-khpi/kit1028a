/**
* @file TestPhoneArray.h
* ���������� ����� TestPhoneArray.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"
#include "PhoneArray.h"

/**
* ���� ��������� ����� TestPhoneArray � ���� ������ �� ��������. 
* ���� ������� ������� - ������������ ������ ����� PhoneArray.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class TestPhoneArray {
private:
	/** ��'��� ����������� �����. */
	PhoneArray phoneDatabase;

	/** 
	* ����� ���������� ������� PhoneArray::addPhone.
	* @return ������ ������������� ������� PhoneArray::addPhone.
	*/
	bool testAddPhone();

	/**
	* ����� ���������� ������� PhoneArray::removePhone() ���
	* �������� �������� � ����.
	* @return ������ �������������  ������� PhoneArray::removePhone() ���
	* �������� �������� � ����.
	*/
	bool isRemoveFromEnd();

	/**
	* ����� ���������� ������� PhoneArray::removePhone() ���
	* �������� �������� � �������.
	* @return ������ �������������  ������� PhoneArray::removePhone() ���
	* �������� �������� � �������.
	*/
	bool isRemoveFromBegin();

	/**
	* ����� ���������� ������� PhoneArray::removePhone() ���
	* �������� ������� ��������.
	* @return ������ �������������  ������� PhoneArray::removePhone() ���
	* �������� ������� ��������.
	*/
	bool isSingleRemove();


	/** 
	* ����� ���������� ������� PhoneArray::removePhone.
	* @return ������ ������������� ������� PhoneArray::removePhone.
	*/
	bool testRemovePhone();

	/** 
	* ����� ���������� ������� PhoneArray::getPhone.
	* @return ������ ������������� ������� PhoneArray::getPhone.
	*/
	bool testGetPhone();

	/** 
	* ����� ���������� ������� PhoneArray::getSmallestResolutPhone.
	* @return ������ ������������� ������� PhoneArray::getSmallestResolutPhone.
	*/
	bool testGetSmallestResolutPhone();
public:
	/** 
	* ����� ������� ��� ������� ����� TestPhoneArray.
	* @return ������ ������������� ��� ������� ����� PhoneArray.
	*/
	bool testAll();
};
