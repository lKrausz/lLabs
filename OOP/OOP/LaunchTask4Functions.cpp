#include <iostream>
#include <Windows.h>
#include "LaunchTask4Functions.h"

void ShowList(List* list)
{
	Node* current = list->head;
	if (list->head == nullptr)
		return;

	cout << "List:" << endl;
	while (current != nullptr)
	{
		ShowPerson(current->data);
		current = current->next;
	} 
	cout << endl;
};


int GetListLength(List* list)
{
	Node* count = list->head;
	int ListSize = 0;
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
		cout << "Error. Incorrect index." << endl;
		return;
	}

	Node* newNode = new Node();
	newNode->data = data;
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
