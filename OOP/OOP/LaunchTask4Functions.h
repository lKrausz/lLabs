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

void AddElement(List* list, Person data);
void InsertElement(List* list, Person data, int index);
void DeleteElement(List* list, int index);
void ListShow(List* list);