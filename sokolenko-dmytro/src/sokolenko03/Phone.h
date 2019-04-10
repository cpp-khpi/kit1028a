/**
* @file Phone.h
* ���������� �������� ����� Phone.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include <iostream>
//#include <cstring>
#include <string>
#include <sstream>
#include <fstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::getline;
using std::ifstream;

/** 
* ���� ����� Phone � ���� ������ �� ��������.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class Phone {
private:
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
	Phone(string, unsigned int, unsigned int, unsigned int, unsigned int);

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
	void setPhoneInfo(string, unsigned int, unsigned int, unsigned int, unsigned int);

	/**
	* ������������� ���������� ��� �������� ��'��� � �����.
	* @return 
	*/
	string convertPhone() const;

	/**
	* ���������� ���� Phone::title.
	* @return ������� �������� ���� Phone::title.
	*/
	string getTitle() const;

	/**
	* ������������ ������� ����� Phone::title.
	* @param newTitle: ����� � ���'��, �� ��� ����� newTitle, 
	* ��������� � ���'���, �� ��� ����� Phone::title.
	*/
	void setTitle(string);

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