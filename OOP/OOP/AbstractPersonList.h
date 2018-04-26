#pragma once
#include "AbstractPerson.h"
#include <iostream>
#include <iomanip>

class APersonListItem
{
public:
	AbstractPerson * data;
	APersonListItem* next = NULL;
	APersonListItem* prev = NULL;
};

class APersonList
{
	APersonListItem* _head;
	APersonListItem* _tail;
	//количество элементов в списке
	int _count;

public:
	APersonList()
	{
		APersonListItem* _head;
		APersonListItem* _tail;
		int _count;
	}

	~APersonList()
	{
		if(_head != nullptr)
		{
			APersonListItem* temp = _head;
			while (temp != nullptr)
			{
				if(temp->data != nullptr)
				{
					//delete temp->data;
				}
				temp = temp->next;
			}
		}
	}
	//добавить человека в список

	void Add(AbstractPerson* person)
	{
		_count++;
		APersonListItem* newPerson = new APersonListItem();
		newPerson->data = person;
		newPerson->next = NULL;
		newPerson->prev = NULL;

		int i = 0;
		APersonListItem* node = _head;

		if (_head == NULL)
		{
			_head = newPerson;
			_tail = newPerson;
			return;
		}

		while (node->next != nullptr)
			node = node->next;

		node->next = newPerson;
		newPerson->prev = node;
		_tail = newPerson;
	};

	//найти человека по указанному индексу
	AbstractPerson* Find(int index)
	{
		if (index > _count) return nullptr;

		APersonListItem* current = _head;
		for (int i = 0; i < _count; i++)
		{
			if (current != nullptr)
			{
				if (i == index)
				{
					return current->data;
				}
				current = current->next;
			}
			else return nullptr;
		}
		return nullptr;
	};
	//вернуть индекс человека, если он есть в списке
	int IndexOf(AbstractPerson* person)
	{
		APersonListItem* current = _head;
		int index = 0;
		while (current != nullptr && index <= _count)
		{
			if (current->data->GetName() == person->GetName())
				if (current->data->GetSurname() == person->GetName())
					if (current->data->GetAge() == person->GetAge())
						if (current->data->GetSex() == person->GetSex())
							return index;
			current = current->next;
			index++;
		}
		return -1;
	};
	//удалить человека из списка
	void Remove(AbstractPerson* person)
	{
		int index = IndexOf(person);
		RemoveAt(index);
	};
	//удалить человека из списка по индексу
	void RemoveAt(int index)
	{
		_count--;
		if (_head == NULL || index >_count)
			return;
		int i = 0;
		APersonListItem* node = _head;
		while (i != index && node != NULL)
		{
			++i;
			node = node->next;
		}
		if (node == NULL)
			return;
		//начало списка
		if (node->prev == NULL)
		{
			_head = NULL;
			if (node->next != NULL)
			{
				_head = node->next;
				_head->prev = NULL;
			}
		}
		//конец списка
		if (node->next == NULL)
		{
			_tail = NULL;
			if (node->prev != NULL)
			{
				_tail = node->prev;
				_tail->next = NULL;
			}
		}
		//середина списка
		if (node->next != NULL && node->prev != NULL)
		{
			node->next->prev = node->prev;
			node->prev->next = node->next;
		}
		delete node;
	};
	//очистить список
	void NewClear()
	{
		_count = 0;
		APersonListItem* current = _head;
		if (current)
		{
			while (current->next)
			{
				current = current->next;
				delete current->prev;
			}
			delete current;

			_head = NULL;
			_tail = NULL;
		}
	};
	//получить количество элементов

	int GetNewCount()
	{
		return _count;
	};
	//вывести список на экран
	void ShowNewList(APersonList* list)
	{
		APersonListItem* current = _head;
		if (_head == nullptr)
			return;
		int i = 0;
		cout << "List:" << endl;
		cout << setw(10) << left
			<< setw(3) << "#"
			<< setw(20) << "Surname"
			<< setw(15) << "Name"
			<< setw(8) << "Sex"
			<< setw(3) << "Age"
			<< endl;
		while (current != nullptr)
		{
			cout << i++ << ".";
			ShowPerson(current->data);
			current = current->next;
		}
		cout << endl;
	};
};