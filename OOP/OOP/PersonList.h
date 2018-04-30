#pragma once
#include "BasePerson.h"

class PersonList
{
private:
	class PersonListItem
	{

	public:
		BasePerson * Data;
		PersonListItem* Next = nullptr;
		PersonListItem* Prev = nullptr;
	};

	PersonListItem* _head;
	PersonListItem* _tail;
	int _count;

public:
	PersonList();
	~PersonList();
	//Добавить человека в список
	void Add(BasePerson* person);
	//Найти человека по указанному индексу
	BasePerson* Find(int index);
	//Вернуть индекс человека, если он есть в списке
	int IndexOf(BasePerson* person);
	//Удалить человека из списка
	void Remove(BasePerson* person);
	//Удалить человека из списка по индексу
	void RemoveAt(int index);
	//Очистить список
	void Clear();
	//Получить количество элементов списка
	int GetCount();
	//Вывести список на экран
	void Show(PersonList* list);
};