#pragma once

//TODO: Убрать слова struct и functions из названия. Просто Person - и так будет понятно, что здесь Person и функции для работы с ним. Остальные слова в названии - мусор
//done
using namespace std;

enum Gender
{
	female = 0,
	male = 1
};

struct Person
{
	//TODO: Переходили бы уже на использование строк string. Массив символов это уже атавизм
	char Surname[20];
	char Name[15];
	Gender Sex;
	int Age;
};

//Вывод данных
void ShowPerson(Person person);
//Ввод данных
Person ReadPerson();
//Рандомные данные
Person CreateRandomPerson();
//TODO: Если сделать реализацию на string вместо char[], не надо будет писать такие функции
//done
//Перенос const char строки в строку структуры Person
void CopyCharString(char* structString, const char* constString);