/**
* @file Phone.h
* ���������� �������� ����� Phone.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include <string>
#include <sstream>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::getline;
using std::ostream;
using std::istream;

/** 
* ���� ����� Phone � ���� ������ �� ��������.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class Phone {
protected:
	/** ����� ��������. */
	string title;
	/** ֳ�� ��������. */
	unsigned int price;
	/** ʳ������ sim-���� � �������. */
	unsigned int simCardsNumber;
	/** ٳ������ ������ ������ ��������. */
	unsigned int resolution;
	/** ������ ����������� ��������. */
	unsigned int capacity;
public:
	/** 
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������.
	*/
	Phone();

	/** 
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param newTitle �������� ���� Phone::title.
	* @param newPrice �������� ���� Phone::price.
	* @param newSimNum �������� ���� Phone::simCardsNumber.
	* @param newResolution �������� ���� Phone::resolution.
	* @param newCapacity �������� ���� Phone::capacity.
	*/
	Phone(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity);

	/**
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param copiedPhone: ����������� ���� ������ ��'���� ���������� ���� ������������.
	*/
	Phone(const Phone& copiedPhone);

	/**
	* ����������.
	*/
	virtual ~Phone();

	/**
	* �������������� �������� ������������.
	* @param copiedPhone: �������� ���� ���� ������������ ����� ��������� ��'����.
	* @return �������� �� �������� ��'���.
	*/
	Phone& operator= (const Phone& copiedPhone);

	/**
	* �������������� �������� ���������.
	* @param otherPhone ��'���, � ���� ����������� ���������.
	* @return ������ ������ ���� ��'���� ����� Phone.
	*/
	bool operator==(const Phone& otherPhone) const;

	/**
	* �������� �����, �� ������ ����� � ����������� ��� ��'��� 
	* � �� ���� ����� �������� ���� ��'����.
	* @param out - ��������� �� ���� �����
	* @param outputPhone - ��������� �� ��'��� Phone.
	* @return ��������� �� ���� �����.
	*/
	friend istream& operator>>(istream& in, Phone& inputPhone);

	/**
	* �������� ������, �� �������� ����� � ����������� ��� ��'���.
	* @param out - ��������� �� ���� ������
	* @param outputPhone - ��������� �� ��'��� Phone.
	* @return ��������� �� ���� ������.
	*/
	friend ostream& operator<<(ostream& out, const Phone& outputPhone);

	/**
	* ������������ ����� ������ ����� �������.
	* @param newTitle �������� ���� Phone::title ����� ������� ���������.
	* @param newPrice �������� ���� Phone::price.
	* @param newSimNum �������� ���� Phone::simCardsNumber.
	* @param newResolution �������� ���� Phone::resolution.
	* @param newCapacity �������� ���� Phone::capacity.
	*/
	void setPhoneInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity);

	/**
	* �������� � ������ �� ���������� ���� ��'���� Phone. 
	*/
	virtual void input() = 0;

	/**
	* ������������� ���������� ��� �������� ��'��� � �����.
	* @return ����� � ����������� ��� �������� ��'���.
	*/
	virtual string phoneToString() const = 0;

	/**
	* ���������� ���� ��������� ��'���� ��
	* ����������, ��� �������� � �����.
	* @param phoneString - �������� ����� � ����������� ��� ��'���.
	*/
	virtual void stringToPhone(const string phoneString) = 0;
	
	/**
	* ������������ ������� ����� Phone::title.
	* @param newTitle ������������ ���� Phone::title.
	*/
	void setTitle(string newTitle);

	/**
	* ���������� ���� Phone::title.
	* @return ������� �������� ���� Phone::title.
	*/
	string getTitle() const;

	/**
	* ������������ ������� ����� Phone::price.
	* @param newPrice ������������ Phone::price.
	*/
	void setPrice(unsigned int newPrice);

	/**
	* ���������� ���� Phone::price.
	* @return ������� �������� ���� Phone::price.
	*/
	unsigned int getPrice() const;

	/**
	* ������������ ������� ����� Phone::simCardsNumber.
	* @param newSimCardsNumber ������������ Phone::simCardsNumber.
	*/
	void setSimCardsNumber(unsigned int newsimCardsNumber);

	/**
	* ���������� ���� Phone::simCardsNumber.
	* @return ������� �������� ���� Phone::simCardsNumber.
	*/
	unsigned int getSimCardsNumber() const;

	/**
	* ������������ ������� ����� Phone::resolution.
	* @param newResolution ������������ Phone::resolution.
	*/
	void setResolution(unsigned int newResolution);

	/**
	* ���������� ���� Phone::resolution.
	* @return ������� �������� ���� Phone::resolution.
	*/
	unsigned int getResolution() const;


	/**
	* ������������ ������� ����� Phone::capacity.
	* @param newCapacity ������������ Phone::capacity.
	*/
	void setCapacity(unsigned int newCapacity);

	/**
	* ���������� ���� Phone::capacity.
	* @return ������� �������� ���� Phone::capacity.
	*/
	unsigned int getCapacity() const;
};