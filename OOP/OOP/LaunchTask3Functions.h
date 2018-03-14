#pragma once


struct Person
{
	char Surname[40];
	char Name[20];
	char Sex[1];
	int Age;
};

//���� ������ 
Person ReadPerson();

//����� ������ �� �����
void PrintPerson(Person person);


//���� ������
char* CreateLength();


//������� ����� ������
int GetLength(char* str);


//���������� ���� ����� 
char* Concatenate(char* string1, char* string2);


//��������� ��������� ���������� ������� � ���������� �������
char* GetSubstring(char* string, int startIndex, int charCount);


//����� ��������� � ������
int FindSubstring(char* string, char* substring);

//���� ������� ������ ���������
void TestSubstringFind(char* string, char* substring, char testSubstring[10]);


//���������� ������ � �������� ��������
char* Uppercase(char* string);


//���������� ������ � ������� ��������
char* Lowercase(char* string);


//���������� ������ �� ����, ��� � ����������
void SplitFilename(char* source, char* path, char* name, char* extension);


//������ ��������� �� �������
//char* ReplaceTabsOnSpaces(char* string);

//������ �������� �� ���������
//char* ReplaceSpacesOnTabs(char* string);
