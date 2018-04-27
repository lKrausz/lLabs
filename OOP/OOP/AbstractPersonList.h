#pragma once
#include "AbstractPerson.h"
#include <iostream>
#include <iomanip>
//TODO: ВСЮ РЕАЛИЗАЦИЮ ВЫНЕСТИ В CPP-ФАЙЛ
//TODO: Что за буква A в начале? Никаких сокращений! Слово Abstract не нужно
//TODO: Это должен быть вложенный в List класс под модификатором private - чтобы никто, кроме списка, не мог создавать его экземпляры
class APersonListItem
{
public:
	AbstractPerson * data; //TODO: Неправильное именование поля
	APersonListItem* next = NULL; //TODO: Неправильное именование поля
	APersonListItem* prev = NULL; //TODO: Неправильное именование поля
};

//TODO: Что за буква A в начале? Никаких сокращений! Слово Abstract не нужно
//TODO: Имя класса не должно отличаться от имени файла - иначе возникает путаница при просмотре проекта
class APersonList
{
	//TODO: модификатор private надо указывать явно - повышает читаемость
	APersonListItem* _head;
	APersonListItem* _tail;
	//количество элементов в списке //TODO: комментарии к коду пишутся с заглавной буквы
	int _count;

public:
	APersonList()
	{
		APersonListItem* _head;
		APersonListItem* _tail;
		int _count;
	}

	//TODO: Исправить реализацию. Сейчас деструктор не освобождает память. Он вообще ничего не удаляет - утечка памяти!
	~APersonList()
	{
		//TODO: реализацию можно сократить до одной строчки. Подумай
		if(_head != nullptr)
		{
			APersonListItem* temp = _head;
			while (temp != nullptr)
			{
				//TODO: под if нет рабочего кода. Тогда зачем if?
				if(temp->data != nullptr)
				{
					//delete temp->data;
				}
				temp = temp->next;
			}
		}
	}
	//добавить человека в список //TODO: комментарий оторван от функции пустой строкой. Исправить

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
		//TODO: зачем в цикле искать последний элемент, если в классе хранится указатель _tail?
		while (node->next != nullptr)
			node = node->next;

		node->next = newPerson;
		newPerson->prev = node;
		_tail = newPerson;
	};

	//найти человека по указанному индексу
	AbstractPerson* Find(int index)
	{
		//TODO: в таких случаях надо выкидывать исключение, а не возвращать пустой указатель
		if (index > _count) return nullptr;
		//TODO: добавить проверку на отрицательное значение

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
	}; //TODO: функции должны быть отделены одной пустой строкой
	//вернуть индекс человека, если он есть в списке
	int IndexOf(AbstractPerson* person)
	{
		APersonListItem* current = _head;
		int index = 0;
		//TODO: заменить на for. While ухудшают читаемость, и лучше их использовать реже
		while (current != nullptr && index <= _count)
		{
			//TODO: что за ёлочка? Избавиться от вложенности условий. Есть логические сложения и умножения условий
			if (current->data->GetName() == person->GetName())
				if (current->data->GetSurname() == person->GetName())
					if (current->data->GetAge() == person->GetAge())
						if (current->data->GetSex() == person->GetSex())
							return index;
			current = current->next;
			index++;
		}
		return -1;
	}; //TODO: функции должны быть отделены одной пустой строкой
	//удалить человека из списка
	void Remove(AbstractPerson* person)
	{
		int index = IndexOf(person);
		RemoveAt(index);
	}; //TODO: функции должны быть отделены одной пустой строкой
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
	}; //TODO: функции должны быть отделены одной пустой строкой
	//очистить список
	void NewClear()
	{ //TODO: убрать слово New из названия метода
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
	//получить количество элементов //TODO: комментарий оторван от функции

	int GetNewCount()
	{ //TODO: Убрать слово New из названия метода
		return _count;
	}; //TODO: пустая строка между функциями
	//вывести список на экран
	void ShowNewList(APersonList* list)
	{ //TODO: убрать слово New из названия функции
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