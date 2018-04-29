#pragma once
#include "BasePerson.h"

//TODO: ��� ���������� � CPP-����//done
class Child : public BasePerson
{ //TODO: ���� ��������� ����������� private//done
private:
	string _school;
	BasePerson* _mother;
	BasePerson* _father;
public:
	//TODO:  ������������ ������ int//done
	Child(string name, string surname, int age, Sex sex, string school, BasePerson * Mother, BasePerson* Father);
	//��������� �������� ��� ��������
	virtual void SetAge(int age);
	//��������� �������� ���� Age
	virtual int GetAge();
	//��������� �������� ��� ������������ �����
	void SetSchool(string school);
	//��������� �������� ���� School
	string GetSchool();
	//������ � ��������
	virtual string GetDescription();
};
//��������� ������ � ��������
Child* GetRandomChild();

