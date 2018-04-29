#include "BasePerson.h"
#include "Child.h"
#include "Adult.h"

using namespace std;

string BasePerson::GetDescription()
{
	string description = _surname + ", " + _name + ", " + to_string(_age) + ", ";
	if (_sex == female) //TODO: зачем делать перечисление, если всё равно работаешь с int?//done?
	{
		description = description + ", " + "famale";
	}
	else
	{
		description = description + ", " + "male";
	}
	return description;
}

void BasePerson::SetAge(int age)
{
	_age = age;
}

int BasePerson::GetAge()
{
	return _age;
}
void BasePerson::SetName(string name)
{
	_name = name;
}

void BasePerson::SetSurname(string surname)
{
	_surname = surname;
}

//TODO: входной тип данных должен быть Sex, а не int. Иначе зря создавали перечисление//done
void BasePerson::SetSex(Sex sex)
{
	_sex = sex;
}

string BasePerson::GetName()
{
	return _name;
}

string BasePerson::GetSurname()
{
	return _surname;
}

//TODO: должен возращаться тип данных Sex, а не int//done
Sex BasePerson::GetSex()
{
	return _sex;
}


BasePerson* GetRandomPerson()
{

	int initPerson = rand() % 2;
	switch (initPerson)
	{
	case 1:
	{
		return GetRandomAdult();
	}
	case 0:
	{
		return GetRandomChild();
	}
	}
}
