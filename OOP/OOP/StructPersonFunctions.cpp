#include <iostream>
#include <ctime>
#include <random>
#include "StructPersonFunctions.h"
#include <iomanip>


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

void ShowPerson(Person person)
{
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
