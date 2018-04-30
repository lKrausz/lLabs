#pragma once
#include "BasePerson.h"

using namespace std;

template <typename T>
class List //TODO: ������ ����� Universal �� ��������//done
{
	template <typename TItem>
	class ListItem //TODO: ������ ����� Universal �� ��������//done
	{
		TItem _value;

	public:

		ListItem<TItem>* next = nullptr;
		ListItem<TItem>* prev = nullptr;

		ListItem() {};

		ListItem(TItem data)
		{
			_value = data;
		};

		TItem GetValue()
		{
			return _value;
		};
	};

	ListItem<T>* _head = nullptr;
	ListItem<T>* _tail = nullptr;
	int _count = 0;

public:
	List() {};

	//���������� �������� � �����
	void Add(T data)
	{
		this->Insert(data, _count);
	};

	//������� ��������
	void Insert(T data, int index)
	{
		if (index < 0 || index > _count) return;

		_count++;

		ListItem<T>* newNode = new ListItem<T>(data);
		newNode->next = NULL;
		newNode->prev = NULL;
		
		if (_head == NULL)
		{
			_head = newNode;
			_tail = newNode;
			return;
		}
		
		ListItem<T>* current = _head;
		for (int i = 1; i < index && current->next != NULL; i++)
			current = current->next;
		if (index == 0)
		{
			//��������� ����� ������� �� ������ �����
			newNode->next = _head;
			_head->prev = newNode;
			_head = newNode;
		}
		else
		{
			//��������� ����� ������� �� �������� �����
			if (current->next != NULL)
				current->next->prev = newNode;
			newNode->next = current->next;
			current->next = newNode;
			newNode->prev = current;
			current = newNode;
		}
	}

	T Find(int index)
	{
		if (index < 0)
		{
			//TODO: ��� ����� ������ ������������� �������, ������ �������. 
			// ��� ������� ������ �������� ������ � ������� ����������, ��� � �� �������� ���-�� ������������
			return nullptr;
		}

		ListItem<T>* current = _head;

		for (int i = 0; i < index; i++)
		{
			if (current->next)
			{
				current = current->next;
			}
		}
		return current->GetData();
	};

	int IndexOf(T data)
	{
		ListItem<T>* current = _head;
		int index = 0;
		while (current)
		{
			if (current->GetValue() == data)
			{
				return index;
			}
			index++;
			current = current->next;
		}
		return -1;
	};

	int GetCount()
	{
		return _count;
	};

	void Remove(T data)
	{
		int index = IndexOf(data);
		RemoveAt(index);
	};

	void RemoveAt(int index)
	{
		_count--;
		if (_head == NULL || index >_count)
			return;
		int i = 0;
		ListItem<T>* deletedElement = _head;

		while (i != index && deletedElement != NULL)
		{
			++i;
			deletedElement = deletedElement->next;
		}
		if (deletedElement == NULL)
			return;
		//������ ������
		if (deletedElement->prev == NULL)
		{
			_head = NULL;
			if (deletedElement->next != NULL)
			{
				_head = deletedElement->next;
				_head->prev = NULL;
			}
		}
		//����� ������
		if (deletedElement->next == NULL)
		{
			_tail = NULL;
			if (deletedElement->prev != NULL)
			{
				_tail = deletedElement->prev;
				_tail->next = NULL;
			}
		}
		//�������� ������
		if (deletedElement->next != NULL && deletedElement->prev != NULL)
		{
			deletedElement->next->prev = deletedElement->prev;
			deletedElement->prev->next = deletedElement->next;
		}
		delete deletedElement;
	};

	void Show()
	{
		ListItem<T>* current = _head;
		if (_head == nullptr)
			return;
		int i = 0;
		cout << "List:" << endl;
		if (current)
		{
			while (current)
			{
				cout << ++i << ":\t" << current->GetValue() << endl;
				current = current->next;
			}
		}
		else
		{
			cout << "List empty" << endl;
		}
		cout << endl;
	};

	void Clear()
	{
		_count = 0;
		ListItem<T>* current = _head;
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

	~List()
	{
		Clear();
	};

	friend ostream & operator<<(ostream& os, List<T>* l)
	{
		ListItem<T>* temp = l->_head;
		while (temp)
		{
			os << temp->GetValue() << ' ';
			temp = temp->next;
		}
		return os;
	}
};

//TODO: ���� �������� ������������� ��� ������ Person, �� ���� ��� ������ ���� � ������ Person, � �� � ������//��� ��� �� ������� //�� ��� ���� �����������, ������ �� �������. � �������, ����� �������
ostream& operator<<(ostream& os, BasePerson* person)
{
	os << person->GetDescription();
	return os;
}

ostream& operator<<(ostream& os, double* d)
{
	for (int i = 0; i < 5; i++)
	{
		os << d[i] << ' ';
	}
	return os;
}