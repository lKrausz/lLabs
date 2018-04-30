#include "PersonList.h"
#include "BasePerson.h"
#include <iostream>

PersonList::PersonList()
{
	PersonListItem* _head;
	PersonListItem* _tail;
	int _count;
}

PersonList::~PersonList()
{
	Clear();
}

void PersonList::Add(BasePerson* person)
{
	_count++;
	PersonListItem* newPerson = new PersonListItem();
	newPerson->Data = person;
	newPerson->Next = NULL;
	newPerson->Prev = NULL;

	int i = 0;
	PersonListItem* node = _head;

	if (_head == NULL)
	{
		_head = newPerson;
		_tail = newPerson;
		return;
	}

	_tail->Next = newPerson;
	newPerson->Prev = _tail;
	_tail = newPerson;
};


BasePerson* PersonList::Find(int index)
{
	PersonListItem* current = _head;
	for (int i = 0; i < _count; i++)
	{
		if (current != nullptr)
		{
			if (i == index)
			{
				return current->Data;
			}
			current = current->Next;
		}
		else return nullptr;
	}
	return nullptr;
}; 
  
int PersonList::IndexOf(BasePerson* person)
{
	PersonListItem* current = _head;
	for (int index = 0; index <= _count; index++)
	{
		if (current != nullptr) //TODO: Здесь лучше сделать инверсию условия - if (current == nullptr) break; или сразу if (current == nullptr) return -1;
		{
			if (current->Data == person) return index;
			current = current->Next;
		}
	}
	return -1;
}; 
   
void PersonList::Remove(BasePerson* person)
{
	int index = IndexOf(person);
	RemoveAt(index);
}; 

void PersonList::RemoveAt(int index)
{
	_count--;
	if (_head == NULL || index >_count)
		return;
	int i = 0;
	PersonListItem* node = _head;
	while (i != index && node != NULL)
	{
		++i;
		node = node->Next;
	}
	if (node == NULL)
		return;
	//Начало списка
	if (node->Prev == NULL)
	{
		_head = NULL;
		if (node->Next != NULL)
		{
			_head = node->Next;
			_head->Prev = NULL;
		}
	}
	//Конец списка
	if (node->Next == NULL)
	{
		_tail = NULL;
		if (node->Prev != NULL)
		{
			_tail = node->Prev;
			_tail->Next = NULL;
		}
	}
	//Середина списка
	if (node->Next != NULL && node->Prev != NULL)
	{
		node->Next->Prev = node->Prev;
		node->Prev->Next = node->Next;
	}
	delete node;
};

void PersonList::Clear()
{ 
	_count = 0;
	PersonListItem* current = _head;
	if (current)
	{
		while (current->Next)
		{
			current = current->Next;
			delete current->Prev;
		}
		delete current;

		_head = NULL;
		_tail = NULL;
	}
};

int PersonList::GetCount()
{ 
	return _count;
}; 

void PersonList::Show(PersonList* list)
{ 
	PersonListItem* current = _head;
	if (_head == nullptr)
		return;
	int i = 0;
	cout << "List:" << endl;
	while (current != nullptr)
	{
		cout << i++ << ".";
		cout << current->Data->GetDescription() << endl;
		current = current->Next;
	}
	cout << endl;
};
