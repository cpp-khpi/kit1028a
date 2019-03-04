/*
 * @mainpage
 * <b> Лабораторна робота № 1. <br/> Класи. </b>
 * <br/><b><i >Мета роботи </i></b>:Отримати базові знання про класи. Дослідити механізм інкапсуляції.<br/>
 * <b>1 Завдання до роботи <br/> Загальне завдання  <br/> </b>
 * Розробити програму рішення прикладної задачі мовою С++, використовуючи інтегроване середовище розробки
 * Visual Studio. Продемонструвати роботу програми. <br/>
 * <b>1.2 Основне завдання  <br/> </b>
 * Реалізувати програму відповідно до індивідуального завдання. <br/>
 * <b><i> Індивідуальне завдання </i></b><br/>
 * Для предметної галузі з табл. 1.2 розробити два класи:
 * - клас, що відображає сутність «базового класу». 
 * - клас, що має в собі динамічний масив об’єктів базового класу та має в собі методи додавання, 
 * видалення елементу, отримання елементу по індексу (або ідентифікатору), вивід усіх елементів 
 * на екран. <br/>
 *
 *
 * @author Сергій Котенко
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
