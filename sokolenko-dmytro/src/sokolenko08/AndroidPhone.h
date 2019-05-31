/**
* @file AndroidPhone.h
* ���������� �������� ����� AndroidPhone.
* @author Sokolenko Dmytro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Phone.h"

/**
* ���� ����� AndroidPhone � ���� ������ �� ��������.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class AndroidPhone : public Phone {
private:
	/** ����� ������ ���������. */
	string manufacturer;
	/** �� � OS Android �����������. */
	bool isStandardAndroid;
	/** ����� ����������� ������� Android. */
	float androidVersion;
public:
	/**
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������.
	*/
	AndroidPhone();

	/**
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param newTitle �������� ���� AndroidPhone::title.
	* @param newPrice �������� ���� AndroidPhone::price.
	* @param newSimNum �������� ���� AndroidPhone::simCardsNumber.
	* @param newResolution �������� ���� AndroidPhone::resolution.
	* @param newCapacity �������� ���� AndroidPhone::capacity.
	* @param newAndroidVersion �������� ���� AndroidPhone::androidVersion.
	*/
	AndroidPhone(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		string newManufacturer,
		bool newIsStandAndr,
		float newAndroidVersion);

	/**
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param copiedAndroidPhone: ����������� ���� ������ ��'���� ���������� ���� ������������.
	*/
	AndroidPhone(const AndroidPhone& copiedPhone);

	/**
	* ����������.
	*/
	virtual ~AndroidPhone() override;

	/**
	* ������������ ����� ������ ����� �������.
	* @param newTitle, @param newPrice, @param newSimNum, @param newResolution,
	* @param newCapacity ����������� � ������� Phone::setPhoneInfo,
	* �� ������������ ��������� �����.
	* @param newManufacturer ������������ ���� AndroidPhone::manufacturer,
	* @param newIsStandAndr ������������ ���� AndroidPhone::isStandardAndroid,
	* @param newAndroidVersion ������������ ���� AndroidPhone::androidVersion.
	*/
	void setPhoneInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		string newManufacturer,
		bool newIsStandAndr,
		float newAndroidVersion);

	/**
	* �������������� �������� ������������.
	* @param copiedAndroidPhone: �������� ���� ���� ������������ ����� ��������� ��'����.
	* @return �������� �� �������� ��'���.
	*/
	AndroidPhone& operator= (const AndroidPhone& copiedPhone);

	/**
	* �������������� �������� ���������.
	* @param otherPhone ��'���, � ���� ����������� ���������.
	* @return ������ ������ ���� ��'���� ����� Phone.
	*/
	bool operator==(const AndroidPhone& otherPhone) const;

	/**
	* �������� �����, �� ������ ����� � ����������� ��� ��'���
	* � �� ���� ����� �������� ���� ��'����.
	* @param out - ��������� �� ���� �����
	* @param outputPhone - ��������� �� ��'��� AndroidPhone.
	* @return ��������� �� ���� �����.
	*/
	friend istream& operator>>(istream& in, AndroidPhone& inputPhone);

	/**
	* �������� ������, �� �������� ����� � ����������� ��� ��'���.
	* @param out - ��������� �� ���� ������
	* @param outputPhone - ��������� �� ��'��� AndroidPhone.
	* @return ��������� �� ���� ������.
	*/
	friend ostream& operator<<(ostream& out, const AndroidPhone& outputPhone);

	/**
	* �������� � ������ �� ���������� ���� ��'���� AndroidPhone.
	*/
	virtual void input() override;

	/**
	* ������������� ���������� ��� �������� ��'��� � �����.
	* �������������� ������ ����� AndroidPhone.
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
	* ������������ ������� ����� IosPhone::iosVersion.
	* @param newIosVersion ������������ ���� IosPhone::iosVersion.
	*/
	void setManufacturer(string newManufacturer);

	/**
	* ���������� ���� AndroidPhone::manufacturer.
	* @return ������� �������� ���� Phone::manufacturer.
	*/
	string getManufacturer() const;

	/**
	* ������������ ������� ����� AndroidPhone::isStandardAndroid.
	* @param newIsStandAndr ������������ ���� AndroidPhone::isStandardAndroid.
	*/
	void setIsStandardAndroid(bool newIsStandAndr);

	/**
	* ���������� ���� AndroidPhone::isStandardAndroid.
	* @return ������� �������� ���� AndroidPhone::isStandardAndroid.
	*/
	bool getIsStandardAndroid() const;

	/**
	* ������������ ������� ����� AndroidPhone::androidVersion.
	* @param newIosVersion ������������ ���� AndroidPhone::androidVersion.
	*/
	void setAndroidVersion(float newAndroidVersion);

	/**
	* ���������� ���� AndroidPhone::androidVersion.
	* @return ������� �������� ���� AndroidPhone::androidVersion.
	*/
	float getAndroidVersion() const;
};