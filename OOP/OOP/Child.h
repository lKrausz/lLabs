#pragma once
#include "BasePerson.h"

//TODO: ВСЮ РЕАЛИЗАЦИЮ В CPP-ФАЙЛ//done
class Child : public BasePerson
{ //TODO: явно указывать модификатор private//done
private:
	string _school;
	BasePerson* _mother;
	BasePerson* _father;
public:
	//TODO:  перечисление вместо int//done
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

