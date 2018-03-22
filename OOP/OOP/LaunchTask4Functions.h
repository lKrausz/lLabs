#pragma once
#include "StructPersonFunctions.h"

struct Node
{
	Person data;
	Node* next = NULL;
	Node* prev = NULL;
};

struct List
{
	Node* head = NULL;
	Node* tail = NULL;
};

//������� ��������
void InsertElement(List* list, Person data, int index);
//�������� ��������
void DeleteElement(List* list, int index);
//����� ������ �� �����
void ShowList(List* list);
//������ ������
int GetListLength(List* list);
//��������� ������ person
Person* GetPersonAderess(List* list, int index);