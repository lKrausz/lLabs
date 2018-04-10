#pragma once
#include <string>

using namespace std;

enum Sex
{
	female = 0,
	male = 1
};

class Person
{
	string _name;
	string _surname;
	int _age;
	Sex _sex;
public:
	Person(string name, string surname, int age, enum Sex sex)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
	}
	void SetName(string name)
	{
		_name = name;
	}

	void SetSurname(string surname)
	{
		_surname = surname;
	}

	void SetAge(int age)
	{
		_age = age;
	}

	void SetSex(enum Sex sex)
	{
		_sex = sex;
	}

	string GetName()
	{
		return _name;
	}

	string GetSurname()
	{
		return _surname;
	}

	int GetAge()
	{
		return _age;
	}

	int GetSex()
	{
		return _sex;
	}

	
};

Person* GetRandomPerson();
Person* ReadPerson();
void ShowPerson(Person* person);