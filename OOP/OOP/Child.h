#pragma once
#include "AbstractPerson.h"
//TODO: ВСЮ РЕАЛИЗАЦИЮ В CPP-ФАЙЛ
class Child : public AbstractPerson
{ //TODO: явно указывать модификатор private
	string _school;
	AbstractPerson * _mother; //TODO: звездочка не должна висеть где-то посередине
	AbstractPerson* _father;
public:
	//TODO:  перечисление вместо int
	Child(string name, string surname, int age, int sex, string school, AbstractPerson * Mother,AbstractPerson* Father)
	{
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetSex(sex); //TODO:  перечисление вместо int
		SetSchool(school);
		_mother = Mother;
		_father = Father;
	}

	virtual void SetAge(int age)
	{
		if (age > 18)
			//TODO: должно быть исключение, потому что кто-то пытается создать взрослого-малолетку
			_age = 15;
		else
			_age = age;
	} //TODO: пустая строка
	virtual int GetAge()
	{
		return _age;
	} //TODO: пустая строка
	void SetSchool(string school)
	{
		if (school == "0") //TODO: что за строка с "0"? Должна быть просто пустая строка
			_school = "None.\0";
		else
			_school = school;
	} //TODO: пустая строка
	string GetSchool()
	{
		return _school;
	} //TODO: пустая строка
	virtual string GetDescription() //override
	{
		string description = _surname + ", " + _name + ", " + to_string(_age);
		if (_sex == 0) //TODO: зачем делать перечисление, если всё равно работаешь с int?
		{
			description = description + ", " + "famale";
		}
		else
		{
			description = description + ", " + "male";
		}
		if (_school != "0") //TODO: что за строка с "0"? Должна быть просто пустая строка
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

