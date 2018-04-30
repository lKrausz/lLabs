#pragma once
#include <string>

using namespace std;

enum Sex
{
	female = 0,
	male = 1
};

class BasePerson
{
protected:
	string _name;
	string _surname;
	int _age;
	Sex _sex;

public:
	//��������� �������� ��� �����
	void SetName(string name);
	//��������� �������� ��� �������
	void SetSurname(string surname);
	//��������� �������� ��� ����
	void SetSex(Sex sex);
	//��������� �������� ���� Name
	string GetName();
	//��������� �������� ���� Surname
	string GetSurname();
	//��������� �������� ���� Sex
	Sex GetSex();
	//��������� �������� ��� ��������
	virtual void SetAge(int age);
	//��������� �������� ���� Age
	virtual int GetAge();
	//������ � ��������
	virtual string GetDescription();

};

BasePerson* GetRandomPerson();
