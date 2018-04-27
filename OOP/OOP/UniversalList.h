#pragma once
//TODO: ���������� � ������������� ���������� ������ ���������� � ������ ������������. ���� ��� ����� ������ �������
#include "UniversalList.h" //TODO: ���� ���������� ��� ����?
#include "ClassPerson.h"

using namespace std;

template <typename T>
class UniversalList //TODO: ������ ����� Universal �� ��������
{
	template <typename TItem>
	class UniversalListItem //TODO: ������ ����� Universal �� ��������
	{
		TItem _value;

	public:

		UniversalListItem<TItem>* next = nullptr;
		UniversalListItem<TItem>* prev = nullptr;

		UniversalListItem() {};

		UniversalListItem(TItem data)
		{
			_value = data;
		};

		TItem GetValue()
		{
			return _value;
		};
	};

	UniversalListItem<T>* _head = nullptr;
	UniversalListItem<T>* _tail = nullptr;
	int _count = 0;

public:
	UniversalList() {};
	//TODO: ����� ��������� ��� data, � Insert ��������� ��� element - ������� ������������
	void Add(T data)
	{
		UniversalListItem<T>* temp = new UniversalListItem<T>(data);
		if (!_head)
		{
			_head = temp;
		}
		else
		{
			temp->prev = _tail;
			_tail->next = temp;
		}
		_tail = temp;
		_count++;
	};

	void Insert(T element, int index)
	{
		if (_head == nullptr || index < 0)
		{
			return;
		}

		UniversalListItem<T>* temp = _head;
		int i = 0;
		while (i < index)
		{
			temp = temp->next;
			i++;
			if (temp == nullptr)
			{
				//TODO: ����� � Insert ��������� ���������� �� Add, � � Add ������� ����� ������� Insert
				Add(element);
				return;
			}
		};//TODO: �� ���� ���� ������ ����� ����� ������� ���� � �������


		if (temp == _head)
		{
			UniversalListItem<T>* newNode = new UniversalListItem<T>();
			_head->prev = newNode;
			newNode->next = _head;

			_head = newNode;
			return;
		}

		if (temp == _tail)
		{
			UniversalListItem<T>* newNode = new UniversalListItem<T>(element);
			_tail->prev->next = newNode;
			newNode->prev = _tail->prev;
			newNode->next = _tail;
			_tail->prev = newNode;
			_tail->next = nullptr;
			return;
		} //TODO: ����� ������������ ����������... � ������ ����� ���� ��� ������ ������... � ����� ���� � ��������� � ��� �� �������... �������� � ��������


		if (temp != nullptr)
		{
			UniversalListItem<T>* newNode = new UniversalListItem<T>(element);
			temp->prev->next = newNode;
			newNode->prev = temp->prev;
			newNode->next = temp;
			temp->prev = newNode;
		}
		return;
	}

	T Find(int index)
	{
		if (index < 0)
		{
			return nullptr;
		}

		UniversalListItem<T>* current = _head;

		for (int i = 0; i < index; i++)
		{
			if (current->next)
			{
				current = current->next;
			}
		}
		return current->GetValue();
	};

	int IndexOf(T data)
	{
		UniversalListItem<T>* current = _head;
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
		UniversalListItem<T>* deletedElement = _head;

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

	void ShowList() //TODO: ������ Show. �� ���� ��������� �������� ������ � ��� ������� � �� ����� ������������ � list.ShowList - ����������
	{
		UniversalListItem<T>* current = _head;
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
		UniversalListItem<T>* current = _head;
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

	~UniversalList()
	{
		Clear();
	};

	friend ostream & operator<<(ostream & os, UniversalList<T>* l)
	{
		UniversalListItem<T>* temp = l->_head;
		while (temp)
		{
			os << temp->GetValue() << ' ';
			temp = temp->next;
		}
		return os;
	}
};

//TODO: ���� �������� ������������� ��� ������ Person, �� ���� ��� ������ ���� � ������ Person, � �� � ������
ostream& operator<<(ostream& os, Person* person)
{
	os << person->GetName() << ", " << person->GetSurname() << ", " << person->GetAge() << ", " << person->GetSex();
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