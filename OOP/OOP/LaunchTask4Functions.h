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

//Вставка элемента
void InsertElement(List* list, Person data, int index);
//Удаление элемента
void DeleteElement(List* list, int index);
//Вывод списка на экран
void ShowList(List* list);
//Размер списка
int GetListLength(List* list);
//Получение адреса person
Person* GetPersonAderess(List* list, int index);