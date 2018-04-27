#pragma once
#include "AbstractPerson.h"
//TODO: ��� ���������� � CPP-����
class Child : public AbstractPerson
{ //TODO: ���� ��������� ����������� private
	string _school;
	AbstractPerson * _mother; //TODO: ��������� �� ������ ������ ���-�� ����������
	AbstractPerson* _father;
public:
	//TODO:  ������������ ������ int
	Child(string name, string surname, int age, int sex, string school, AbstractPerson * Mother,AbstractPerson* Father)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex); //TODO:  ������������ ������ int
		SetSchool(school);
		_mother = Mother;
		_father = Father;
	}

	virtual void SetAge(int age)
	{
		if (age > 18)
			//TODO: ������ ���� ����������, ������ ��� ���-�� �������� ������� ���������-���������
			_age = 15;
		else
			_age = age;
	} //TODO: ������ ������
	virtual int GetAge()
	{
		return _age;
	} //TODO: ������ ������
	void SetSchool(string school)
	{
		if (school == "0") //TODO: ��� �� ������ � "0"? ������ ���� ������ ������ ������
			_school = "None.\0";
		else
			_school = school;
	} //TODO: ������ ������
	string GetSchool()
	{
		return _school;
	} //TODO: ������ ������
	virtual string GetDescription() //override
	{
		string description = _surname + ", " + _name + ", " + to_string(_age);
		if (_sex == 0) //TODO: ����� ������ ������������, ���� �� ����� ��������� � int?
		{
			description = description + ", " + "famale";
		}
		else
		{
			description = description + ", " + "male";
		}
		if (_school != "0") //TODO: ��� �� ������ � "0"? ������ ���� ������ ������ ������
		{
			description = description + ", " + _school;
		}
		if (_mother != nullptr)
		{
			description = description + " Mother:  " + this->_mother->GetName() + ", " + this->_mother->GetSurname() + ".\0";
		}
		if (_father != nullptr)
		{
			description = description + " Father: " + this->_father->GetName() + ", " + this->_father->GetSurname() + ".\0";
		}
		if(_father == nullptr && _mother == nullptr)
		{
			description = description + "Parents are not specified.\0";
		}
		return description;
	}
};

Child* GetRandomChild();

