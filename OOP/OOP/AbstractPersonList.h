#pragma once
#include "AbstractPerson.h"
#include <iostream>
#include <iomanip>
//TODO: ��� ���������� ������� � CPP-����
//TODO: ��� �� ����� A � ������? ������� ����������! ����� Abstract �� �����
//TODO: ��� ������ ���� ��������� � List ����� ��� ������������� private - ����� �����, ����� ������, �� ��� ��������� ��� ����������
class APersonListItem
{
public:
	AbstractPerson * data; //TODO: ������������ ���������� ����
	APersonListItem* next = NULL; //TODO: ������������ ���������� ����
	APersonListItem* prev = NULL; //TODO: ������������ ���������� ����
};

//TODO: ��� �� ����� A � ������? ������� ����������! ����� Abstract �� �����
//TODO: ��� ������ �� ������ ���������� �� ����� ����� - ����� ��������� �������� ��� ��������� �������
class APersonList
{
	//TODO: ����������� private ���� ��������� ���� - �������� ����������
	APersonListItem* _head;
	APersonListItem* _tail;
	//���������� ��������� � ������ //TODO: ����������� � ���� ������� � ��������� �����
	int _count;

public:
	APersonList()
	{
		APersonListItem* _head;
		APersonListItem* _tail;
		int _count;
	}

	//TODO: ��������� ����������. ������ ���������� �� ����������� ������. �� ������ ������ �� ������� - ������ ������!
	~APersonList()
	{
		//TODO: ���������� ����� ��������� �� ����� �������. �������
		if(_head != nullptr)
		{
			APersonListItem* temp = _head;
			while (temp != nullptr)
			{
				//TODO: ��� if ��� �������� ����. ����� ����� if?
				if(temp->data != nullptr)
				{
					//delete temp->data;
				}
				temp = temp->next;
			}
		}
	}
	//�������� �������� � ������ //TODO: ����������� ������� �� ������� ������ �������. ���������

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
		//TODO: ����� � ����� ������ ��������� �������, ���� � ������ �������� ��������� _tail?
		while (node->next != nullptr)
			node = node->next;

		node->next = newPerson;
		newPerson->prev = node;
		_tail = newPerson;
	};

	//����� �������� �� ���������� �������
	AbstractPerson* Find(int index)
	{
		//TODO: � ����� ������� ���� ���������� ����������, � �� ���������� ������ ���������
		if (index > _count) return nullptr;
		//TODO: �������� �������� �� ������������� ��������

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
	}; //TODO: ������� ������ ���� �������� ����� ������ �������
	//������� ������ ��������, ���� �� ���� � ������
	int IndexOf(AbstractPerson* person)
	{
		APersonListItem* current = _head;
		int index = 0;
		//TODO: �������� �� for. While �������� ����������, � ����� �� ������������ ����
		while (current != nullptr && index <= _count)
		{
			//TODO: ��� �� ������? ���������� �� ����������� �������. ���� ���������� �������� � ��������� �������
			if (current->data->GetName() == person->GetName())
				if (current->data->GetSurname() == person->GetName())
					if (current->data->GetAge() == person->GetAge())
						if (current->data->GetSex() == person->GetSex())
							return index;
			current = current->next;
			index++;
		}
		return -1;
	}; //TODO: ������� ������ ���� �������� ����� ������ �������
	//������� �������� �� ������
	void Remove(AbstractPerson* person)
	{
		int index = IndexOf(person);
		RemoveAt(index);
	}; //TODO: ������� ������ ���� �������� ����� ������ �������
	//������� �������� �� ������ �� �������
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
		//������ ������
		if (node->prev == NULL)
		{
			_head = NULL;
			if (node->next != NULL)
			{
				_head = node->next;
				_head->prev = NULL;
			}
		}
		//����� ������
		if (node->next == NULL)
		{
			_tail = NULL;
			if (node->prev != NULL)
			{
				_tail = node->prev;
				_tail->next = NULL;
			}
		}
		//�������� ������
		if (node->next != NULL && node->prev != NULL)
		{
			node->next->prev = node->prev;
			node->prev->next = node->next;
		}
		delete node;
	}; //TODO: ������� ������ ���� �������� ����� ������ �������
	//�������� ������
	void NewClear()
	{ //TODO: ������ ����� New �� �������� ������
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
	//�������� ���������� ��������� //TODO: ����������� ������� �� �������

	int GetNewCount()
	{ //TODO: ������ ����� New �� �������� ������
		return _count;
	}; //TODO: ������ ������ ����� ���������
	//������� ������ �� �����
	void ShowNewList(APersonList* list)
	{ //TODO: ������ ����� New �� �������� �������
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