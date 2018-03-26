#pragma once

//TODO: ������ ����� struct � functions �� ��������. ������ Person - � ��� ����� �������, ��� ����� Person � ������� ��� ������ � ���. ��������� ����� � �������� - �����
using namespace std;

enum Gender
{
	female = 0,
	male = 1
};

struct Person
{
	//TODO: ���������� �� ��� �� ������������� ����� string. ������ �������� ��� ��� �������
	char Surname[30];
	char Name[20];
	Gender Sex;
	int Age;
};

//����� ������
void ShowPerson(Person person);
//���� ������
Person ReadPerson();
//��������� ������
Person ReadRandomPerson();
//TODO: ���� ������� ���������� �� string ������ char[], �� ���� ����� ������ ����� �������
//������� const char ������ � ������ ��������� Person
void CopyCharString(char* structString, const char* constString);