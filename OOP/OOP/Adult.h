#pragma once
#include "AbstractPerson.h"

class Adult : public AbstractPerson
{
	string _workPlace;
	AbstractPerson * _marriedOn;

public:
	
	Adult(string name, string surname, int age, int sex, string workPlace, AbstractPerson * marriedOn)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);
		SetMarried(marriedOn);
		SetWorkPlace(workPlace);
	}
	virtual void SetAge(int age)
	{
		if (age < 18)
		{
			age = 18;
		}
		_age = age;
	}
	virtual int GetAge()
	{
		return _age;
	}
	void SetWorkPlace(string workPlace)
	{
		_workPlace = workPlace;
	}
	string GetWorkPlace()
	{
		return _workPlace;
	}
	void SetMarried(AbstractPerson * marrieOn)
	{
		_marriedOn = marrieOn;
	}
	AbstractPerson* GetMarried()
	{
		return _marriedOn;
	}
	virtual string GetDescription() //override
	{
		string description = _surname + ", " + _name + ", " + to_string(_age) + ", ";
		if (_sex == 0)
		{
			description = description + ", " + "famale";
		}
		else
		{
			description = description + ", " + "male";
		}
		if (_workPlace != "0")
		{
			description = description + ", " + _workPlace;
		}
		else
		{
			description = description + ", Unemployee";
		}
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
};
Adult* GetRandomAdalt();
