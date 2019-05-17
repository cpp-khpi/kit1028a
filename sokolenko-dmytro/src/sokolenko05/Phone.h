/**
* @file Phone.h
* ���������� �������� ����� Phone.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include "Cpu.h"
#include "MemoryCard.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::getline;
using std::ios_base;

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
	/** ��������� �������� */
	Cpu processor;
	/** ������ ���'��, �� �������� � �������. */
	MemoryCard* memCard;
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
	* @param newProcessor �������� ���� Phone::processor.
	*/
	Phone(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		Cpu newProcessor);

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
	~Phone();

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
	* �������������� �������� ���������.
	* @param otherPhone ��'���, � ���� ����������� ���������.
	* @return ������ �������� ���� ��'���� ����� Phone.
	*/
	bool operator!=(const Phone& otherPhone) const;

	/**
	* ������������ ����� ������ ����� �������.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param newTitle �������� ���� Phone::title ����� ������� ���������.
	* @param newPrice �������� ���� Phone::price.
	* @param newSimNum �������� ���� Phone::simCardsNumber.
	* @param newResolution �������� ���� Phone::resolution.
	* @param newCapacity �������� ���� Phone::capacity.
	* @param newProcessor �������� ���� Phon::processor.
	*/
	void setPhoneInfo(string newTitle,
		unsigned int newPrice,
		unsigned int newSimNum,
		unsigned int newResolution,
		unsigned int newCapacity,
		Cpu newProccessor);

	/**
	* ������������� ���������� ��� �������� ��'��� � �����.
	* @return ����� � ����������� ��� �������� ��'���.
	*/
	string phoneToString() const;

	/**
	* ���������� ���� ��������� ��'���� ��
	* ����������, ��� �������� � �����.
	* @param phoneString - �������� ����� � ����������� ��� ��'���.
	*/
	void stringToPhone(const string phoneString);
	
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
	void setTitle(string newTitle);

	/**
	* ���������� ���� Phone::price.
	* @return ������� �������� ���� Phone::price.
	*/
	unsigned int getPrice() const;

	/**
	* ������������ ������� ����� Phone::price.
	* @param newPrice ������������ Phone::price.
	*/
	void setPrice(unsigned int newPrice);

	/**
	* ���������� ���� Phone::simCardsNumber.
	* @return ������� �������� ���� Phone::simCardsNumber.
	*/
	unsigned int getSimCardsNumber() const;

	/**
	* ������������ ������� ����� Phone::simCardsNumber.
	* @param newSimCardsNumber ������������ Phone::simCardsNumber.
	*/
	void setSimCardsNumber(unsigned int newsimCardsNumber);

	/**
	* ���������� ���� Phone::resolution.
	* @return ������� �������� ���� Phone::resolution.
	*/
	unsigned int getResolution() const;

	/**
	* ������������ ������� ����� Phone::resolution.
	* @param newResolution ������������ Phone::resolution.
	*/
	void setResolution(unsigned int newResolution);

	/**
	* ���������� ���� Phone::capacity.
	* @return ������� �������� ���� Phone::capacity.
	*/
	unsigned int getCapacity() const;

	/**
	* ������������ ������� ����� Phone::capacity.
	* @param newCapacity ������������ Phone::capacity.
	*/
	void setCapacity(unsigned int newCapacity);

	/**
	* ���������� ���� Phone::memCard.
	* @return ����������� �������� ���� Phone::memCard.
	*/
	const MemoryCard* getMemoryCard() const;

	/**
	* ������������ ������� ����� Phone::memCard.
	* @param newMemCard ������������ Phone::memCard.
	*/
	void setMemoryCard(MemoryCard* newMemCard);
};