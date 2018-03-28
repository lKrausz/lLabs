#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

enum Sex
{
	female = 0,
	male = 1
};

class Person
{
	string Name;
	string Surname;
	int Age;
	Sex Sex;
public:
	Person(string name, string surname, int age, enum Sex sex)
	{
		Name = name;
		Surname = surname;
		Age = age;
		Sex = sex;
	}

	void SetName(string name)
	{
		Name = name;
	}

	void SetSurname(string surname)
	{
		Surname = surname;
	}

	void SetAge(int age)
	{
		Age = age;
	}

	void SetSex(enum Sex sex)
	{
		Sex = sex;
	}

	string GetName()
	{
		return Name;
	}

	string GetSurname()
	{
		return Surname;
	}

	int GetAge()
	{
		return Age;
	}

	int GetSex()
	{
		return Sex;
	}

	static Person* GetRandomPerson();
};

Person* ReadPerson();
void ShowPerson(Person* person);