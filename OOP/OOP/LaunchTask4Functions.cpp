//TODO: Переименовать файл согласно заголовочному (после преименования заголовочного)
#include <iostream>
#include <Windows.h>
#include "LaunchTask4Functions.h"
#include <iomanip>

//TODO: Продублировать комментарии из заголовочного файла
void ShowList(List* list)
{
	Node* current = list->head;
	if (list->head == nullptr)
		return;
	int i = 0;
	cout << "List:" << endl;
	cout << setw(10) << left 
		<< setw(3) << "#"
		 << setw(11) << "Surname"
		 << setw(10) << "Name"
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
int GetListLength(List* list)
{
	Node* count = list->head;
	//TODO: локальные переменные с маленькой буквы
	int ListSize = 0;
	//TODO: Если использовать цикл while вместо do-while, можно избавиться от этого условия
	if (list->head == nullptr) return 0;
	do
	{
		count = count->next;
		ListSize++;
	} while (count != nullptr);
	return ListSize;
}


void InsertElement(List* list, Person data, int index)
{
	if (index > GetListLength(list) || index < 0)
	{
		//TODO: Никакого вывода текста. Нужно выкидывать исключения и ловить их в точке вызова
		cout << "Error. Incorrect index." << endl;
		return;
	}

	Node* newNode = new Node();
	newNode->data = data;
	//TODO: не нужные строки, так как сейчас это делается автоматически при создании Node (см. реализацию Node)
	newNode->next = nullptr;
	newNode->prev = nullptr;

	Node* current = list->head;
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
	Node* node = list->head;
	//TODO: А если индекс больше количества элементов списка?
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
Person* GetPersonAderess(List* list, int index)
{
	int count = 0;
	Node* node = new Node;
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