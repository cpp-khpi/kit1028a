# Лабораторна робота №3. Потоки {#mainpage}

#### Тема. 
Робота з потоками: потокове введення/виведення на консоль
та у файл, рядки типу _string_, _stringstream_.
#### Мета. 
Отримати знання про основи роботи з потоковим введенням /
виведенням на мові С++, роботу з файлами та рядками типу string.

## 1 ВИМОГИ
### 1.1 Розробник
Інформація про розробника:
- Соколенко Д.Г.;
- НТУ "ХПІ", кафедра "ОТП", група 1.КІТ 102.8(а);
### 1.2 Загальне завдання
Поширити попередню лабораторну роботу
наступним чином:
- використання функцій printf/scanf замінити на використання _cin/cout_;
- усі конкатенації рядків замінити на використання _stringstream_;
- замінити метод виводу інформації про об’єкт на метод, що повертає
рядок-інформацію про об’єкт, який далі можна виводити на екран;
- замінити метод вводу інформації про об’єкт на метод, що приймає
рядок з інформацією про об’єкт, обробляє його та створює об’єкт на
базі цієї інформації;
- поширити клас-список, шляхом реалізації методів роботи з файлами
за допомогою файлових потоків _(fstream)_ (якщо використовувалися
функції _fprintf/fscanf_ – замінити їх на класи _ifsteam/ofstream_), при
цьому сигнатури методів повинні виглядати наступним чином:
- читання: _void CList::readFromFile(string fileName);_
де _CList_ – клас-список об’єктів, при цьому слід пам’ятати, що
при повторному читанні з файлу, попередні дані списку
повинні бути очищені;
- запис: _void CList::writeToFile(string fileName);_

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

### 2.1 Функціональне призначення
Програма призначена для створення та обробки масиву об'єктів типу Phone.

### 2.2 Опис логічної структури
Нижче продемонстрована діаграма класів, використаних у програмі з їх 
полями й методами (рис 2.2.1)

![Рис.2.2.1 - Діаграма класів](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/12%20-%20Class%20diagram.jpg)

## 3 ВАРІАНТИ ВИКОРИСТАННЯ

Нижче (рис.3.1 - 3.10) показані варіанти використання програми.
![Рис.3.1 - Запуск програми, зчитання даних з файлу](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/1%20-%20Read%20data%20from%20file.jpg)
![Рис.3.2 - Вихідні дані у файлі](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/2%20-%20Source%20data%20in%20file.jpg)
![Рис.3.3 - Додавання нового елементу](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/3%20-%20Add%20element.jpg)
![Рис.3.4 - Видалення елементу](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/4%20-%20Delete%20element.jpg)
![Рис.3.5 - Отримання по індексу](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/5%20-%20Get%20by%20index.jpg)
![Рис.3.6 - Відображення поточного розміру масиву](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/7%20-%20Display%20size.jpg)
![Рис.3.7 - Отримання об'єкту Телефон з найменшою кількістю пікселів](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/8%20-%20Smallest%20Resolution%20Phone.jpg)
![Рис.3.8 - Вихід, запис даних у файл](https://github.com/cpp-khpi/kit1028a/blob/master/sokolenko-dmytro/doc/sokolenko03/images/9%20-%20Exit,%20write%20data%20to%20file.jpg?raw=true)
![Рис.3.9 - Остаточні дані у файлі](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/10%20-%20Result%20data%20in%20file.jpg)


## 4 ТЕСТУВАННЯ
Нижче продемонстрован результат роботи функції, яка в свєму тілі викликає всі тестові методи.(рис.4.1)
![Рис.3.9 - Результат тестової функції](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/11%20-%20Test%20all.jpg)

## ВИСНОВКИ

На лабораторній роботі отримано знання про основи роботи з потоковим введенням/
виведенням на мові С++, роботу з файлами та рядками типу string. Отримані знання закріплено на практиці
методом розробки програмного кода, що працює з потоками та рядками string.