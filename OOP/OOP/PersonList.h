#pragma once
#include "BasePerson.h"

class PersonList
{
private:
	class PersonListItem
	{

	public:
		BasePerson * Data;
		PersonListItem* Next = nullptr;
		PersonListItem* Prev = nullptr;
	};

	PersonListItem* _head;
	PersonListItem* _tail;
	int _count;

public:
	PersonList();
	~PersonList();
	//�������� �������� � ������
	void Add(BasePerson* person);
	//����� �������� �� ���������� �������
	BasePerson* Find(int index);
	//������� ������ ��������, ���� �� ���� � ������
	int IndexOf(BasePerson* person);
	//������� �������� �� ������
	void Remove(BasePerson* person);
	//������� �������� �� ������ �� �������
	void RemoveAt(int index);
	//�������� ������
	void Clear();
	//�������� ���������� ��������� ������
	int GetCount();
	//������� ������ �� �����
	void Show(PersonList* list);
};