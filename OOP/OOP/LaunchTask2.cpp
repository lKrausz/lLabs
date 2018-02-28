#include <iostream>
#include "LaunchTask2Functions.h"
#include "Labs.h"

using namespace std;

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
			PrintHelloWorld();
			break;

		case 2:
			{
			int value1 = 0;
			int value2 = 0;
			char operationKey;
			cout << "Enter mathematic operation (+, -, *, /, %): ";
			operationKey = getchar();
			while ((operationKey != '+') && (operationKey != '-') && (operationKey != '*') && (operationKey != '/') && (operationKey != '%'))
			{
				cout << "INCORRECT SYMBOL!!! Please, enter (+, -, *, /, %):" << endl;
				operationKey = getchar();
				fflush(stdin);
			}
			z = MakeCalculation(value1, value2, operationKey);
			cout << value1 << " " << operationKey << " " << value2 << " = " << z << ".\n";
			break;
			}

		case 3:
		{
			double x1 = 0;
			double x2 = 0;
			double x3 = 0;
			double x4 = 0;
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
			break;
		}

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
			break;
		}

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
			int n;
			int m;
			cout << "Enter the base: " << endl;
			cin >> n;
			cout << "Enter the power: " << endl;
			cin >> m;
			cout << n << " in power " << m << " = " << GetPower(n, m) << endl;
			}
			break;

		case 8:
			{
			Game();
			}
			break;

		case 9:
		{
			int n;
			cout << "Enter the size of the array:" << endl;
			cin >> n;
			double* array = new double[n];
			srand(time(NULL));
			cout << "Your array: " << endl;
			for (int i = 0; i < n; i++) 
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
				BubbleSort(arrPointer, n);
				ArrayShow(array, n);
			}
			if (sortKey == 2)
			{
				cout << "QuickSort results: " << endl;
				QuickSort(array, n);
				ArrayShow(array, n);
			}
			if (sortKey == 3)
			{
				cout << "SelectionSort results: " << endl;
				SelectionSort(array, n);
				ArrayShow(array, n);
			}

			delete[] array;
		}
			break;

		case 10:
			{
			//Инициализация матрицы А
			int n;
			int m;
			cout << "Enter the number of rows of matrix A" << endl;
			cin >> n;
			cout << "Enter the number of columns of matrix A" << endl;
			cin >> m;
			srand(time(NULL));
			int **aMatrix = new int*[n];
			cout << "The array A is" << endl;
			aMatrix = MatrixValues(n, m, aMatrix);
			//Инициализация матрицы В
			int w;
			cout << "The number of rows of matrix B equal the number of columns of matrix A: " << m << endl;
			cout << "Enter the number of columns of matrix B" << endl;
			cin >> w;
			int **bMatrix = new int*[m];
			cout << "The array B is" << endl;
			bMatrix = MatrixValues(m, w, bMatrix);
			//Инициализация матрицы результата
			int** result = new int*[n];
			for (int i = 0; i < n; i++)
			{
				result[i] = new int[w];
			}
			for (int i = 0; i< n; i++)
			{
				for (int j = 0; j < w; j++)
				{
					result[i][j] = 0;
				}
				cout << endl;
			}
			//Умножение матриц и вывод резульатата на экран
			result = MultiplyMatrix(n, w, m, aMatrix, bMatrix, result);
			cout << "Results: " << endl;
			for (int i = 0; i< n; i++)
			{
				for (int j = 0; j < w; j++)
				{
					cout << result[i][j] << ' ';
				}
				cout << endl;
			}
			//Освобождение памяти
			for (int i = 0; i < n; i++)
			{
				delete[] aMatrix[i];
			}
			delete[] aMatrix;
			for (int i = 0; i < z; i++)
			{
				delete[] bMatrix[i];
			}
			delete[] bMatrix;
			for (int i = 0; i < n; i++)
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
