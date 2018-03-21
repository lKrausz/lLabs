#pragma once


using namespace std;

enum Gender
{
	female = 0,
	male = 1
};

struct Person
{
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
//������� const char ������ � ������ ��������� Person
void CopyCharString(char* structString, const char* constString);