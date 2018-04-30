#include "Child.h"
#include "Adult.h"
#include <iostream>


Child* GetRandomChild()
{
	string surname;
	string name;
	string school;
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
	const char *RandomSchool[] = { "Liceum #1", "State school #13", "State school #13", "State school #2", "0"};
	school = RandomSchool[rand() % 5];
	Child* person = new Child(name, surname, age, sex, school, GetRandomAdult(), GetRandomAdult());
	return person;
}

Child::Child(string name, string surname, int age, Sex sex, string school, BasePerson * Mother, BasePerson* Father)
{
	SetName(name);
	SetSurname(surname);
	SetAge(age);
	SetSex(sex); //TODO:  перечисление вместо int//done
	SetSchool(school);
	_mother = Mother;
	_father = Father;
}

void Child::SetAge(int age)
{
	try
	{
		if (age > 18)
			throw age; //TODO: лучше всё таки кидать экзепляры класса exception, а не int...
		else
			_age = age;
	}
	catch(int age) //TODO: Нет! Обработка исключения делается снаружи. Функция выбрасывает исключение, а код снаружи ловит исключение.
	{
		cout << "Age more then 18." << endl;
	}
}

int Child::GetAge()
{
	return _age;
}

void Child::SetSchool(string school)
{
		_school = school;
}

string Child::GetSchool()
{
	return _school;
}

string Child::GetDescription()
{
	string description = _surname + ", " + _name + ", " + to_string(_age);
	if (_sex == female)
	{
		description = description + ", " + "female";
	}
	else
	{
		description = description + ", " + "male";
	}
	description = description + ", " + _school;
	if (_mother != nullptr)
	{
		description = description + " Mother:  " + this->_mother->GetName() + ", " + this->_mother->GetSurname() + ".\0";
	}
	if (_father != nullptr)
	{
		description = description + " Father: " + this->_father->GetName() + ", " + this->_father->GetSurname() + ".\0";
	}
	if (_father == nullptr && _mother == nullptr)
	{
		description = description + "Parents are not specified.\0";
	}
	return description;
}