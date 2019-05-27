/**
* @file PhoneOs.h
* ���������� �������� ����� PhoneOs.
* @author Sokolenko Dmytro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"

/**
* ���� ����� PhoneOs � ���� ������ �� ��������.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class PhoneOs : public Phone {
private:
	/** ����� ���������� �������. */
	string osTitle;
public:
	/**
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������.
	*/
	PhoneOs();

	/**
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param newTitle �������� ���� Phone::title.
	* @param newPrice �������� ���� Phone::price.
	* @param newSimNum �������� ���� Phone::simCardsNumber.
	* @param newResolution �������� ���� Phone::resolution.
	* @param newCapacity �������� ���� Phone::capacity.
	* @param newProcessor �������� ���� Phone::processor.
	*/
	PhoneOs(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		string newOsTitle);

	/**
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param copiedPhone: ����������� ���� ������ ��'���� ���������� ���� ������������.
	*/
	PhoneOs(const PhoneOs& copiedPhoneOs);

	/**
	* ������������ ����� ������ ����� �������.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param newTitle �������� ���� Phone::title ����� ������� ���������.
	* @param newPrice �������� ���� Phone::price.
	* @param newSimNum �������� ���� Phone::simCardsNumber.
	* @param newResolution �������� ���� Phone::resolution.
	* @param newCapacity �������� ���� Phone::capacity.
	*/
	void setPhoneOsInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		string newOsTitle);

	/**
	* ������������� ���������� ��� �������� ��'��� � �����.
	* �������������� ������ ����� Phone.
	* @return ����� � ����������� ��� �������� ��'���.
	*/
	virtual string phoneToString() const override;

	/**
	* ���������� ���� ��������� ��'���� ��
	* ����������, ��� �������� � �����.
	* @param phoneString - �������� ����� � ����������� ��� ��'���.
	*/
	virtual void stringToPhone(const string phoneString) override;

	/**
	* ����������.
	*/
	~PhoneOs();

	/**
	* �������������� �������� ������������.
	* @param copiedPhoneOs: �������� ���� ���� ������������ ����� ��������� ��'����.
	* @return �������� �� �������� ��'���.
	*/
	PhoneOs& operator= (const PhoneOs& copiedPhoneOs);

	/**
	* ���������� ���� Phone::title.
	* @return ������� �������� ���� Phone::title.
	*/
	string getOsTitle() const;

	/**
	* ������������ ������� ����� Phone::title.
	* @param newTitle: ����� � ���'��, �� ��� ����� newTitle,
	* ��������� � ���'���, �� ��� ����� Phone::title.
	*/
	void setOsTitle(string newOsTitle);
};