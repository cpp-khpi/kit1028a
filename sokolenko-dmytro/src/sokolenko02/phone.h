/**
* @file phone.h
* ���������� �������� ����� Phone.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

/** 
* ���� ����� Phone � ���� ������ �� ��������.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class Phone {
private:
	/** ����� ��������. */
	char * title;
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
	* ����������� �� �������������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	*/
	Phone();

	/** 
	* ����������� � �����������. 
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param newTitle � ������������� ��������� ������� ��������� � ���� Phone::title.
	* @param newPrice �������� ���� Phone::price.
	* @param newSimNum �������� ���� Phone::simCardsNumber.
	* @param newResolution �������� ���� Phone::resolution.
	* @param newCapacity �������� ���� Phone::capacity.
	*/
	Phone(char *, unsigned int, unsigned int, unsigned int, unsigned int);

	/**
	* ����������� ���������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param copiedPhone: ����������� ���� ������ ��'���� ���������� ���� ������������.
	*/
	Phone(const Phone &);

	/**
	* ����������. ��������� ������� ���'�� ��� �����.
	*/
	~Phone();

	/**
	* �������������� �������� ������������.
	* @param copiedPhone: �������� ���� ���� ������������ ����� ��������� ��'����.
	* @return �������� �� �������� ��'���.
	*/
	Phone& operator= (const Phone &);

	/**
	* �������������� �������� ���������.
	* @param otherPhone ��'���, � ���� ����������� ���������.
	* @return ������ ������ ���� ��'���� ����� Phone.
	*/
	bool operator==(const Phone&) const;

	/**
	* �������������� �������� ���������.
	* @param otherPhone ��'���, � ���� ����������� ���������.
	* @return ������ �������� ���� ��'���� ����� Phone.
	*/
	bool operator!=(const Phone&) const;

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
	void setPhoneInfo(char *, unsigned int, unsigned int, unsigned int, unsigned int);

	/**
	* ���������� ���� Phone::title.
	* @return ������� �������� ���� Phone::title.
	*/
	char * getTitle() const;

	/**
	* ������������ ������� ����� Phone::title.
	* @param newTitle ������������ Phone::title.
	*/
	void setTitle(char *);

	/**
	* ���������� ���� Phone::price.
	* @return ������� �������� ���� Phone::price.
	*/
	unsigned int getPrice() const;

	/**
	* ������������ ������� ����� Phone::price.
	* @param newPrice ������������ Phone::price.
	*/
	void setPrice(unsigned int);

	/**
	* ���������� ���� Phone::simCardsNumber.
	* @return ������� �������� ���� Phone::simCardsNumber.
	*/
	unsigned int getSimCardsNumber() const;

	/**
	* ������������ ������� ����� Phone::simCardsNumber.
	* @param newSimCardsNumber ������������ Phone::simCardsNumber.
	*/
	void setSimCardsNumber(unsigned int);

	/**
	* ���������� ���� Phone::resolution.
	* @return ������� �������� ���� Phone::resolution.
	*/
	unsigned int getResolution() const;

	/**
	* ������������ ������� ����� Phone::resolution.
	* @param newResolution ������������ Phone::resolution.
	*/
	void setResolution(unsigned int);

	/**
	* ���������� ���� Phone::capacity.
	* @return ������� �������� ���� Phone::capacity.
	*/
	unsigned int getCapacity() const;

	/**
	* ������������ ������� ����� Phone::capacity.
	* @param newCapacity ������������ Phone::capacity.
	*/
	void setCapacity(unsigned int);
};