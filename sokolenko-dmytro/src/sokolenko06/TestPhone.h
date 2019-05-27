/**
* @file TestPhone.h
* ���������� ����� TestPhone.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"

/**
* ���� ��������� ����� TestPhoneArray � ���� ������ �� ��������.
* ���� ������� ������� - ������������ ������ ����� PhoneArray.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class TestPhone {
private:
	/** ��'��� ����������� �����. */
	Phone phone;

	/**
	* ����� ���������� ������� Phone::phoneToString.
	* @return ������ ������������� ������� Phone::phoneToString.
	*/
	bool testPhoneToString();

	/**
	* ����� ���������� ������� Phone::stringToPhone.
	* @return ������ ������������� ������� Phone::stringToPhone.
	*/
	bool testStringToPhone();
public:
	/**
	* ����� ������� ��� ������� ����� TestPhone.
	* @return ������ ������������� ��� ������� ����� Phone.
	*/
	bool testAll();
};