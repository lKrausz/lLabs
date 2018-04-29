#pragma once
#include "BasePerson.h"
//TODO: ��� ���������� � CPP-����//done
class Adult : public BasePerson
{
	string _workPlace;
	BasePerson * _marriedOn;

public:
	//TODO:  ������������ ������ int//done
	Adult(string name, string surname, int age, Sex sex, string workPlace, BasePerson * marriedOn);
	//��������� �������� ��� ��������
	virtual void SetAge(int age);
	//��������� �������� ���� Age
	virtual int GetAge();
	//��������� �������� ��� �������� �����
	void SetWorkPlace(string workPlace);
	//��������� �������� ���� WorkPlace
	string GetWorkPlace();
	//��������� �������� ��� ��������� ���������
	void SetMarried(BasePerson * marriedOn);
	//��������� �������� ���� MarriedOn
	BasePerson* GetMarried();
	//������ � ��������
	virtual string GetDescription();
};
//��������� ������ � ��������
Adult* GetRandomAdult(); //TODO: �������������� ������//done
