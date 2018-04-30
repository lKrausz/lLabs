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
	//Установка значения для имени
	void SetName(string name);
	//Установка значения для фамилии
	void SetSurname(string surname);
	//Установка значения для пола
	void SetSex(Sex sex);
	//Получение значения поля Name
	string GetName();
	//Получение значения поля Surname
	string GetSurname();
	//Получение значения поля Sex
	Sex GetSex();
	//Установка значения для возраста
	virtual void SetAge(int age);
	//Получение значения поля Age
	virtual int GetAge();
	//Данные о человеке
	virtual string GetDescription();

};

BasePerson* GetRandomPerson();
