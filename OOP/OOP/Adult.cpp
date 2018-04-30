#include "Adult.h"
#include "BasePerson.h"
#include <iostream>

Adult* GetRandomAdult()
{
	string surname;
	string name;
	string workPlace;
	Sex sex;
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
	const char *RandomWorkPlace[] = { "Google", "0", "Microsoft", "Facebook", "Valve" };
	workPlace = RandomWorkPlace[rand() % 5];
	Adult* person = new Adult(name, surname, age, sex, workPlace, nullptr);
	return person;
}

Adult::Adult(string name, string surname, int age, Sex sex, string workPlace, BasePerson * marriedOn)
{
	SetName(name);
	SetSurname(surname);
	SetAge(age);
	SetSex(sex); 
	SetMarried(marriedOn);
	SetWorkPlace(workPlace);
}

void Adult::SetAge(int age)
{
	try
	{
		if (age < 18)
			//TODO: тоже самое, что и в Child
			throw age;
		else
			_age = age;
	}
	catch (int age)
	{
		cout << "Age less then 18." << endl;
	}
}

int Adult::GetAge()
{
	return _age;
}

void Adult::SetWorkPlace(string workPlace)
{
	_workPlace = workPlace;
}

string Adult::GetWorkPlace()
{
	return _workPlace;
}

void Adult::SetMarried(BasePerson * marrieOn)
{
	_marriedOn = marrieOn;
}

BasePerson* Adult::GetMarried()
{
	return _marriedOn;
}

string Adult::GetDescription()
{
	string description = _surname + ", " + _name + ", " + to_string(_age) + ", ";
	if (_sex == female) //TODO: зачем делать перечисление, если всё равно работаешь с int? //done
	{
		description = description + ", " + "female";
	}
	else
	{
		description = description + ", " + "male";
	}
	description = description + ", " + _workPlace;
	if (_marriedOn != nullptr)
	{
		description = description + ", " + "married on " + _marriedOn->GetName() + ", " + _marriedOn->GetSurname() + ".\0";
	}
	else
	{
		description = description + ", " + " single.\0";
	}
	return description;
}