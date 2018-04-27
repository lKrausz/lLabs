#pragma once
#include <string>
#include "ClassPerson.h" //TODO: этого файла нет в проекте. Добавить!
//TODO: ВСЮ РЕАЛИЗАЦИЮ В CPP-ФАЙЛ

using namespace std;//TODO: должна быть только одна пустая строка между неймспейсом и описанием класса


//TODO: 1) Абстрактные классы обозначаются словом Base, а не Abstract
//TODO: 2) Этот класс не должен быть абстрактным
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

	//TODO: входной тип данных должен быть Sex, а не int. Иначе зря создавали перечисление
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

	//TODO: должен возращаться тип данных Sex, а не int
	int GetSex()
	{
		return _sex;
	}

	virtual void SetAge(int age) = 0; //TODO: почему у человека не может быть реализации возраста?
	virtual int GetAge() = 0; //TODO: почему у человека не может быть реализации возраста?
	virtual string GetDescription() = 0; //TODO: почему у человека не можеть быть реализации описания? ведь это по существу функция ShowPerson()

};

//TODO: реализацию функции перенести в GetDescription(), от этой функции избавиться
void ShowPerson(AbstractPerson* person);

