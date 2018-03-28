//TODO: Переименовать файл в соответствии с заголовочным файлом (после переименования заголовочного)
//done
#include <stdio.h>
#include <iostream>
#include "String.h"

using namespace std;

//TODO: Почему функция называется "Создать длину"? Длину или строку? Создать или прочесть с клавиатуры?
//done
char* ReadString()
{
	int size = 100;
	char* str = new char[size];
	cout << "Enter your string: " << endl;
	cin.get(str, size);
	return str;
}

//TODO: Продублировать комментарии из заголовочного файла - сейчас почему-то не показываются во всплывающих подсказках
int GetLength(char* str)
{
	int size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return size;
}

char* Concatenate(char* string1, char* string2)
{
	//Длина строки-результата - сумма длин строк + 1 для '\0'
	char* result = new char[GetLength(string1) + GetLength(string2) + 1];
	int i;
	for (i = 0; i < GetLength(string1); i++)
	{
		result[i] = string1[i];
	}
	for (int j = 0; j < GetLength(string2); j++)
	{
		result[i] = string2[j];
		i++;
	}
	result[i] = '\0';
	return result;
}

//TODO: Функция должна вернуть подстроку, а не вывести её на экран
char* GetSubstring(char* string, int startIndex, int charCount)
{
	//TODO: Длинное сложное условие под if - для таких лучше оставлять комментарий
	//done
	//Проверка на корректность входных данных: чтобы подстрока не выходила за пределы строки || 
	//чтобы индекс начала подстроки был больше нуля или равен ему ||
	//чтобы индекс конца строки был больше нуля
	if (((GetLength(string) - startIndex) < charCount) || (startIndex < 0) || (charCount <= 0))
	{
		cout << "Error. Incorrect value." << endl;
		return NULL;
	}
	cout << "Test results: " << endl;
	for (int i = 0; i < charCount; i++)
	{
		cout << string[startIndex];
		startIndex++;
	}
	cout << endl;
}

int FindSubstring(char* string, char* substring)
{
	if (GetLength(string) < GetLength(substring))
	{
		return -1;
	}
	for (int i = 0; i < GetLength(string); i++)
	{
		if (string[i] == substring[0])
		{
			bool subString = true;
			int str = i + 1;
			for (int subStr = 1; subStr < GetLength(substring); subStr++)
			{
				if (str > GetLength(string))
				{
					return -1;
				}
				if (string[str] != substring[subStr])
				{
					subString = false;
				}
				str++;
			}
			if (subString)
			{
				return i - 1;
			}
		}
	}
	return -1;
}

//TODO: На вход приходит массив из ровно 10 символов - так передавать строки неправильно, надо через указатель
void TestSubstringFind(char* string, char* substring, char testSubstring[10])
{
	int index;
	substring = testSubstring;
	index = FindSubstring(string, substring);
	cout << "Start index: " << index << endl;
}

char* Uppercase(char* string)
{
	//TODO: А если входная строка окажется больше 200 символов?
	//вам наверняка будет лень столько вводить
	char* newString = new char[200];
	//TODO: Зачем сначала копировать всю строку, если можно сразу записывать в новую строку приведенные к верхнему кейсу символы? Избавиться от первого цикла
	//done
	int i;
	for (i = 0; i < GetLength(string); i++)
	{
		//TODO: Магические числа 97, 122 и 32 - избавиться, так как читаемость кода плохая
		//done
		if (string[i] >= 'a' && string[i] <= 'z')
		{
			//ascii code
			newString[i] = string[i] - 32;
		}
		else
		{
			newString[i] = string[i];
		}
	}
	newString[i] = '\0';
	return newString;
}

char* Lowercase(char* string)
{
	//TODO: Аналогично предыдущей функции
	//done
	char* newString = new char[200];
	//TODO: Аналогично предыдущей функции
	//done
	int i;
	for (i = 0; i < GetLength(string); i++)
	{

		if (string[i] >= 'A' && string[i] <= 'Z')
		{
			//ascii code
			newString[i] = string[i] + 32;
		}
		else
		{
			newString[i] = string[i];
		}
	}
	newString[i] = '\0';
	return newString;
}

