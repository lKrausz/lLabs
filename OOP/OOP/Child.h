#pragma once
#include "BasePerson.h"

class Child : public BasePerson
{
private:
	string _school;
	BasePerson* _mother;
	BasePerson* _father;
public:
	Child(string name, string surname, int age, Sex sex, string school, BasePerson * Mother, BasePerson* Father);
	//Установка значения для возраста
	virtual void SetAge(int age);
	//Получение значения поля Age
	virtual int GetAge();
	//Установка значения для наименования школы
	void SetSchool(string school);
	//Получение значения поля School
	string GetSchool();
	//Данные о человеке
	virtual string GetDescription();
};
//Генератор данных о человеке
Child* GetRandomChild();

