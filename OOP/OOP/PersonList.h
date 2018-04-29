#pragma once
#include "BasePerson.h"
//TODO: ��� ���������� ������� � CPP-����//done
//TODO: ��� �� ����� A � ������? ������� ����������! ����� Abstract �� �����//done
//TODO: PersonListItem ������ ���� ��������� � List ����� ��� ������������� private - ����� �����, ����� ������, �� ��� ��������� ��� ����������//done


//TODO: ��� �� ����� A � ������? ������� ����������! ����� Abstract �� �����//done
//TODO: ��� ������ �� ������ ���������� �� ����� ����� - ����� ��������� �������� ��� ��������� �������//done
class PersonList
{
private:
	class PersonListItem
	{

	public:
		BasePerson * Data; //TODO: ������������ ���������� ����//done?
		PersonListItem* Next = nullptr; //TODO: ������������ ���������� ����//done?
		PersonListItem* Prev = nullptr; //TODO: ������������ ���������� ����//done?
	};
	//TODO: ����������� private ���� ��������� ���� - �������� ����������//done
	PersonListItem* _head;
	PersonListItem* _tail;
	//���������� ��������� � ������ //TODO: ����������� � ���� ������� � ��������� �����//done
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