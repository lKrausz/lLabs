#include <stdio.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "LaunchTask2Functions.h"

using namespace std;

int globalVariable = 7;
//TODO: Внимательно прочитайте стандарт оформления кода RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: и приведите свой код в соответстие со стандартом
void PrintHelloWorld()
{
	cout << "Hello, world!" << endl;
}


double MakeCalculation(int value1, int value2, char operationKey)
{
	//TODO:Правильнее	использовать switch-case, а не if-else
	//done
	switch (operationKey)
	{
	case '+': return value1 + value2;
	case '-': return value1 - value2;
	case '*': return value1 * value2;
	case '/': return value1 / value2;
	case '%': return value1 % value2;
	}
}


void DisplayRootsValues(int check, double x1, double x2)
{//TODO:Правильнее использовать switch-case, а не if-else
//done
	switch (check)
	{
	case 0:
		{
		cout << "Have no roots" << endl << endl;
		}
		break;
	case 1:
		{
		cout << "Real roots: x1 = x2 = " << x1 << endl << endl;
		}
		break;
	case 2:
		{
		cout << "Real roots:" << endl << "x1 = " << x1 << endl << "x2: " << x2 << endl << endl;
		}
		break;
	case -1:
	{
		cout << "Complex roots:" << endl << "x1 = " << x1 << " + " << x2 << "i" << endl;
		cout << "x2 = " << x1 << " - " << x2 << "i" << endl << endl;
	}
		break;
	}	
}

void TestGetRootsResults(int a, int b, int c, double* x1, double* x2)
{
	int check = GetRoots(a, b, c, x1, x2);
	DisplayRootsValues(check, *x1, *x2);
}


void TestGetRootsResults(int a, int b, int c, double& x1, double& x2)
{
	int check = AnotherGetRoots(a, b, c, x1, x2);
	DisplayRootsValues(check, x1, x2);
}



int GetRoots(int a, int b, int c, double* x1, double* x2)
{
	cout << "Quadratic equation: " << a << " * x^2 + " << b << " x + " << c << " = 0 " << endl;
	if (a != 0)
	{
		double discriminant = b * b - 4 * a*c;
		//комплексные корни
		if (discriminant < 0) 
		{
			*x1 = -b / (2 * a);
			*x2 = sqrt(-discriminant) / (2 * a);
			return -1;
		}
		//один действительный корень
		if (discriminant == 0) 
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


int AnotherGetRoots(int a, int b, int c, double& x1, double& x2)
{
	cout << "Quadratic equation: " << a << " * x^2 + " << b << " x + " << c << " = 0 " << endl;
	if (a != 0)
	{
		double discriminant = b * b - 4 * a*c;
		//комплексные корни
		if (discriminant < 0) 
		{
			x1 = -b / (2 * a);
			x2 = sqrt(-discriminant) / (2 * a);
			return -1;
		}
		//один действительный корень
		if (discriminant == 0) 
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


void SummNumbers(int value1, int value2)
{
	cout << "Summ of integers is " << value1 + value2 << endl;
}

void SummNumbers(double value1, double value2)
{
	cout << fixed << setprecision(2) << "Summ of doubles is " << value1 + value2 << endl;
}

void SummNumbers(int value1, double value2)
{
	cout << "Summ of integer and double is " << value1 + value2 << endl;
}


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


int GuessRandomValueGame()
{
	//TODO: Не пишите комментарии к коду в завершении строки. Код должен читаться сверху вниз.
	//TODO: Без передвижения диагонального скрол-бара.
	//TODO: Правильнее будет располагать комментарии НАД комментируемой строкой.
	//done
	srand(time(NULL)); 
	cout << "---Game: Guess the Number---" << endl;
	// угадываемое число
	int guessNumber = rand() % 10;
	// вводимое пользователем число
	int enteredNumber = -1; 
	// количество попыток
	int shots = 1; 
	cout << "Enter number from 0 to 9: ";
	cin >> enteredNumber;

	while (shots <= 3)
	{
		if (guessNumber != enteredNumber)
		{
			if (shots == 3)
			{
				cout << "Wrong!!! You lose!" << endl;
			}
			else
			{
				cout << "Wrong!!! Try again!" << endl;
				//TODO: Для if-else всегда надо расставлять скобки!
				//done
				if (guessNumber < enteredNumber) 
				{
					cout << "Number less then " << enteredNumber << endl;
				}
				else 
				{
					cout << "Number more then " << enteredNumber << endl;
				}
				cin >> enteredNumber;
			}
		}
		else
		{
			cout << "\nCorrect! You win in " << shots << " shots!\n" << endl;
			break;
		}
		shots++;
	}
	return 0;

}


void BubbleSort(double *arrPointer, int size)
{
	double tmp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = (size - 1); j >= (i + 1); j--)
		{
			if (arrPointer[j]<arrPointer[j - 1])
			{
				tmp = arrPointer[j];
				arrPointer[j] = arrPointer[j - 1];
				arrPointer[j - 1] = tmp;
			}
		}
	}
}


void SelectionSort(double array[], int size)
{
	int j = 0;
	int tmp = 0;
	for (int i = 0; i < size; i++)
	{
		j = i;
		for (int k = i; k < size; k++)
		{
			if (array[j] > array[k])
			{
				j = k;
			}
		}
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

void ShowArray(double array[], int  size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

//TODO: Именование метода не корректное. Название метода должно быть отглагольным и говорить о действии.
//done
int** CreateMatrixValues(int row, int col, int **matrix)
{
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}
	for (int i = 0; i< row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = 1 + rand() % 9;
		}
		cout << endl;
	}
	return matrix;
}

void ShowMatrix(int row, int col, int **matrix)
{
	for (int i = 0; i< row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
}

int** MultiplyMatrix(int resultRow, int resultCol, int aCol, int **aMatrix, int **bMatrix, int **result)
{
	for (int row = 0; row < resultRow; row++) {
		for (int col = 0; col < resultCol; col++)
		{
			for (int inner = 0; inner < aCol; inner++)
			{
				const int temp = aMatrix[row][inner] * bMatrix[inner][col];
				result[row][col] = result[row][col] + temp;
			}
		}
	}
	return result;
}

void DeleteMatrix(int size, int **matrix)
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}