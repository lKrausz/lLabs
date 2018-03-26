//TODO: Переименовать файл согласно заголовочному (после преименования заголовочного)
//done
#include <iostream>
#include <Windows.h>
#include "List.h"
#include <iomanip>

//TODO: Продублировать комментарии из заголовочного файла
void ShowList(List* list)
{
	ListNode* current = list->head;
	if (list->head == nullptr)
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

//TODO: лишние пустые строки между функциями. Должна быть только одна
//done
int GetListLength(List* list)
{
	ListNode* count = list->head;
	//TODO: локальные переменные с маленькой буквы
	//done
	int listSize = 0;
	//TODO: Если использовать цикл while вместо do-while, можно избавиться от этого условия
	//done
	while (count != nullptr)
	{
		count = count->next;
		listSize++;
	} 
	return listSize;
}


void InsertElement(List* list, Person data, int index)
{
	if (index > GetListLength(list) || index < 0)
	{
		//TODO: Никакого вывода текста. Нужно выкидывать исключения и ловить их в точке вызова
		cout << "Error. Incorrect index." << endl;
		return;
	}

	ListNode* newNode = new ListNode();
	newNode->data = data;

	ListNode* current = list->head;
	int i = 0;
	if (list->head == nullptr)
	{
		list->head = newNode;
		list->tail = newNode;
		return;
	}

	for (int i = 1; i < index && current->next != nullptr; i++)
		current = current->next;
	if (index == 0)
	{
		//вставляем новый элемент на первое место
		newNode->next = list->head;
		list->head->prev = newNode;
		list->head = newNode;
	}
	else
	{
		//вставляем новый элемент на непервое место
		if (current->next != nullptr)
			current->next->prev = newNode;
		newNode->next = current->next;
		current->next = newNode;
		newNode->prev = current;
		current = newNode;
	}
}


void DeleteElement(List* list, int index)
{
	if (list->head == NULL)
		return;

	int i = 0;
	ListNode* node = list->head;
	//TODO: А если индекс больше количества элементов списка?
	//ничего. наверн, надо эксепшн
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
		list->head = NULL;
		if (node->next != NULL)
		{
			list->head = node->next;
			list->head->prev = NULL;
		}

	}

	//конец списка
	if (node->next == NULL)
	{
		list->tail = NULL;
		if (node->prev != NULL)
		{
			list->tail = node->prev;
			list->tail->next = NULL;
		}
	}

	//середина списка
	if (node->next != NULL && node->prev != NULL)
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}

	delete node;
}

//TODO: переименовать функцию (см. заголовочный файл)
//done
Person* GetPerson(List* list, int index)
{
	int count = 0;
	ListNode* node = new ListNode;
	node = list->head;
	while (count != index)
	{
		node = node->next;
		count++;
	}
	if (count > index) return NULL;
	return &node->data;
}

//TODO: Еще нужна функция Clear() - очистка всего списка
//done
void Clear(List* list)
{
	ListNode* node = list->head;
	if (node)
	{
		while (node->next)
		{
			node = node->next;
			delete node->prev;
		}
		delete node;

		list->head = NULL;
		list->tail = NULL;
	}
}