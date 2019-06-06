/**
* @file IosPhone.h
* ���������� �������� ����� IosPhone.
* @author Sokolenko Dmytro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"

/**
* ���� ����� IosPhone � ���� ������ �� ��������.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class IosPhone : public Phone {
private:
	/** ����� ������ ���������. */
	const string manufacturer = "Apple";
	/** ����� ����������� ������� IOS. */
	float iosVersion;
public:
	/**
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������.
	*/
	IosPhone();

	/**
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param newTitle �������� ���� IosPhone::title.
	* @param newPrice �������� ���� IosPhone::price.
	* @param newSimNum �������� ���� IosPhone::simCardsNumber.
	* @param newResolution �������� ���� IosPhone::resolution.
	* @param newCapacity �������� ���� IosPhone::capacity.
	* @param newIosVersion �������� ���� IosPhone::iosVersion.
	*/
	IosPhone(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		float newIosVersion);

	/**
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param copiedIosPhone: ����������� ���� ������ ��'���� ���������� ���� ������������.
	*/
	IosPhone(const IosPhone& copiedPhone);

	/**
	* ����������.
	*/
	virtual ~IosPhone() override;

	/**
	* ������������ ����� ������ ����� �������.
	* @param newTitle, @param newPrice, @param newSimNum, @param newResolution,
	* @param newCapacity ����������� � ������� Phone::setPhoneInfo,
	* �� ������������ ��������� �����.
	* @param newIosVersion ������������ ���� IosPhone::iosVersion.
	*/
	void setPhoneInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		float newIosVersion);

	/**
	* �������������� �������� ������������.
	* @param copiedIosPhone: �������� ���� ���� ������������ ����� ��������� ��'����.
	* @return �������� �� �������� ��'���.
	*/
	IosPhone& operator= (const IosPhone& copiedPhone);

	/**
	* �������� � ������ �� ���������� ���� ��'���� IosPhone.
	*/
	virtual void input() override;

	/**
	* ���������� ���� IosPhone::manufacturer.
	* @return ������� �������� ���� Phone::manufacturer.
	*/
	string getManufacturer() const;


	/**
	* ������������ ������� ����� IosPhone::iosVersion.
	* @param newIosVersion ������������ ���� IosPhone::iosVersion.
	*/
	void setIosVersion(float newIosVersion);

	/**
	* ���������� ���� IosPhone::iosVersion.
	* @return ������� �������� ���� IosPhone::iosVersion.
	*/
	float getIosVersion() const;
};