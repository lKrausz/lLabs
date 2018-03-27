//TODO: ������������� ���� � ������������ � ������������ ������ (����� �������������� �������������)
#include <stdio.h>
#include <iostream>
#include "LaunchTask3Functions.h"

using namespace std;

//TODO: ������ ������� ���������� "������� �����"? ����� ��� ������? ������� ��� �������� � ����������?
char* CreateLength()
{
	int size = 100;
	char* str = new char[size];
	cout << "Enter your string: " << endl;
	cin.get(str, size);
	cout << "Your string: " << endl << str << endl;
	return str;
}

//TODO: �������������� ����������� �� ������������� ����� - ������ ������-�� �� ������������ �� ����������� ����������
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
	//����� ������-���������� - ����� ���� ����� + 1 ��� '\0'
	char* result = new char[GetLength(string1)+ GetLength(string2) + 1];
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

//TODO: ������� ������ ������� ���������, � �� ������� � �� �����
char* GetSubstring(char* string, int startIndex, int charCount)
{
	//TODO: ������� ������� ������� ��� if - ��� ����� ����� ��������� �����������
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

//TODO: �� ���� �������� ������ �� ����� 10 �������� - ��� ���������� ������ �����������, ���� ����� ���������
void TestSubstringFind(char* string, char* substring, char testSubstring[10])
{
	int index;
	substring = testSubstring;
	index = FindSubstring(string, substring);
	cout << "Start index: " << index << endl;
}

char* Uppercase(char* string)
{
	//TODO: � ���� ������� ������ �������� ������ 200 ��������?
	char* newString = new char[200];
	//TODO: ����� ������� ���������� ��� ������, ���� ����� ����� ���������� � ����� ������ ����������� � �������� ����� �������? ���������� �� ������� �����
	for (int i = 0; i < GetLength(string); i++)
	{
		newString[i] = string[i];
		newString[i + 1] = '\0';
	}

	for (int i = 0; i < GetLength(newString); i++)
	{
		//TODO: ���������� ����� 93, 122 � 32 - ����������, ��� ��� ���������� ���� ������
		if (newString[i] >= 97 && newString[i] <= 122)
		{
			newString[i] -= 32;
		}
	}
	return newString;
}

char* Lowercase(char* string)
{
	//TODO: ���������� ���������� �������
	char* newString = new char[200];
	//TODO: ���������� ���������� �������
	for (int i = 0; i < GetLength(string); i++)
	{
		newString[i] = string[i];
		newString[i + 1] = '\0';
	}

	for (int i = 0; i < GetLength(newString); i++)
	{
		//TODO: ���������� ���������� �������
		if (newString[i] >= 65 && newString[i] <= 90)
		{
			newString[i] += 32;
		}
	}
	return newString;
}

//TODO: ����� ���������� size, ���� ��� ����� ��������� ������ ������� - ���������� �� ������� ���������
//TODO: � ����� �������� length, � ������ - size. ���� � �� �� �������� ���� ��������� ���������. �������������
//��������� ��������(�������������) ������
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

//TODO: ���� ������� ���������� - ���� �� �������� ������ ������������ ������, � ������������ ����� - ��� �� ������ �������? ����� ��� ������ �����?
//��������� ������ source �� ����� (����, ���, ����������)
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
		partString[i-1] = '\0';
	}
	else
	{
		partString[i] = '\0';
	}
	partString = RevertString(partString, GetLength(partString) - 1);
	//TODO: ������� ����������� ������ �� ������ ������ �������� �� �����. ����� �� ����� ������ ���� � ������������ ��������
	cout << partName << partString << endl;
	//TODO: ������ ������
	return size;
}

void SplitFilename(char* source, char* path, char* name, char* extension)
{
	int size = GetLength(source);
	//TODO: ��� "���������" ����� ��� ���� ������� ������� GetSubstring, FindSubstring � ��. ������� GetSourcePart �� �����
	size = GetSourcePart(source, extension, '.', "Extension: ", size);
	if (size == NULL)
	{
		size = GetLength(source);
		//TODO: �������� ������ � �������� ������! ����� ������ ���� ������ � ������������ ��������!
		cout << "Extension: NULL" << endl;
	}
	size = GetSourcePart(source, name, '\\', "Name: ", size);
	if (size == NULL)
	{
		size = GetLength(source);
		cout << "Name: " << RevertString(name, GetLength(name) - 1) << endl;
		cout << "Path: NULL" << endl;
	}
	else
	{
		source[size + 1] = '\0';
		path = source;
		cout << "Path: " << path << endl;
	}
	
}

//TODO: ������ ������ ������ ����� ���������
//TODO: ��, ������� �������� �������. ��� ������ ����� �� ����� ��������, ����� ������ ���������� � ����� � ��� �� �������, � ������ ��������� ���������� �������� ������ ������������ ���������
char* ReplaceTabsOnSpaces(char* string)
{
		char* newString = new char[GetLength(string)];
		int j = 0;
		
		//TODO: ���� �� i, � ������������� j - �����������!
		for (int i = 0; i < GetLength(string); j++)
		{
			if (string[i] == '\t')
			{
				//TODO: ������ ���������� if-else ������ ���� 1 ����
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

//TODO: ��, ������� �������� �������. ��� ������ ����� �� ����� ��������, ����� ������ ���������� � ����� � ��� �� �������, � ������ ��������� ��������� ������ ������������ ���������� �������
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

