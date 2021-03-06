﻿# Лабораторна робота №7. Поліморфізм {#mainpage}

#### Тема. 
Класи. Поліморфізм. Абстрактні класи.
#### Мета. 
Отримати знання про парадигму ООП – поліморфізм.
Навчитися застосовувати отримані знання на практиці.

## 1 ВИМОГИ
### 1.1 Розробник
Інформація про розробника:
- Соколенко Д.Г.;
- НТУ "ХПІ", кафедра "ОТП", група 1.КІТ 102.8(а);
### 1.2 Загальне завдання
Модернізувати попередню лабораторну роботу шляхом:
- додавання ще одного класу-спадкоємця до базового класу. Поля
обрати самостійно;
- базовий клас зробити абстрактним. Додати абстрактні поля;
- розроблені класи-списки поєднуються до одного таким чином,
щоб він міг працювати як з базовим класом, так і з його
спадкоємцями. При цьому, серед полів класу-списку повен бути лише
один масив, що містить усі типи класів ієрархії. Оновити методи, що
працюють з цим масивом.

### 1.3 Додаткові умови виконання завдання:
- продемонструвати відсутність витоків пам’яті;
- продемонструвати роботу розроблених методів за допомогою
модульних тестів;
- не використовувати конструкцію _«using namespace std;»_, замість
цього слід роботи _«using»_ кожного необхідного класу: _using std::string,
using std::cout;_
- в проекті не повинні використовуватися бібліотеки введення /
виведення мови _С_, а також не повинні використовуватися рядки типу
_char*_.

## 2 ОПИС ПРОГРАМИ

#### Опис програми дивитись у документації до коду.

### 2.1 Функціональне призначення
Програма призначена для створення та обробки масиву об'єктів типу Phone.

### 2.2 Опис логічної структури
Нижче продемонстрована діаграма класів, використаних у програмі з їх 
полями й методами (рис 2.2.1)

![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko07/images/13-%20Class%20diagram.jpg)
Рис.2.2.1 - Діаграма класів

## 3 ВАРІАНТИ ВИКОРИСТАННЯ

Нижче (рис.3.1 - 3.10) показані варіанти використання програми.
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko04/images/1%20-%20Read%20data%20from%20file.jpg)
Рис.3.1 - Запуск програми, зчитання даних з файлу
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko07/images/2%20-%20Source%20data%20in%20file.jpg)
Рис.3.2 - Вихідні дані у файлі
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko04/images/3%20-%20Add%20element.jpg)
Рис.3.3 - Додавання нового елементу
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko04/images/4%20-%20Delete%20element.jpg)
Рис.3.4 - Видалення елементу
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko04/images/5%20-%20Get%20by%20index.jpg)
Рис.3.5 - Отримання по індексу
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko04/images/6%20-%20Show%20All.jpg)
Рис.3.6 - Вивід на екран усіх елементів
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko04/images/7%20-%20Display%20size.jpg)
Рис.3.7 - Відображення поточного розміру масиву
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko04/images/8%20-%20Smallest%20Resolution%20Phone.jpg)
Рис.3.8 - Отримання об'єкту Телефон з найменшою кількістю пікселів
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko04/images/9%20-%20Phones%20with%20two%20or%20more%20words.jpg)
Рис.3.9 - Виведення на екран усіх телефонів, які мають у назва 2 або більше слів
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko04/images/10%20-%20Exit%2C%20write%20data%20to%20file.jpg)
Рис.3.10 - Вихід, запис даних у файл
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko07/images/11%20-%20Result%20data%20in%20file.jpg)
Рис.3.11 - Остаточні дані у файлі

## 4 ТЕСТУВАННЯ
Нижче продемонстрован результат роботи двох функцій, які в свєму тілі викликають всі тестові методи.(рис.4.1)
![](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko04/images/12%20-%20Test%20all.jpg)
Рис.3.9 - Результат тестової функції

## ВИСНОВКИ

На лабораторній роботі отримано знання про базові регулярні вирази та досвід роботи
по застосуванню їх на практиці. У рамках лабораторної роботи розроблені функції, які перевіряються
рядок на наявність латинських символів, цифр, пропусків, розділових знаків, що повторюються; 
відсутність маленького символу на початку рядка та наявність полів з щонайменше двома словами.