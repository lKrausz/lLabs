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

//Вывод данных
void ShowPerson(Person person);
//Ввод данных
Person ReadPerson();
//Рандомные данные
Person ReadRandomPerson();
//Перенос const char строки в строку структуры Person
void CopyCharString(char* structString, const char* constString);