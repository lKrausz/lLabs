#pragma once
#include <string>
#include "ClassPerson.h" //TODO: ����� ����� ��� � �������. ��������!
//TODO: ��� ���������� � CPP-����

using namespace std;//TODO: ������ ���� ������ ���� ������ ������ ����� ����������� � ��������� ������


//TODO: 1) ����������� ������ ������������ ������ Base, � �� Abstract
//TODO: 2) ���� ����� �� ������ ���� �����������
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

	//TODO: ������� ��� ������ ������ ���� Sex, � �� int. ����� ��� ��������� ������������
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

	//TODO: ������ ����������� ��� ������ Sex, � �� int
	int GetSex()
	{
		return _sex;
	}

	virtual void SetAge(int age) = 0; //TODO: ������ � �������� �� ����� ���� ���������� ��������?
	virtual int GetAge() = 0; //TODO: ������ � �������� �� ����� ���� ���������� ��������?
	virtual string GetDescription() = 0; //TODO: ������ � �������� �� ������ ���� ���������� ��������? ���� ��� �� �������� ������� ShowPerson()

};

//TODO: ���������� ������� ��������� � GetDescription(), �� ���� ������� ����������
void ShowPerson(AbstractPerson* person);

