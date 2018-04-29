#pragma once
#include <string>
//TODO: ВСЮ РЕАЛИЗАЦИЮ В CPP-ФАЙЛ//done

using namespace std;//TODO: должна быть только одна пустая строка между неймспейсом и описанием класса//done

//TODO: 1) Абстрактные классы обозначаются словом Base, а не Abstract//done
//TODO: 2) Этот класс не должен быть абстрактным//done

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
	virtual void SetAge(int age); //TODO: почему у человека не может быть реализации возраста?//done
	//Получение значения поля Age
	virtual int GetAge(); //TODO: почему у человека не может быть реализации возраста?//done
	//Данные о человеке
	virtual string GetDescription(); //TODO: почему у человека не можеть быть реализации описания? ведь это по существу функция ShowPerson()//done

};

BasePerson* GetRandomPerson();
