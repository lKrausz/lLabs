#pragma once

#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

int globalVariable = 7;


//Реализация функции, выводящей на экран текст.
void PrintHelloWorld()
{
	cout << "Hello, world!" << endl;
}


//Калькулятор
double MakeCalculation(int value1, int value2, char operationKey)
{
	double z;	if (operationKey == '+') z = value1 + value2; else
	if (operationKey == '-') z = value1 - value2; else
	if (operationKey == '*') z = value1 * value2; else
	if (operationKey == '/') z = value1 / value2; else
	if (operationKey == '%') z = value1 % value2;
	return z;
}


//Ввод данных для функций поиска корней квадратного уравнения
void DisplayRootsValues(int check, double* x1, double* x2)
{
	if (check == 0)
	{
		cout << "Have no roots" << endl << endl;
	}
	if (check == 1)
	{
		cout << "Real roots: x1 = x2: " << *x1 << endl << endl;
	}
	if (check == 2)
	{
		cout << "Real roots: "<< endl << "x1: " << *x1 << endl << "x2: " << *x2 << endl << endl;
	}
	if (check == -1)
	{
		cout << "Complex roots: "<< endl <<"x1 = " << *x1 << " + " << *x2 << "i" << endl;
		cout << "x2 = " << *x1 << " - " << *x2 << "i" << endl << endl;
	}
}


//Корни квадратного уравнения
int GetRoots(int a, int b, int c, double* x1, double* x2)
{
	cout << "Quadratic equation: " << a << " * x^2 + " << b << " x + " << c << " = 0 " << endl;
	double discriminant;
	if (a != 0) 
	{
		discriminant = b * b - 4 * a*c;
		if (discriminant < 0) //комплексные корни
		{
			*x1 = -b / (2 * a);
			*x2 = sqrt(-discriminant) / (2 * a);
			return -1;
		}  
		if (discriminant == 0) //один действительный корень
		{
			*x1 = -b / 2 / a;
			return 1;
		}
		//два действительных корня
		*x1 = (-b - sqrt(discriminant)) / 2 / a;
		*x2 = (-b + sqrt(discriminant)) / 2 / a;
		return 2;
		
	}
	if (b != 0 & a == 0) 
	{
		*x1 = -c / b;
		return 1;
	}
	return 0;
}


//Ввод данных для функций поиска корней квадратного 
//уравнения с использованием ссылок
void AnotherDisplayRootsValues(int check, double& x1, double& x2)
{
	if (check == 0)
	{
		cout << "Have no roots" << endl << endl;
	}
	if (check == 1)
	{
		cout << "Real roots: x1 = x2 = " << x1 << endl << endl;
	}
	if (check == 2)
	{
		cout << "Real roots:" << endl <<"x1 = " << x1 << endl <<"x2: " << x2 << endl << endl;
	}
	if (check == -1)
	{
		cout << "Complex roots:" << endl << "x1 = " << x1 << " + " << x2 << "i" << endl;
		cout << "x2 = " << x1 << " - " << x2 << "i" << endl << endl;
	}
}


//Корень квадратного уравнения (с использованием ссылок)
int AnotherGetRoots(int a, int b, int c, double& x1, double& x2)
{
	cout << "Quadratic equation: " << a << " * x^2 + " << b << " x + " << c << " = 0 " << endl;
	double discriminant;
	if (a != 0)
	{
		discriminant = b * b - 4 * a*c;
		if (discriminant < 0) //комплексные корни
		{
			x1 = -b / (2 * a);
			x2 = sqrt(-discriminant) / (2 * a);
			return -1;
		}
		if (discriminant == 0) //один действительный корень
		{
			x1 = -b / 2 / a;
			return 1;
		}
		//два действительных корня
		x1 = (-b - sqrt(discriminant)) / 2 / a;
		x2 = (-b + sqrt(discriminant)) / 2 / a;
		return 2;

	}
	if (b != 0 & a == 0)
	{
		x1 = -c / b;
		return 1;
	}
	return 0;
}


//Рассчитать сумму двух целочисленных переменных (перегрузка функций)
void SummNumbers(int value1, int value2)
{
	printf("Summ of integer is %d\n", value1 + value2);
}


//Рассчитать сумму двух целочисленных переменных
void SummNumbers(double value1, double value2)
{
	printf("Summ of double is %f\n", value1 + value2);
}


//Рассчитать сумму двух целочисленных переменных
void SummNumbers(int value1, double value2)
{
	printf("Summ of integer and double is %f\n", value1 + value2);
}


//Задание на использование глобальных переменных
void GlobalPlusTwo()
{
	globalVariable += 2;
}
void GlobalMultiplyThree()
{
	globalVariable *= 3;
}
void GlobalEqualsOne()
{
	globalVariable = 1;
}

//Рекурсивный поиск числа в степени
int GetPower(int base, int power)
{
	if (power == 1)
	{
		return base;
	}
	else
	{
		return base * GetPower(base, power - 1);
	}
}

//Игра на угадывание рандомно заданного числа. 
//Изменить: 5 попыток, указывать, больше число или меньше введенного пользователем
int Game()
{
	srand(time(NULL)); // для задания случайного начального числа
	printf("\n---Game: Guess the Number---\n");
	int guessNumber = rand() % 10; // генерация угадываемого числа
	int enteredNumber = -1; // вводимое пользователем число
	int shots = 0; // количество попыток
	printf("\nEnter number from 0 to 9: ");
	scanf_s("%d", &enteredNumber);
	while (guessNumber != enteredNumber)
	{
		shots++;
		printf("\nWrong!!! Try again!\nEnter number from 0 to 9: ");
		scanf_s("%d", &enteredNumber);
	}
	printf("\nCorrect! You win in %d shots!\n", shots);
	return 0;
}
