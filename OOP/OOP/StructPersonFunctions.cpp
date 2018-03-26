#include <iostream>
#include <ctime>
#include <random>
#include "StructPersonFunctions.h"
#include <iomanip> //TODO: Подписать комментарий, зачем подключается это библиотека
//TODO: Переименовать файл в соответствии с заголовочным файлом

//Ввод данных
Person ReadPerson()
{
	Person person;
	cout << "Enter surname: ";
	cin.getline(person.Surname, 30);
	cout << "Enter name: ";
	cin.getline(person.Name, 20);
	cout << "Enter sex: " << endl
		<< "0 for female "
		<< "1 for male: ";

	//TODO: Зациклить ввод пола до ввода правильного значения
	// Сейчас можно ввести в качестве пола, например, 15 - и программа отработает без инициализации пола
	int sex;
	cin >> sex;
	switch (sex)
	{
		case 1:
		{
			person.Sex = male;
			break;
		}
		case 0:
		{
			person.Sex = female;
			break;
		}
	}
	do
	{
		cout << "Enter age: " << endl;
		cin >> person.Age;
		if (person.Age < 0)
		{
			cout << "Incorrest value. Try again." << endl;
		}
	} while (person.Age < 0);
	return person;
}

//TODO: Продублировать комментарии из заголовочного файла - сейчас наведение мыши не показывает комментарий во всплывающей подсказке
void ShowPerson(Person person)
{
	//TODO: Почему setw(11), если на фамилию выделяется 30 символов? Как это отработает с длинными фамилиями?
	cout << setw(11) << person.Surname << setw(10) << person.Name;
	switch (person.Sex)
	{
	case 0:
		cout << setw(8) << "female";
		break;
	case 1:
		cout << setw(8) << "male";
		break;
	}
	cout << setw(3) << person.Age << endl;
}

void CopyCharString(char* structString, const char* constString)
{
	int i = 0;
	for (; constString[i]; i++)
	{
		structString[i] = constString[i];
	}
	structString[i] = '\0';
}

//TODO: Почему Read? Read - это когда с клавиатуры или из файла. Здесь же Get или Create/Generate
Person ReadRandomPerson()
{
	Person person;
	srand(time(NULL));
	person.Age = 1 + rand() % 100;
	int sex = rand() % 2;
	switch (sex)
	{
	case 1:
	{
		person.Sex = male;
		const char *maleSurname[] = { "Walter", "Krause", "Zimmer", "Regenherz", "Von-Webber" };
		CopyCharString(person.Surname, maleSurname[rand() % 5]);
		const char *maleName[] = { "Johann", "Walter", "Ludwig", "Karl", "Ulrich" };
		CopyCharString(person.Name, maleName[rand() % 5]);
		break;
	}
	case 0:
	{
		person.Sex = female;
		const char *femaleSurname[] = { "Marinelli", "Alfieri", "Bellini", "Ferrario", "Cortese" };
		CopyCharString(person.Surname, femaleSurname[rand() % 5]);
		const char *femaleName[] = { "Annabella", "Ottavia", "Laura", "Alessia", "Chiara" };
		CopyCharString(person.Name, femaleName[rand() % 5]);
		break;
	}
	}
	return person;
}
