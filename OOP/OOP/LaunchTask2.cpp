#include <iostream>
#include "LaunchTask2Functions.h"
#include "Labs.h"
#include <ctime>

using namespace std;

extern int globalVariable;

//Прототип функции
int Menu2();

void LaunchTask2()
{
	int key = Menu2();
	cout << key << "\n";
}

//Меню
int Menu2()
{
	int key;
	double z = 0;


	int check;


	do
	{
		cout << "\t Choose next step:" << endl << endl
			<< "1. ""Hello, World!"";" << endl
			<< "2. Calculator;" << endl
			<< "3. Quadratic equation;" << endl
			<< "4. Quadratic equation (links);" << endl
			<< "5. Sum of numbers;" << endl
			<< "6. Global value;" << endl
			<< "7. Exponentiation;" << endl
			<< "8. 'Guess the Number' game;" << endl
			<< "9. Sorts;" << endl
			<< "10. Multiply Matrix;" << endl <<endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore();
		system("cls");
		switch (key)
		{
		case 1:
		{
			PrintHelloWorld();
			}
		break;

		case 2:
		{
			int value1 = 0;
			int value2 = 0;
			char operationKey;
			cout << "Enter mathematic operation (+, -, *, /, %): ";
			operationKey = getchar();
			while ((operationKey != '+') && (operationKey != '-') && (operationKey != '*') 
				&& (operationKey != '/') && (operationKey != '%'))
			{
				cout << "INCORRECT SYMBOL!!! Please, enter (+, -, *, /, %):" << endl;
				operationKey = getchar();
				fflush(stdin);
			}
			z = MakeCalculation(value1, value2, operationKey);
			cout << value1 << " " << operationKey << " " << value2 << " = " << z << ".\n";
			}
		break;

		case 3:
		{
			double x1 = 0;
			double x2 = 0;
			double* x1Pointer = &x1;
			double* x2Pointer = &x2;
			check = GetRoots(1, 3, 2, x1Pointer, x2Pointer);
			DisplayRootsValues(check, *x1Pointer, *x2Pointer);
			check = GetRoots(1, 4, 0, x1Pointer, x2Pointer);
			DisplayRootsValues(check, *x1Pointer, *x2Pointer);
			check = GetRoots(0, 1, 2, x1Pointer, x2Pointer);
			DisplayRootsValues(check, *x1Pointer, *x2Pointer);
			check = GetRoots(0, 0, 3, x1Pointer, x2Pointer);
			DisplayRootsValues(check, *x1Pointer, *x2Pointer);
			check = GetRoots(0, 1, 0, x1Pointer, x2Pointer);
			DisplayRootsValues(check, *x1Pointer, *x2Pointer);
			check = GetRoots(4, 1, 4, x1Pointer, x2Pointer);
			DisplayRootsValues(check, *x1Pointer, *x2Pointer);
		}
		break;

		case 4:
		{
			double x1 = 0;
			double x2 = 0;
			double& x1Reference = x1;
			double& x2Reference = x2;
			check = AnotherGetRoots(1, 3, 2, x1Reference, x2Reference);
			DisplayRootsValues(check, x1, x2);
			check = AnotherGetRoots(1, 4, 0, x1Reference, x2Reference);
			DisplayRootsValues(check, x1, x2);
			check = AnotherGetRoots(0, 1, 2, x1Reference, x2Reference);
			DisplayRootsValues(check, x1, x2);
			check = AnotherGetRoots(0, 0, 3, x1Reference, x2Reference);
			DisplayRootsValues(check, x1, x2);
			check = AnotherGetRoots(0, 1, 0, x1Reference, x2Reference);
			DisplayRootsValues(check, x1, x2);
			check = AnotherGetRoots(4, 1, 4, x1Reference, x2Reference);
			DisplayRootsValues(check, x1, x2);
		}
		break;

		case 5:
		{
			int a = 1;
			int b = 2;
			SummNumbers(a, b);
			double x = 3.0;
			double y = 4.0;
			SummNumbers(x, y);
			SummNumbers(a, y);
			float m = 5.0;
			float n = 6.0;
			SummNumbers(m, n);
			}
		break;

		case 6:
		{
			cout << "Global Variable: "<< globalVariable << endl;
			GlobalPlusTwo();
			cout << "Global Variable + 2: " << globalVariable << endl;
			GlobalMultiplyThree();
			cout << "Global Variable * 3: " << globalVariable << endl;
			GlobalEqualsOne();
			cout << "New global Variable: " << globalVariable << endl;
			globalVariable = 5;
			cout << "New global Variable: " << globalVariable << endl;
			}
		break;

		case 7:
		{
			int base;
			int power;
			cout << "Enter the base: " << endl;
			cin >> base;
			cout << "Enter the power: " << endl;
			cin >> power;
			cout << base << " in power " << power << " = " << GetPower(base, power) << endl;
			}
		break;

		case 8:
		{
			GuessRandomValueGame();
			}
		break;

		case 9:
		{
			int size;
			cout << "Enter the size of the array:" << endl;
			cin >> size;
			double* array = new double[size];
			srand(time(NULL));
			cout << "Your array: " << endl;
			for (int i = 0; i <  size; i++)
			{
				array[i] = rand() % 100;
				cout << array[i] << " ";
			}
			cout << "Enter sort number: " << endl 
			<< "1- Bubble Sort;" << endl 
			<< "2- Quick Sort;" << endl 
			<< "3- Selection Sort" << endl;
			int sortKey;
			cin >> sortKey;
			if (sortKey == 1)
			{
				cout << "BubbleSort results: " << endl;
				double *arrPointer = array;
				BubbleSort(arrPointer, size);
				ShowArray(array, size);
			}
			if (sortKey == 2)
			{
				cout << "QuickSort results: " << endl;
				QuickSort(array, size);
				ShowArray(array, size);
			}
			if (sortKey == 3)
			{
				cout << "SelectionSort results: " << endl;
				SelectionSort(array, size);
				ShowArray(array, size);
			}

			delete[] array;
		}
		break;

		case 10:
		{
			//Инициализация матрицы А
			int aRow; //Кол-во строк в матрице а 
			int aCol; //Кол-во столбцов в матрице а
			cout << "Enter the number of rows of matrix A" << endl;
			cin >> aRow;
			cout << "Enter the number of columns of matrix A" << endl;
			cin >> aCol;
			srand(time(NULL));
			int **aMatrix = new int*[aRow];
			cout << "The array A is" << endl;
			aMatrix = MatrixValues(aRow, aCol, aMatrix);
			ShowMatrix(aRow, aCol, aMatrix);

			//Инициализация матрицы В
			int bRow; //Кол-во строк в матрице b
			int bCol; //Кол-во столбцов в матрице b
			cout << "Enter the number of rows of matrix B" << endl;
			cin >> bRow;
			while (aCol != bRow)
			{
				cout << "Error. Enter correct value. " << endl
					<< "Rows of matrix A and columns of matrix B must be equals" << endl;
				cin >> bRow;
			}
			cout << "Enter the number of columns of matrix A" << endl;
			cin >> bCol;
			int **bMatrix = new int*[bRow];
			cout << "The array B is" << endl;
			bMatrix = MatrixValues(bRow, bCol, bMatrix);
			ShowMatrix(bRow, bCol, bMatrix);

			//Инициализация матрицы результата
			int** result = new int* [aRow];
			for (int i = 0; i < aRow; i++)
			{
				result[i] = new int[bCol];
			}
			for (int i = 0; i< aRow; i++)
			{
				for (int j = 0; j < bCol; j++)
				{
					result[i][j] = 0;
				}
				cout << endl;
			}
			//Умножение матриц и вывод резульатата на экран
			result = MultiplyMatrix(aRow, bCol, aCol, aMatrix, bMatrix, result);
			cout << "Results: " << endl;
			ShowMatrix(aRow, bCol, result);
			//Освобождение памяти
			for (int i = 0; i < aRow; i++)
			{
				delete[] aMatrix[i];
			}
			delete[] aMatrix;
			for (int i = 0; i < bRow; i++)
			{
				delete[] bMatrix[i];
			}
			delete[] bMatrix;
			for (int i = 0; i < aRow; i++)
			{
				delete[] result[i];
			}
			delete[] result;
			}
		break;

		case 0:
			cout << " Welcome back.\n";
			break;
		default:
			cout << " Mistake. Try again.\n";
			break;
		}
	} while (key != 0);

	return(key);

};
