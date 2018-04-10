#pragma once
#include "ClassPerson.h"

class PersonListItem
{
public:
	Person* data;
	PersonListItem* next = NULL;
	PersonListItem* prev = NULL;
};

class PersonList
{
	PersonListItem* _head; 
	PersonListItem* _tail;
	//количество элементов в списке
	int _count; 

public:
	PersonList()
	{
		PersonListItem* _head;
		PersonListItem* _tail;
		int _count;
	}
	~PersonList()
	{
		while (_head != NULL)
		{
			PersonListItem *next = _head->next;
			delete _head->data;
			delete _head;
			_head = next;
		}
	}
	//добавить человека в список
	void Add(Person* person); 
	//найти человека по указанному индексу
	Person* Find(int index); 
	//вернуть индекс человека, если он есть в списке
	int IndexOf(Person* person); 
	//удалить человека из списка
	void Remove(Person* person); 
	//удалить человека из списка по индексу
	void RemoveAt(int index); 
	//очистить список
	void Clear();
	//получить количество элементов
	int GetCount();
	//вывести список на экран
	void ShowList(PersonList* list);
};