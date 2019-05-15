/**
* @file Cpu.h
* ���������� ����� Cpu.
* @author Sokolenko Dmitro
* @version 0.3
* @date 2019.03.27
*/

#pragma once

#include <string>

using std::string;

/**
* ���� ����� Cpu � ���� ������ �� ��������.
* ���������������� �������� � ���� Javadoc ��� ������� ������� Doxygen.
*/
class Cpu {
private:
	/** ����� ���������. */
	string title;
	/** ʳ������ ���� ���������. */
	unsigned int coresNumber;
	/** ������� ���������. */
	unsigned int frequency;
public:
	/**
	* ���������� ���� Cpu::coresNumber.
	* @return ������� �������� ���� Cpu::coresNumber.
	*/
	string getTitle() const;

	/**
	* ������������ ������� ����� Cpu::coresNumber.
	* @param newCapacity ������������ Cpu::coresNumber.
	*/
	void setTitle(string newTitle);

	/**
	* ���������� ���� Cpu::coresNumber.
	* @return ������� �������� ���� Cpu::coresNumber.
	*/
	unsigned int getCoresNumber() const;

	/**
	* ������������ ������� ����� Cpu::coresNumber.
	* @param newCapacity ������������ Cpu::coresNumber.
	*/
	void setCoresNumber(unsigned int newCoresNumber);

	/**
	* ���������� ���� Cpu::frequency.
	* @return ������� �������� ���� Cpu::frequency.
	*/
	unsigned int getFrequency() const;

	/**
	* ������������ ������� ����� Cpu::frequency.
	* @param newCapacity ������������ Cpu::frequency.
	*/
	void setFrequency(unsigned int newFrequency);
	
	/**
	* ����������� �� �������������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������.
	*/
	Cpu();

	/**
	* ����������� � �����������.
	* ���������� ����.
	* ��������������� ������ ����������� �������� ������.
	* @param newTitle � ������������� ��������� ������� ��������� � ���� Cpu::title.
	* @param newCoresNumber �������� ���� Cpu::coresNumber.
	* @param newFrequency �������� ���� Cpu::frequency.
	*/
	Cpu(string newTitle,
		unsigned int newCoresNumber,
		unsigned int newFrequency);

	/**
	* ����������.
	*/
	~Cpu();
};