#pragma once
#include "AbstractPerson.h"

class Adult : public AbstractPerson
{
	string _workPlace;

public:
	AbstractPerson * MarriedOn;
	Adult(string name, string surname, int age, int sex) : AbstractPerson()
	{
		MarriedOn = nullptr;
		string _workPlace;
	}
	~Adult();
	virtual void SetAge(int age)
	{
		if (age < 18)
		{
			age = 18;
		}
		this->_age = age;
	}
	virtual int GetAge()
	{
		return this->_age;
	}
	void SetWorkPlace(string workPlace)
	{
		_workPlace = workPlace;
	}
	string GetWorkPlace()
	{
		return _workPlace;
	}
	virtual string GetDescription()
	{
		string description = _surname + ", " + _name + ", " + to_string(_age) + ", " + to_string(_sex);
		if (_workPlace != "0")
		{
			description = description + ", " + _workPlace;
		}
		else
		{
			description = description + ", Unemployee, ";
		}
		if (MarriedOn != nullptr)
		{
			description = description + "married on " + this->MarriedOn->GetName() + ", " + this->MarriedOn->GetSurname() + ".\0";
		}
		else
		{
			description = description + "single.\0";
		}
		return description;
	}
};
Adult* ReadAdult(string name, string surname, int age, int sex);

