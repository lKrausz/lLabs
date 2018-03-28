#pragma once
#include "Person.h"
//TODO: Файл имеет смысл переименовать в List - чтобы название отражало его содержание
//done
//TODO: Переименовать Node на ListNode - структура используется только для списков, это должно быть отражено в названии
//done
struct ListNode
{
	//TODO: Node должен хранить объект по указателю, а не по значению.
	// Иначе мы не можем поместить в список объекты, которые были созданы в динамической памяти
	Person data;
	ListNode* next = NULL;
	ListNode* prev = NULL;
};

struct List
{
	ListNode* head = NULL;
	ListNode* tail = NULL;
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
//TODO: Получение не адреса объекта, а самого объекта. Переименовать
//done
Person* GetPerson(List* list, int index);
//Отчистка всего списка
void Clear(List* list);