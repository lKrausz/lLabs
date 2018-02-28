#pragma once

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int globalVariable = 7;


//���������� �������, ��������� �� ����� �����.
void PrintHelloWorld()
{
	cout << "Hello, world!" << endl;
}


//�����������
double MakeCalculation(int value1, int value2, char operationKey)
{
	double z;	if (operationKey == '+') z = value1 + value2; else
		if (operationKey == '-') z = value1 - value2; else
			if (operationKey == '*') z = value1 * value2; else
				if (operationKey == '/') z = value1 / value2; else
					z = value1 % value2;
	return z;
}


//����� ������ ��� ������� ������ ������ ����������� ���������
void DisplayRootsValues(int check, double x1, double x2)
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
		cout << "Real roots:" << endl << "x1 = " << x1 << endl << "x2: " << x2 << endl << endl;
	}
	if (check == -1)
	{
		cout << "Complex roots:" << endl << "x1 = " << x1 << " + " << x2 << "i" << endl;
		cout << "x2 = " << x1 << " - " << x2 << "i" << endl << endl;
	}
}

//����� ����������� ���������
int GetRoots(int a, int b, int c, double* x1, double* x2)
{
	cout << "Quadratic equation: " << a << " * x^2 + " << b << " x + " << c << " = 0 " << endl;
	double discriminant;
	if (a != 0) 
	{
		discriminant = b * b - 4 * a*c;
		if (discriminant < 0) //����������� �����
		{
			*x1 = -b / (2 * a);
			*x2 = sqrt(-discriminant) / (2 * a);
			return -1;
		}  
		if (discriminant == 0) //���� �������������� ������
		{
			*x1 = -b / 2 / a;
			return 1;
		}
		//��� �������������� �����
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

//������ ����������� ��������� (� �������������� ������)
int AnotherGetRoots(int a, int b, int c, double& x1, double& x2)
{
	cout << "Quadratic equation: " << a << " * x^2 + " << b << " x + " << c << " = 0 " << endl;
	double discriminant;
	if (a != 0)
	{
		discriminant = b * b - 4 * a*c;
		if (discriminant < 0) //����������� �����
		{
			x1 = -b / (2 * a);
			x2 = sqrt(-discriminant) / (2 * a);
			return -1;
		}
		if (discriminant == 0) //���� �������������� ������
		{
			x1 = -b / 2 / a;
			return 1;
		}
		//��� �������������� �����
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


//���������� ����� ���� ������������� ���������� (���������� �������)
void SummNumbers(int value1, int value2)
{
	cout << "Summ of integers is " << value1 + value2 << endl;
}

//���������� ����� ���� ������������ ����������
void SummNumbers(double value1, double value2)
{
	cout << fixed << setprecision(2) << "Summ of doubles is " << value1 + value2 << endl;
}

//���������� ����� �������������� � ������������� ����������
void SummNumbers(int value1, double value2)
{
	cout << "Summ of integer and double is " << value1 + value2 << endl;
}


//������� �� ������������� ���������� ����������
//���������� ���������� + 2
void GlobalPlusTwo()
{
	globalVariable += 2;
}

//���������� ���������� * 3
void GlobalMultiplyThree()
{
	globalVariable *= 3;
}

//������������ ���������� ���������� �������� 1
void GlobalEqualsOne()
{
	globalVariable = 1;
}


//����������� ����� ����� � �������
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


//���� �� ���������� �������� ��������� �����. 
//3 �������, �����������, ������ ����� ��� ������ ���������� �������������
int Game()
{
	srand(time(NULL)); // ��� ������� ���������� ���������� �����
	cout << "---Game: Guess the Number---" << endl;
	int guessNumber = rand() % 10; // ��������� ������������ �����
	int enteredNumber = -1; // �������� ������������� �����
	int shots = 1; // ���������� �������
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
				if (guessNumber < enteredNumber) cout << "Number less then " << enteredNumber << endl;
				else cout << "Number more then " << enteredNumber << endl;
				cin >> enteredNumber;
			}
		}
		else
		{
			cout << "\nCorrect! You win in "<< shots << " shots!\n" << endl;
			break;
		}
		shots++;
	}
	return 0;
}


//���������� ���������
void BubbleSort(double *arrPointer, int n)
{
	double tmp = 0;
	for (int i = 0; i<n; i++) 
	{
		for (int j = (n - 1); j >= (i + 1); j--) 
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

//������� ����������
void QuickSort(double* array, int const n)
{
	int const lenD = n;
	int pivot = 0;
	int ind = lenD / 2;
	int i, j = 0, k = 0;
	if (lenD>1) {
		double* L = new double[lenD];
		double* R = new double[lenD];
		pivot = array[ind];
		for (i = 0; i<lenD; i++) {
			if (i != ind) {
				if (array[i]<pivot) {
					L[j] = array[i];
					j++;
				}
				else {
					R[k] = array[i];
					k++;
				}
			}
		}
		QuickSort(L, j);
		QuickSort(R, k);
		for (int cnt = 0; cnt<lenD; cnt++) {
			if (cnt<j) {
				array[cnt] = L[cnt];;
			}
			else if (cnt == j) {
				array[cnt] = pivot;
			}
			else {
				array[cnt] = R[cnt - (j + 1)];
			}
		}
	}
}

//���������� ��������
void SelectionSort(double array[], int lenD)
{
	int j = 0;
	int tmp = 0;
	for (int i = 0; i<lenD; i++) 
	{
		j = i;
		for (int k = i; k<lenD; k++) 
		{
			if (array[j]>array[k]) 
			{
				j = k;
			}
		}
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

//����� ������� �� �����
void ArrayShow(double array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}


//���������� ������
int** MatrixValues(int row, int col, int **matrix)
{
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}
	for (int i = 0; i< row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = rand() % 10;
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	return matrix;
}

//������������ ������ ������� �������
int** MultiplyMatrix(int n, int w, int m, int** aMatrix, int** bMatrix, int** result)
{
	int temp;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < w; col++) 
		{
			for (int inner = 0; inner < m; inner++) 
			{
				temp = aMatrix[row][inner] * bMatrix[inner][col];
				result[row][col] = result[row][col] + temp;
			}
		}
	}
	return result;
}