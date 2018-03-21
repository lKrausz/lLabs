#include <iostream>
#include <ctime>
#include <random>
#include "StructPersonFunctions.h"

//¬вод данных
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

	int sex;
	cin >> sex;
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

void ShowPerson(Person person)
{
	cout << "Surname: " << person.Surname << endl;
	cout << "Name: " << person.Name << endl;
	switch (person.Sex)
	{
	case 0:
		cout << "Sex: female" << endl;
		break;
	case 1:
		cout << "Sex: male" << endl;
		break;
	default:
		break;
	}
	cout << "Age: " << person.Age << endl;
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

Person ReadRandomPerson()
{
	Person person;
	srand(time(NULL));
	person.Age = rand() % 10;
	int sex = rand() % 1;

	switch (sex)
	{
	case 1:
	{
		const char *maleSurname[] = { "Walter", "Krause", "Zimmer", "Regenherz", "Von-Webber" };
		CopyCharString(person.Surname, maleSurname[rand() % 5]);
		const char *maleName[] = { "Johann", "Walter", "Ludwig", "Karl", "Ulrich" };
		CopyCharString(person.Name, maleName[rand() % 5]);

	}
	case 0:
	{
		const char *femaleSurname[] = { "Marinelli", "Alfieri", "Bellini", "Ferrario", "Cortese" };
		CopyCharString(person.Surname, femaleSurname[rand() % 5]);
		const char *femaleName[] = { "Annabella", "Ottavia", "Laura", "Alessia", "Chiara" };
		CopyCharString(person.Name, femaleName[rand() % 5]);
	}
	}
	return person;
}
