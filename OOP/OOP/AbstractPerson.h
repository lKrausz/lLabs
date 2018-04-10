#pragma once
#include <string>
#include "ClassPerson.h"

using namespace std;



class AbstractPerson
{
protected:
	string _name;
	string _surname;
	int _age;
	Sex _sex;

public:

	void SetName(string name)
	{
		_name = name;
	}

	void SetSurname(string surname)
	{
		_surname = surname;
	}

	void SetSex(int sex)
	{
		switch (sex)
		{
		case 1:
		{
			_sex = male;
			break;
		}
		case 0:
		{
			_sex = female;
			break;
		}
		default:
			_sex = male;
		}
	}

	string GetName()
	{
		return _name;
	}

	string GetSurname()
	{
		return _surname;
	}

	int GetSex()
	{
		return _sex;
	}

	virtual void SetAge(int age) = 0;
	virtual int GetAge() = 0;
	virtual string GetDescription() = 0;


};

void ShowPerson(AbstractPerson* person);
