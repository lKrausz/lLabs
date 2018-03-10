#pragma once


//Реализация функции, выводящей на экран текст.
void PrintHelloWorld();


//Калькулятор
double MakeCalculation(int value1, int value2, char operationKey);


//Вывод данных для функций поиска корней квадратного уравнения
void DisplayRootsValues(int check, double x1, double x2);

//Корни квадратного уравнения
int GetRoots(int a, int b, int c, double* x1, double* x2);

//Корень квадратного уравнения (с использованием ссылок)
int AnotherGetRoots(int a, int b, int c, double& x1, double& x2);


//Рассчитать сумму двух целочисленных переменных (перегрузка функций)
void SummNumbers(int value1, int value2);

//Рассчитать сумму двух вещественных переменных
void SummNumbers(double value1, double value2);

//Рассчитать сумму целочисленного и вещественного переменных
void SummNumbers(int value1, double value2);


//Задание на использование глобальных переменных
//Глобальная переменная + 2
void GlobalPlusTwo();

//Глобальная переменная * 3
void GlobalMultiplyThree();

//Присваивание глобальной переменной значения 1
void GlobalEqualsOne();


//Рекурсивный поиск числа в степени
int GetPower(int base, int power);


//Игра на угадывание рандомно заданного числа. 
//3 попытки, указывается, больше число или меньше введенного пользователем
int GuessRandomValueGame();


//Сортировка пузырьком
void BubbleSort(double *arrPointer, int n);

//Быстрая сортировка
void QuickSort(double *array, int const n);

//Сортировка выборкой
void SelectionSort(double array[], int lenD);

//Вывод массива на экран
void ShowArray(double array[], int  size);


//Заполнение матриц
int** MatrixValues(int row, int col, int **matrix);

//Вывод матриц
void ShowMatrix(int row, int col, int **matrix);

//Перемножение матриц разного размера
int** MultiplyMatrix(int resultRow, int resultCol, int aCol, int **aMatrix, int **bMatrix, int **result);