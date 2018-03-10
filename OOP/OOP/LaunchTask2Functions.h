#pragma once


//���������� �������, ��������� �� ����� �����.
void PrintHelloWorld();


//�����������
double MakeCalculation(int value1, int value2, char operationKey);


//����� ������ ��� ������� ������ ������ ����������� ���������
void DisplayRootsValues(int check, double x1, double x2);

//����� ����������� ���������
int GetRoots(int a, int b, int c, double* x1, double* x2);

//������ ����������� ��������� (� �������������� ������)
int AnotherGetRoots(int a, int b, int c, double& x1, double& x2);


//���������� ����� ���� ������������� ���������� (���������� �������)
void SummNumbers(int value1, int value2);

//���������� ����� ���� ������������ ����������
void SummNumbers(double value1, double value2);

//���������� ����� �������������� � ������������� ����������
void SummNumbers(int value1, double value2);


//������� �� ������������� ���������� ����������
//���������� ���������� + 2
void GlobalPlusTwo();

//���������� ���������� * 3
void GlobalMultiplyThree();

//������������ ���������� ���������� �������� 1
void GlobalEqualsOne();


//����������� ����� ����� � �������
int GetPower(int base, int power);


//���� �� ���������� �������� ��������� �����. 
//3 �������, �����������, ������ ����� ��� ������ ���������� �������������
int GuessRandomValueGame();


//���������� ���������
void BubbleSort(double *arrPointer, int n);

//������� ����������
void QuickSort(double *array, int const n);

//���������� ��������
void SelectionSort(double array[], int lenD);

//����� ������� �� �����
void ShowArray(double array[], int  size);


//���������� ������
int** MatrixValues(int row, int col, int **matrix);

//����� ������
void ShowMatrix(int row, int col, int **matrix);

//������������ ������ ������� �������
int** MultiplyMatrix(int resultRow, int resultCol, int aCol, int **aMatrix, int **bMatrix, int **result);