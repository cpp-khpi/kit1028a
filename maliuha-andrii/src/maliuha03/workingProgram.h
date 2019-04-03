/**
* @file workingProgram.h
* ���������� ������ workingProgram
* @author Maliuga Andrey
* @version 0.6
* @date 30.03.2019
*/



#pragma once
#include "Header.h"

/**
* �������� ������ workingProgram � ��� ������ � ��������.
* ����� workingProgram ������ ��� �������� ���������� ���������.
*/
class workingProgram {
private:
	
	/** �������� ��������� */
	string name;

	/** �������� ��� ����������� ���������. */
	string publisher;
	
	/** ���������� ����������� ������, ������� ������� ���������. */
	float opMemoryMb;
	
	/** ���������� ���������� ������, ������� �������� ���������. */
	float memoryGb;
	
	/** ����� ������ ��������� � ������ ������. */
	float timeWorkMin;

public:
	
	/**
	* ����������� �� ���������.
	* ������������ ������ ������������.
	*/
	workingProgram();

	/** 
	* �����, ������� ������� �������� ����� ������� �� �����.
	*/
	stringstream print();


	/**
	* �����, ������� ��������� �������� ����� �������.
	* @param info ������ ���������� � ����� �������.
	*/
	void setObj(string &info);

	/**
	* ��������� ���� workingProgram::name.
	* @param name ������������� ���� workingProgram::name.
	*/
	void setName(string name);

	/**
	* ��������� ���� workingProgram::publisher.
	* @param publisher ������������� ���� workingProgram::publisher.
	*/
	void setPublisher(string publisher);

	/** 
	* ��������� ���� workingProgram::opMemoryMd.
	* @param opMemoryMd ������������� ���� workingProgram::opMemoryMd.
	*/
	void setOpMemoryMb(float opMemoryMb);

	/**
	* ��������� ���� workingProgram::memoryGd.
	* @param memoryGd ������������� ���� workingProgram::memoryGd.
	*/
	void setMemoryGb(float memoryGd);

	/**
	* ��������� ���� workingProgram::timeWorkMin.
	* @param timeWorkMin ������������� ���� workingProgram::timeWorkMin.
	*/
	void setTimeWorkMin(float timeWorkMin);

	/**
	* ������ ���� workingProgram::name.
	* @return ������� �������� ���� workingProgram::name.
	*/
	string getName();

	/**
	* ������ ���� workingProgram::publisher.
	* @return ������� �������� ���� workingProgram::publisher.
	*/
	string getPublisher();

	/**
	* ������ ���� workingProgram::opMemoryMd.
	* @return ������� �������� ���� workingProgram::opMemoryMd.
	*/
	float getOpMemoryMb();

	/**
	* ������ ���� workingProgram::memoryGd.
	* @return ������� �������� ���� workingProgram::memoryGd.
	*/
	float getMemoryGb();

	/**
	* ������ ���� workingProgram::timeWorkMin.
	* @return ������� �������� ���� workingProgram::timeWorkMin.
	*/
	float getTimeWorkMin();
};
