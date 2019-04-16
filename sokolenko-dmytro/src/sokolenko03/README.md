# ����������� ������ �3. ������ {#mainpage}

#### ����. 
������ � ��������: �������� ��������/��������� �� �������
�� � ����, ����� ���� _string_, _stringstream_.
#### ����. 
�������� ������ ��� ������ ������ � ��������� ��������� /
���������� �� ��� �++, ������ � ������� �� ������� ���� string.

## 1 ������
### 1.1 ���������
���������� ��� ����������:
- ��������� �.�.;
- ��� "�ϲ", ������� "���", ����� 1.ʲ� 102.8(�);
### 1.2 �������� ��������
�������� ��������� ����������� ������
��������� �����:
- ������������ ������� printf/scanf ������� �� ������������ _cin/cout_;
- �� ������������ ����� ������� �� ������������ _stringstream_;
- ������� ����� ������ ���������� ��� �ᒺ�� �� �����, �� �������
�����-���������� ��� �ᒺ��, ���� ��� ����� �������� �� �����;
- ������� ����� ����� ���������� ��� �ᒺ�� �� �����, �� ������
����� � ����������� ��� �ᒺ��, �������� ���� �� ������� �ᒺ�� ��
��� ���� ����������;
- �������� ����-������, ������ ��������� ������ ������ � �������
�� ��������� �������� ������ _(fstream)_ (���� �����������������
������� _fprintf/fscanf_ � ������� �� �� ����� _ifsteam/ofstream_), ���
����� ��������� ������ ������ ��������� ��������� �����:
- �������: _void CList::readFromFile(string fileName);_
�� _CList_ � ����-������ �ᒺ���, ��� ����� ��� ��������, ��
��� ���������� ������ � �����, �������� ��� ������
������ ���� ������;
- �����: _void CList::writeToFile(string fileName);_

### 1.3 �������� ����� ��������� ��������:
- ���������������� ��������� ������ �����;
- ���������������� ������ ����������� ������ �� ���������
��������� �����;
- �� ��������������� ����������� _�using namespace std;�_, ������
����� ��� ������ _�using�_ ������� ����������� �����: _using std::string,
using std::cout;_
- � ������ �� ������ ����������������� �������� �������� /
��������� ���� _�_, � ����� �� ������ ����������������� ����� ����
_char*_.

## 2 ���� ��������

### 2.1 ������������� �����������
�������� ���������� ��� ��������� �� ������� ������ ��'���� ���� Phone.

### 2.2 ���� ������ ���������
����� ���������������� ������� �����, ������������ � ������� � �� 
������ � �������� (��� 2.2.1)

![���.2.2.1 - ĳ������ �����](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/12%20-%20Class%20diagram.jpg)

## 3 ��в���� ������������

����� (���.3.1 - 3.10) ������� ������� ������������ ��������.
![���.3.1 - ������ ��������, �������� ����� � �����](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/1%20-%20Read%20data%20from%20file.jpg)
![���.3.2 - ������ ��� � ����](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/2%20-%20Source%20data%20in%20file.jpg)
![���.3.3 - ��������� ������ ��������](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/3%20-%20Add%20element.jpg)
![���.3.4 - ��������� ��������](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/4%20-%20Delete%20element.jpg)
![���.3.5 - ��������� �� �������](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/5%20-%20Get%20by%20index.jpg)
![���.3.6 - ³���������� ��������� ������ ������](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/7%20-%20Display%20size.jpg)
![���.3.7 - ��������� ��'���� ������� � ��������� ������� ������](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/8%20-%20Smallest%20Resolution%20Phone.jpg)
![���.3.8 - �����, ����� ����� � ����](https://github.com/cpp-khpi/kit1028a/blob/master/sokolenko-dmytro/doc/sokolenko03/images/9%20-%20Exit,%20write%20data%20to%20file.jpg?raw=true)
![���.3.9 - �������� ��� � ����](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/10%20-%20Result%20data%20in%20file.jpg)


## 4 ����������
����� ��������������� ��������� ������ �������, ��� � ���� �� ������� �� ������ ������.(���.4.1)
![���.3.9 - ��������� ������� �������](https://raw.githubusercontent.com/cpp-khpi/kit1028a/master/sokolenko-dmytro/doc/sokolenko03/images/11%20-%20Test%20all.jpg)

## ��������

�� ����������� ����� �������� ������ ��� ������ ������ � ��������� ���������/
���������� �� ��� �++, ������ � ������� �� ������� ���� string. ������� ������ ��������� �� ��������
������� �������� ����������� ����, �� ������ � �������� �� ������� string.