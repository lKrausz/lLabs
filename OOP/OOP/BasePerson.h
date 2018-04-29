#pragma once
#include <string>
//TODO: ��� ���������� � CPP-����//done

using namespace std;//TODO: ������ ���� ������ ���� ������ ������ ����� ����������� � ��������� ������//done

//TODO: 1) ����������� ������ ������������ ������ Base, � �� Abstract//done
//TODO: 2) ���� ����� �� ������ ���� �����������//done

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
	virtual void SetAge(int age); //TODO: ������ � �������� �� ����� ���� ���������� ��������?//done
	//��������� �������� ���� Age
	virtual int GetAge(); //TODO: ������ � �������� �� ����� ���� ���������� ��������?//done
	//������ � ��������
	virtual string GetDescription(); //TODO: ������ � �������� �� ������ ���� ���������� ��������? ���� ��� �� �������� ������� ShowPerson()//done

};

BasePerson* GetRandomPerson();