//TODO: Зачем передавать size, если его можно вычислить внутри функции - избавиться от лишнего параметра
//done
//TODO: В одних функциях length, в других - size. Одни и те же сущности надо именовать одинаково. Переименовать
//done
//Получение обратной(отзеркаленной) строки
char* RevertString(char* string)
{
	int size = GetLength(string) - 1;
	char* newString = new char[size];
	int i = 0;
	while (size != -1)
	{
		newString[i] = string[size];
		i++;
		size--;
	}
	newString[i] = '\0';
	return newString;
}

//TODO: Куча входных параметров - судя по названию должна возвращаться строка, а возвращается число - что за адская функция? Зачем она вообще нужна?
//Разбиение строки source на части (путь, имя, расширение)
int GetSourcePart(char* source, char* partString, char symbol, const char partName[30], int size)
{
	int i = 0;
	while (source[size] != symbol)
	{
		partString[i] = source[size - 1];
		i++;
		size--;
		if (size == -1)
		{
			partString[i - 1] = '\0';
			return NULL;
		}

	}
	if (symbol == '\\')
	{
		partString[i - 1] = '\0';
	}
	else
	{
		partString[i] = '\0';
	}
	partString = RevertString(partString);
	//TODO: Функции программной логики не должны ничего выводить на экран. Вывод на экран должен быть в интерфейсных функциях
	cout << partName << partString << endl;
	//TODO: Утечка памяти
	return size;
}

void SplitFilename(char* source, char* path, char* name, char* extension)
{
	int size = GetLength(source);
	//TODO: Для "нарезания" строк уже есть готовые функции GetSubstring, FindSubstring и др. Функция GetSourcePart не нужна
	size = GetSourcePart(source, extension, '.', "Extension: ", size);
	if (size == NULL)
	{
		size = GetLength(source);
		//TODO: Никакого вывода в функциях логики! Вывод должен быть только в интерфейсных функциях!
		cout << "Extension: NULL" << endl;
	}
	size = GetSourcePart(source, name, '\\', "Name: ", size);
	if (size == NULL)
	{
		size = GetLength(source);
		cout << "Name: " << RevertString(name) << endl;
		cout << "Path: NULL" << endl;
	}
	else
	{
		source[size + 1] = '\0';
		path = source;
		cout << "Path: " << path << endl;
	}
}

//TODO: лишние пустые строки между функциями
//done
//TODO: Да, функция работает неверно. При выводе строк на экран монитора, слова должны начинаться с одних и тех же позиций, а вместо некоторых пробельных символов должны отображаться двоеточия
char* ReplaceTabsOnSpaces(char* string)
{
	char* newString = new char[GetLength(string)];
	int j = 0;

	//TODO: цикл по i, а увеличивается j - неправильно!
	for (int i = 0; i < GetLength(string); j++)
	{
		if (string[i] == '\t')
		{
			//TODO: Вместо следующего if-else должен быть 1 цикл
			if ((j + 1) % 4 != 0)
			{
				newString[j] = ':';
			}
			else
			{
				newString[j] = ':';
				i++;
			}
		}
		else
		{
			newString[j] = string[i];
			i++;
		}
	}
	newString[j++] = '\0';
	return newString;
}

//TODO: Да, функция работает неверно. При выводе строк на экран монитора, слова должны начинаться с одних и тех же позиций, а вместо некоторых двоеточий должны отображаться пробельные символы
char* ReplaceSpacesOnTabs(char* string)
{
	char* newString = new char[GetLength(string)];
	int j = 0;
	int SpacePointer = 0;
	bool isTabulation = false;

	for (int i = 0; i < GetLength(string); i++)
	{
		if (string[i] == ':')
		{
			SpacePointer = i;

			while (string[SpacePointer] == ':')
			{
				if ((SpacePointer + 1) % 4 == 0)
				{
					isTabulation = true;
					break;
				}
				SpacePointer++;
			}
			if (isTabulation)
			{
				i = SpacePointer;
				newString[j] = '\t';
				isTabulation = false;
				j++;
			}
			else
			{
				newString[j] = string[i];
				j++;
			}
		}
		else
		{
			newString[j] = string[i];
			j++;
		}
	}
	newString[j++] = '\0';
	return newString;
}

