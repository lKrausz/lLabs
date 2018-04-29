#pragma once
#include "BasePerson.h"
//TODO: ВСЮ РЕАЛИЗАЦИЮ В CPP-ФАЙЛ//done
class Adult : public BasePerson
{
	string _workPlace;
	BasePerson * _marriedOn;

public:
	//TODO:  перечисление вместо int//done
	Adult(string name, string surname, int age, Sex sex, string workPlace, BasePerson * marriedOn);
	//Установка значения для возраста
	virtual void SetAge(int age);
	//Получение значения поля Age
	virtual int GetAge();
	//Установка значения для рабочего места
	void SetWorkPlace(string workPlace);
	//Получение значения поля WorkPlace
	string GetWorkPlace();
	//Установка значения для семейного положения
	void SetMarried(BasePerson * marriedOn);
	//Получения значения поля MarriedOn
	BasePerson* GetMarried();
	//Данные о человеке
	virtual string GetDescription();
};
//Генератор данных о человеке
Adult* GetRandomAdult(); //TODO: грамматическая ошибка//done
