#pragma once
//TODO: Файл переименовать в String - так название лучше отражает его содержимое
//done

//Ввод строки
char* ReadString();
//TODO: Слишком много пустых строк между функциями. Между двумя функциями должна быть ровно одна пустая строка.
//done

//Рассчет длины строки
int GetLength(char* str);

//Обединение двух строк 
char* Concatenate(char* string1, char* string2);

//Извлечние подстроки указанного размера с указанного индекса
char* GetSubstring(char* string, int startIndex, int charCount);

//Поиск подстроки в строке
int FindSubstring(char* string, char* substring);

//Тест функции поиска подстроки
void TestSubstringFind(char* string, char* substring, char* testSubstring);

//Приведение строки к верхнему регистру
char* Uppercase(char* string);

//Приведение строки к нижнему регистру
char* Lowercase(char* string);

//Разделение строки на путь, имя и расширение
void SplitFilename(char* source, char* path, char* name, char* extension);

//Замена табуляции на пробелы
char* ReplaceTabsOnSpaces(char* string);

//Замена пробелов на табуляцию
char* ReplaceSpacesOnTabs(char* string);
