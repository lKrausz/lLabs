#include <stdio.h>
#include <iostream>
#include "LaunchTask3Functions.h"

using namespace std;

char* CreateLength()
{
	int size = 100;
	char* str = new char[size];
	cout << "Enter your string: " << endl;
	cin.get(str, size);
	cout << "Your string: " << endl << str << endl;
	return str;
}

int GetLength(char* str)
{
	int lengthString = 0;
	while (str[lengthString] != '\0')
	{
		lengthString++;
	}
	return lengthString;
}

char* Concatenate(char* string1, char* string2)
{
	char* result = new char[20];
	int i;
	for ( i = 0; i < GetLength(string1); i++)
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

char* GetSubstring(char* string, int startIndex, int charCount)
{
	if (((GetLength(string) - startIndex) < charCount) || (startIndex < 0) || (charCount < 0))
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
			int str = ++i;
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
				return i-1;
			}
		}
	}
	return -1;
}

void TestSubstringFind(char* string, char* substring, char testSubstring[10])
{
	int index;
	substring = testSubstring;
	index = FindSubstring(string, substring);
	cout << "Start index: " << index << endl;
}

char* Uppercase(char* string)
{
	char* newString = new char[200];
	for (int i = 0; i < GetLength(string); i++)
	{
		newString[i] = string[i];
		newString[i + 1] = '\0';
	}

	for (int i = 0; i < GetLength(newString); i++)
	{
		if (newString[i] >= 97 && newString[i] <= 122)
		{
			newString[i] -= 32;
		}
	}
	return newString;
}

char* Lowercase(char* string)
{
	char* newString = new char[200];
	for (int i = 0; i < GetLength(string); i++)
	{
		newString[i] = string[i];
		newString[i + 1] = '\0';
	}

	for (int i = 0; i < GetLength(newString); i++)
	{
		if (newString[i] >= 65 && newString[i] <= 90)
		{
			newString[i] += 32;
		}
	}
	return newString;
}

//Получение обратной(отзеркаленной) строки
char* RevertString(char* string, int size)
{
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

//Разбиение строки source на части (путь, имя, расширение)
int GetSourcePart(char* source, char* partString, char symbol, const char partName[30], int size)
{
	int i = 0;
	while (source[size] != symbol)
	{
		partString[i] = source[size - 1];
		i++;
		size--;
		if (size == -1) return NULL;
	}
	if (symbol == '\\')
	{
		partString[i-1] = '\0';
	}
	else
	{
		partString[i] = '\0';
	}
	partString = RevertString(partString, GetLength(partString) - 1);
	cout << partName << partString << endl;
	return size;
}

void SplitFilename(char* source, char* path, char* name, char* extension)
{
	int size = GetLength(source);
	
	size = GetSourcePart(source, extension, '.', "Extension: ", size);
	size = GetSourcePart(source, name, '\\', "Name: ", size);
	source[size + 1] = '\0';
	path = source;
	cout << "Path: " << path << endl;
}

/*
char* ReplaceTabsOnSpaces(char* string)
{

}

char* ReplaceSpacesOnTabs(char* string)
{

} 
*/

Person ReadPerson()
{
	Person person;
	cout << "Surname: ";
	cin.getline(person.Surname, 40);
	cout << "Name: ";
	cin.getline(person.Name, 20);
	while (person.Sex[0] != 'M' && person.Sex[0] != 'F')
	{
		cout << "Sex ( Enter 'M' for male or 'F' for female): ";
		cin.getline(person.Sex, 2);
		if (person.Sex[0] != 'M' && person.Sex[0] != 'F')
		{
			cout << "Incorrect value. Try again." << endl;
		}
	}
	while (person.Age < 0)
	{
		cout << "Enter the age: ";
		cin >> person.Age;
		if (person.Age < 0)
		{
			cout << "Incorrect value. Try again." << endl;
		}
	}
	return person;
}

void PrintPerson(Person person)
{
	cout << "Surname: " << person.Surname << endl
	 << "Name: " << person.Name << endl
	 << "Sex: " << person.Sex << endl
	 << "Age: " << person.Age << endl;
}