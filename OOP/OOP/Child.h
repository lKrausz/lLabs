#pragma once
#include "AbstractPerson.h"

class Child : public AbstractPerson
{
	string _school;
public:
	AbstractPerson * Mother;
	AbstractPerson* Father;
	Child(string name, string surname, int age, int sex) : AbstractPerson()
	{
		Mother = nullptr;
		Father = nullptr;
	}

	//бесполезная проверка, которая никогда не будет задействована.
	virtual void SetAge(int age)
	{
		if (age > 18)
		{
			age = 17;
		} 
		this->_age = age;
	}
	virtual int GetAge()
	{
		return this->_age;
	}
	void SetSchool(string school)
	{
		if (school != "0")
			_school = "None.\0";
		else
			_school = school;
	}
	string GetSchool()
	{
		return _school;
	}
	virtual string GetDescription()
	{
		string description = _surname + ", " + _name + ", " + to_string(_age) + ", " + to_string(_sex);
		if (_school != "0")
		{
			description = description + ", " + _school;
		}
		if (Mother != nullptr)
		{
			description = description + "Mother:  " + this->Mother->GetName() + ", " + this->Mother->GetSurname() + ".\0";
		}
		if (Father != nullptr)
		{
			description = description + "Father: " + this->Father->GetName() + ", " + this->Father->GetSurname() + ".\0";
		}
		if(Father != nullptr && Mother != nullptr)
		{
			description = description + "Parents are not specified.\0";
		}
		return description;
	}
};

