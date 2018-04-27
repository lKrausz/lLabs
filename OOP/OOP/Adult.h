#pragma once
#include "AbstractPerson.h"
//TODO: ��� ���������� � CPP-����
class Adult : public AbstractPerson
{
	string _workPlace;
	AbstractPerson * _marriedOn;

public:
	//TODO:  ������������ ������ int
	Adult(string name, string surname, int age, int sex, string workPlace, AbstractPerson * marriedOn)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);  //TODO:  ������������ ������ int
		SetMarried(marriedOn);
		SetWorkPlace(workPlace);
	}  //TODO: ������ ������
	virtual void SetAge(int age)
	{
		if (age < 18)
		{//TODO: ������ ���� ����������, ��� ��� ���-�� �������� ������� ���������-���������
			age = 18;
		}
		_age = age;
	} //TODO: ������ ������
	virtual int GetAge()
	{
		return _age;
	} //TODO: ������ ������
	void SetWorkPlace(string workPlace)
	{
		_workPlace = workPlace;
	} //TODO: ������ ������
	string GetWorkPlace()
	{
		return _workPlace;
	} //TODO: ������ ������
	void SetMarried(AbstractPerson * marrieOn)
	{
		_marriedOn = marrieOn;
	} //TODO: ������ ������
	AbstractPerson* GetMarried()
	{
		return _marriedOn;
	} //TODO: ������ ������
	virtual string GetDescription() //override
	{
		string description = _surname + ", " + _name + ", " + to_string(_age) + ", ";
		if (_sex == 0) //TODO: ����� ������ ������������, ���� �� ����� ��������� � int?
		{
			description = description + ", " + "famale";
		}
		else
		{
			description = description + ", " + "male";
		}
		if (_workPlace != "0") //TODO: ��� �� ������ � "0"? ������ ���� ������ ������ ������
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
Adult* GetRandomAdalt(); //TODO: �������������� ������
