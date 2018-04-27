#pragma once
#include "AbstractPerson.h"
//TODO: ВСЮ РЕАЛИЗАЦИЮ В CPP-ФАЙЛ
class Adult : public AbstractPerson
{
	string _workPlace;
	AbstractPerson * _marriedOn;

public:
	//TODO:  перечисление вместо int
	Adult(string name, string surname, int age, int sex, string workPlace, AbstractPerson * marriedOn)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex);  //TODO:  перечисление вместо int
		SetMarried(marriedOn);
		SetWorkPlace(workPlace);
	}  //TODO: пустая строка
	virtual void SetAge(int age)
	{
		if (age < 18)
		{//TODO: должно быть исключение, так как кто-то пытается создать взрослого-малолетку
			age = 18;
		}
		_age = age;
	} //TODO: пустая строка
	virtual int GetAge()
	{
		return _age;
	} //TODO: пустая строка
	void SetWorkPlace(string workPlace)
	{
		_workPlace = workPlace;
	} //TODO: пустая строка
	string GetWorkPlace()
	{
		return _workPlace;
	} //TODO: пустая строка
	void SetMarried(AbstractPerson * marrieOn)
	{
		_marriedOn = marrieOn;
	} //TODO: пустая строка
	AbstractPerson* GetMarried()
	{
		return _marriedOn;
	} //TODO: пустая строка
	virtual string GetDescription() //override
	{
		string description = _surname + ", " + _name + ", " + to_string(_age) + ", ";
		if (_sex == 0) //TODO: зачем делать перечисление, если всё равно работаешь с int?
		{
			description = description + ", " + "famale";
		}
		else
		{
			description = description + ", " + "male";
		}
		if (_workPlace != "0") //TODO: что за строка с "0"? Должна быть просто пустая строка
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
Adult* GetRandomAdalt(); //TODO: грамматическая ошибка
