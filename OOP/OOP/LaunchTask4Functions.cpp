#include <iostream>
#include <Windows.h>
#include "LaunchTask4Functions.h"

void ListShow(List* list)
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

// ���������� ���� � ��� 
void AddElement(List* list, Person data)
{
	//��������� ����������
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = nullptr;

	int i = 0;
	Node* node = list->head;

	if (list->head == nullptr)
	{
		list->head = newNode;
		list->tail = newNode;
		return;
	}

	while (node->next)
		node = node->next;

	node->next = newNode;
	newNode->prev = node;
	list->tail = newNode;
}
// ������� ���� ���
void InsertElement(List* list, Person data, int index)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	Node* node = list->head;
	int i = 0;
	while (i != index && node != NULL)
	{
		++i;
		node = node->next;
	}
	// n check
	Node* count = list->head;
	int n = 0;
	do
	{
		count = count->next;
		n++;
	} while (count != NULL);

	if (index > n)
	{
		throw "Mistake, Master! This index too big. Try again! \n";
		return;
	}

	Node* current = list->head;
	for (int i = 1; i < index && current->next != NULL; i++)
		current = current->next;
	if (index == 0)
	{
		//��������� ����� ������� �� ������ �����
		newNode->next = list->head;
		list->head->prev = newNode;
		list->head = newNode;
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

// �������� ���� �� ���

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

	//������ ������
	if (node->prev == NULL)
	{
		list->head = NULL;
		if (node->next != NULL)
		{
			list->head = node->next;
			list->head->prev = NULL;
		}

	}

	//����� ������
	if (node->next == NULL)
	{
		list->tail = NULL;
		if (node->prev != NULL)
		{
			list->tail = node->prev;
			list->tail->next = NULL;
		}
	}

	//�������� ������
	if (node->next != NULL && node->prev != NULL)
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}

	delete node;
}


