#pragma once
#include "ClassPerson.h"

Person* ReadPerson()
{
	string surname;
	string name;
	int age;
	enum Sex sex;

	cout << "Enter surname: ";
	cin >> surname;
	cout << "Enter name: ";
	cin >> name;

	int initSex;
	do
	{
		cout << "Enter sex: " << endl
			<< "0 for female " << endl
			<< "1 for male: " << endl;

		cin >> initSex;
		switch (initSex)
		{
		case 1:
		{
			sex = male;
			break;
		}
		case 0:
		{
			sex= female;
			break;
		}
		default:
			cout << "Incorrect value." << endl << endl;
		}
	} while (initSex < 0 || initSex > 1);

	do
	{
		cout << "Enter age: " << endl;
		cin >> age;
		if (age < 0)
		{
			cout << "Incorrest value. Try again." << endl;
		}
	} while (age < 0);
	Person* person = new Person(name, surname, age, sex);
	return person;
}

void ShowPerson(Person* person)
{
	cout << setw(20) << person->GetSurname()
		<< setw(15) << person->GetName();
	switch (person->GetSex())
	{
	case 0:
		cout << setw(8) << "female";
		break;
	case 1:
		cout << setw(8) << "male";
		break;
	}
	cout << setw(3) << person->GetAge() << endl;
}

Person* Person::GetRandomPerson()
{
	string surname;
	string name;
	enum Sex sex;
	int age = 1 + rand() % 100;
	int initSex = rand() % 2;
	switch (initSex)
	{
		case 1:
		{
			sex = male;
			const char *maleSurname[] = { "Walter", "Krause", "Zimmer", "Regenherz", "Von-Webber" };
			surname = maleSurname[rand() % 5];
			const char *maleName[] = { "Johann", "Walter", "Ludwig", "Karl", "Ulrich" };
			name = maleName[rand() % 5];
			break;
		}
		case 0:
		{
			sex = female;
			const char *femaleSurname[] = { "Marinelli", "Alfieri", "Bellini", "Ferrario", "Cortese" };
			surname = femaleSurname[rand() % 5];
			const char *femaleName[] = { "Annabella", "Ottavia", "Laura", "Alessia", "Chiara" };
			name = femaleName[rand() % 5];
			break;
		}
	}
	Person* person = new Person(name, surname, age, sex);
	return person;
}