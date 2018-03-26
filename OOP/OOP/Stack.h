#pragma once

// Не стандартная реализация - в задании ничего не говорилось, что стек должен быть фиксированного размера. Это чья-то готовая реализация или самостоятельно написанная?
struct Stack
{
	int* buffer;
	int bufferSize;
	int top;
};

//Меню функций работы со стеком
int MenuStack(Stack* stack);
//Инициализация стека
Stack* InitStack(int size);
//Добавление в стек
void Push(Stack* stack, int data);
//Извлечение из стека
int Pop(Stack* stack);
//Проверка на пустоту
bool IsEmpty(Stack* stack);
//Проверка на полноту
bool IsFull(Stack* stack);
//Удаление стека
void Delete(Stack* stack);
//Изменение размера стека (только увеличение)
void ReSize(Stack* stack, int size); 
//Вывод стека на экран
void StackShow(Stack* stack);