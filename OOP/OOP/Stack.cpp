//TODO: Переименовать файл в соответствии с заголовочным
//done
#include <iostream>
#include "Stack.h"

using namespace std;

//TODO: До этого все интерфейсные функции выносились в отдельные файлы. Почему здесь всё в одном?
//потому что копипаста
int MenuStack(Stack* stack)
{
	int key;
	int data;
	bool check;
	cout << "Your stack:" << endl << endl;
	StackShow(stack);

	do
	{
		cout << "\t Choose next step:" << endl << endl
			<< "1. Push element. " << endl
			<< "2. Pop element. " << endl
			<< "3. Check Empty. " << endl
			<< "4. Check Full. " << endl
			<< "0. Exit. " << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
		case 1:
			cout << "Enter the element which you want to add:\n";
			cin >> data;
			check = IsFull(stack);
			if (check == false)
				Push(stack, data);
			else
			{
				ReSize(stack, stack->bufferSize * 2);
				Push(stack, data);
			}
			cout << "Your stack:" << endl << endl;
			StackShow(stack);

			break;
		case 2:
			cout << "Your stack:" << endl << endl;
			StackShow(stack);
			check = IsEmpty(stack);
			if (check == false)
			{
				int element = Pop(stack);
				cout << "Last element: " << element << endl;
			}
			else
			{
				cout << "Your stack is already empty." << endl;
			}
			cout << "Your stack:" << endl << endl;
			StackShow(stack);
			break;
		case 3:
			check = IsEmpty(stack);
			if (check == true)
				cout << "Your stack is empty" << endl;
			else
				cout << "Your stack isn't empty" << endl;
			break;
		case 4:
			check = IsFull(stack);
			if (check == true)
				cout << "Your stack is full" << endl;
			else
				cout << "Your stack isn't full." << endl;
			break;
		case 0:
			cout << " Welcome back." << endl;;
			break;
		default:
			cout << " Mistake. Try again." << endl;;
			break;
		}
	} while (key != 0);

	return(key);

};

Stack* InitStack (int size)
{
	Stack* stack = new Stack();
	//TODO: А почему стек в принципе ограничен по размеру bufferSize?
	//потому что копипаста
	stack->bufferSize = size;
	stack->buffer = new int[stack->bufferSize];
	stack->top = 0;
	return stack;
};

void Push(Stack* stack, int data)
{
	stack->buffer[stack->top] = data;
	stack->top++;
};
int Pop(Stack* stack)
{
	int index = stack->top - 1;
	stack->top--;
	return stack->buffer[index];
};
bool IsEmpty(Stack* stack)
{
	return (stack->top <= 0);
};
bool IsFull(Stack* stack)
{
	return (stack->top == stack->bufferSize);
}
void Delete(Stack* stack)
{
	delete[] stack->buffer;
	delete stack;
};
void ReSize (Stack* stack, int newSize)
{
	int* newBuffer = new int[newSize];;
	for (int i = 0; i < stack->bufferSize; i++)
	{
		newBuffer[i] = stack->buffer[i];
	}
	delete[] stack->buffer;
	stack->bufferSize = newSize;
	stack->buffer = newBuffer;
};
void StackShow(Stack* stack)
{
	for (int i = stack->top - 1; i >= 0 ; i--)
	{
		std::cout << (stack->buffer[i]) << endl;
	}
	std::cout << endl << endl;
}
