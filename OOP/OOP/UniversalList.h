#pragma once
//TODO: структурно и синтаксически реализация списка поменялась с шестой лабораторной. Этот код писал другой человек
#include "UniversalList.h" //TODO: файл подключает сам себя?
#include "ClassPerson.h"

using namespace std;

template <typename T>
class UniversalList //TODO: убрать слово Universal из названия
{
	template <typename TItem>
	class UniversalListItem //TODO: убрать слово Universal из названия
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
	//TODO: здесь именуется как data, в Insert именуется как element - сделать единообразно
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
				//TODO: Лучше в Insert перенести реализацию из Add, а в Add сделать вызов функции Insert
				Add(element);
				return;
			}
		};//TODO: не надо двух пустых строк между блоками кода в функции


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
		} //TODO: Какое удивительное совпадение... У Начына здесь тоже две пустые строки... И блоки кода с условиями в том же порядке... Готовься к вопросам


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
		//начало списка
		if (deletedElement->prev == NULL)
		{
			_head = NULL;
			if (deletedElement->next != NULL)
			{
				_head = deletedElement->next;
				_head->prev = NULL;
			}
		}
		//конец списка
		if (deletedElement->next == NULL)
		{
			_tail = NULL;
			if (deletedElement->prev != NULL)
			{
				_tail = deletedElement->prev;
				_tail->next = NULL;
			}
		}
		//середина списка
		if (deletedElement->next != NULL && deletedElement->prev != NULL)
		{
			deletedElement->next->prev = deletedElement->prev;
			deletedElement->prev->next = deletedElement->next;
		}
		delete deletedElement;
	};

	void ShowList() //TODO: Просто Show. Не надо добавлять название класса в имя методов а то вызов превращается в list.ShowList - тавтология
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

//TODO: если оператор перегружается для класса Person, то этот код должен быть в классе Person, а не в списке
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