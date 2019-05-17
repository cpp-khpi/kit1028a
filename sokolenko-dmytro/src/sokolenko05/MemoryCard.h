/**
* @file MemoryCard.h
* ���������� ����� MemoryCard.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include <string>

using std::string;

/**
* ���� ����� MemoryCard � ���� ������ �� ��������.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class MemoryCard {
private:
	/** ����� ����� ���'��. */
	string title;
	/** ������ ����� ���'��, GB. */
	unsigned int capacity;
public:
	/**
	* ���������� ���� MemoryCard::coresNumber.
	* @return ������� �������� ���� MemoryCard::coresNumber.
	*/
	string getTitle() const;

	/**
	* ������������ ������� ����� MemoryCard::coresNumber.
	* @param newTitle ������������ MemoryCard::coresNumber.
	*/
	void setTitle(string newTitle);

	/**
	* ���������� ���� MemoryCard::capacity.
	* @return ������� �������� ���� MemoryCard::capacity.
	*/
	unsigned int getCapacity() const;

	/**
	* ������������ ������� ����� MemoryCard::capacity.
	* @param newCapacity ������������ MemoryCard::capacity.
	*/
	void setCapacity(unsigned int newFrequency);

	/**
	* ����������� �� �������������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������.
	*/
	MemoryCard();

	/**
	* ����������� � �����������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������.
	* @param newTitle � ��������� � ���� Cpu::title.
	* @param newCapacity �������� ���� MemoryCard::capacity.
	*/
	MemoryCard(string newTitle,
		unsigned int newCapacity);

	/**
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������,
	* � �� ������������ ���������� �������� ���'�� �� ��������� �����.
	* @param copiedMemCard: ����������� ���� ������ ��'���� ���������� ���� ������������.
	*/
	MemoryCard(const MemoryCard& copiedMemCard);

	/**
	* ����������.
	*/
	~MemoryCard();
};