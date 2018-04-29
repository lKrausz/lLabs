#pragma once
#include "BasePerson.h"
//TODO: ВСЮ РЕАЛИЗАЦИЮ ВЫНЕСТИ В CPP-ФАЙЛ//done
//TODO: Что за буква A в начале? Никаких сокращений! Слово Abstract не нужно//done
//TODO: PersonListItem должен быть вложенный в List класс под модификатором private - чтобы никто, кроме списка, не мог создавать его экземпляры//done


//TODO: Что за буква A в начале? Никаких сокращений! Слово Abstract не нужно//done
//TODO: Имя класса не должно отличаться от имени файла - иначе возникает путаница при просмотре проекта//done
class PersonList
{
private:
	class PersonListItem
	{

	public:
		BasePerson * Data; //TODO: Неправильное именование поля//done?
		PersonListItem* Next = nullptr; //TODO: Неправильное именование поля//done?
		PersonListItem* Prev = nullptr; //TODO: Неправильное именование поля//done?
	};
	//TODO: модификатор private надо указывать явно - повышает читаемость//done
	PersonListItem* _head;
	PersonListItem* _tail;
	//Количество элементов в списке //TODO: комментарии к коду пишутся с заглавной буквы//done
	int _count;

public:
	PersonList();
	~PersonList();
	//Добавить человека в список
	void Add(BasePerson* person);
	//Найти человека по указанному индексу
	BasePerson* Find(int index);
	//Вернуть индекс человека, если он есть в списке
	int IndexOf(BasePerson* person);
	//Удалить человека из списка
	void Remove(BasePerson* person);
	//Удалить человека из списка по индексу
	void RemoveAt(int index);
	//Очистить список
	void Clear();
	//Получить количество элементов списка
	int GetCount();
	//Вывести список на экран
	void Show(PersonList* list);
};