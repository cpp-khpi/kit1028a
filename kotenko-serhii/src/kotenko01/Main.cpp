/*
 * @mainpage
 * <b> ����������� ������ � 1. <br/> �����. </b>
 * <br/><b><i >���� ������ </i></b>:�������� ����� ������ ��� �����. �������� ������� ������������.<br/>
 * <b>1 �������� �� ������ <br/> �������� ��������  <br/> </b>
 * ��������� �������� ������ ��������� ������ ����� �++, �������������� ����������� ���������� ��������
 * Visual Studio. ���������������� ������ ��������. <br/>
 * <b>1.2 ������� ��������  <br/> </b>
 * ���������� �������� �������� �� �������������� ��������. <br/>
 * <b><i> ������������ �������� </i></b><br/>
 * ��� ��������� ����� � ����. 1.2 ��������� ��� �����:
 * - ����, �� �������� ������� ��������� �����. 
 * - ����, �� �� � ��� ��������� ����� �ᒺ��� �������� ����� �� �� � ��� ������ ���������, 
 * ��������� ��������, ��������� �������� �� ������� (��� ��������������), ���� ��� �������� 
 * �� �����. <br/>
 *
 *
 * @author ����� �������
 * @date 24.02.19
 * @version 2.0
 */

#include "InfoAuditoryLessons.h"
#include "AuditoryLessons.h"

int main(void) {
	system("color A");

	AuditoryLessons Work;

	int i = 0;
	std::cout << "Enter size : " ;
	std::cin >> i;
	Work.getSize(i);
	system("cls");
	Work.newArray();
	Work.print();

    char option = 0;
	do {
		std::cout << "Choose option:" << std::endl << "1 - Exit " << std::endl << "2 - Add element" << std::endl << "3 - Delete element" << std::endl << "4 - Search by index" << std::endl;
		std::cout << std::endl;
        std::cin >> option ;

		switch (option) {
		case'1': {
			system("cls");
			Work.deleteArray();
			exit(0);
		}
		case'2': {
			std::cout << std::endl;
			Work.addElem();
			break;
		}
		case '3': {
			int j = 0;
			std::cout << std::endl << "Enter index by delete element : " ;
			std::cin >> j; 
			std::cout << std::endl;
			Work.deleteElem(j);
			break;
		}
		case '4': {
			int z = 0;
			std::cout << std::endl << "Enter index : " ;
			std::cin >> z;
			Work.getByIndex(z);
			break;
		}
	}
} while (option != 0);
	
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
	_CrtDumpMemoryLeaks();
}
