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
	* �������������� �������� ������������.
	* @param copiedPhone: �������� ���� ���� ������������ ����� ��������� ��'����.
	* @return �������� �� �������� ��'���.
	*/
	IosPhone& operator= (const IosPhone& copiedPhone);

	/**
	* �������������� �������� ���������.
	* @param otherPhone ��'���, � ���� ����������� ���������.
	* @return ������ ������ ���� ��'���� ����� Phone.
	*/
	bool operator==(const IosPhone& otherPhone) const;

	/**
	* �������� �����, �� ������ ����� � ����������� ��� ��'���
	* � �� ���� ����� �������� ���� ��'����.
	* @param out - ��������� �� ���� �����
	* @param outputPhone - ��������� �� ��'��� IosPhone.
	* @return ��������� �� ���� �����.
	*/
	friend istream& operator>>(istream& in, IosPhone& inputPhone);

	/**
	* �������� ������, �� �������� ����� � ����������� ��� ��'���.
	* @param out - ��������� �� ���� ������
	* @param outputPhone - ��������� �� ��'��� IosPhone.
	* @return ��������� �� ���� ������.
	*/
	friend ostream& operator<<(ostream& out, const IosPhone& outputPhone);

	/**
	* �������� �����, �� ������ ����� � ����������� ��� ��'���
	* � �� ���� ����� �������� ���� ��'����.
	* @param out - ��������� �� ���� �����
	* @param outputPhone - ��������� �� ��'��� IosPhone.
	* @return ��������� �� ���� �����.
	*/
	friend istream& operator>>(istream& in, IosPhone* inputPhone);

	/**
	* �������� ������, �� �������� ����� � ����������� ��� ��'���.
	* @param out - ��������� �� ���� ������
	* @param outputPhone - ��������� �� ��'��� IosPhone.
	* @return ��������� �� ���� ������.
	*/
	friend ostream& operator<<(ostream& out, const IosPhone* outputPhone);

	void* operator new(size_t size);

	void operator delete(void *pointer);

	void* operator new[](size_t size);

	void operator delete[](void *pointer);

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
	* �������� � ������ �� ���������� ���� ��'���� IosPhone.
	*/
	virtual void input() override;

	/**
	* ������������� ���������� ��� �������� ��'��� � �����.
	* �������������� ������ ����� IosPhone.
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