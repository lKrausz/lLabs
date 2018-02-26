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
	int a = 0;
	int b = 0;
	int c = 0;
	double x1;
	double x2;
	int value1 = 0;
	int value2 = 0;
	double z = 0;
	double* x1Pointer = &x1;
	double* x2Pointer = &x2;
	double& x1Reference = x1;
	double& x2Reference = x2;
	int check;
	char operationKey;

	do
	{
		cout << "\t Choose next step:" << endl << endl
			<< "1. ""Hello, World!"";" << endl
			<< "2. Calculator;" << endl
			<< "3. Quadratic equation;" << endl
			<< "4. Quadratic equation (2);" << endl
			<< "5. Pointer;" << endl
			<< "6. Even or Odd;" << endl
			<< "7. multiplicity of number (5 and 2);" << endl
			<< "8. PredCondition;" << endl
			<< "9. PostCondition;" << endl
			<< "A. Iteration;" << endl
			<< "B. Break;" << endl
			<< "C. Float <--> Int;" << endl
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
			cout << "Enter mathematic operation (+, -, *, /, %): ";
			operationKey = getchar();
			while ((operationKey != '+') && (operationKey != '-') && (operationKey != '*') && (operationKey != '/') && (operationKey != '%'))
			{
				printf("\nINCORRECT SYMBOL!!!\nPlease, enter (+, -, *, /, %):");
				operationKey = getchar();
				fflush(stdin);
			}
			z = MakeCalculation(value1, value2, operationKey);
			cout << value1 << " " << operationKey << " " << value2 << " = " << z << ".\n";
			break;

		case 3:
			cout << "Enter the coefficients: ax^2 + bx + c " << endl;
			cout << "Enter coefficient a: " << endl;
			cin >> a;
			cout << "Enter coefficient b: " << endl;
			cin >> b;
			cout << "Enter coefficient c: " << endl;
			cin >> c;
			x1 = 0;
			x2 = 0;
			check = GetRoots(a, b, c, x1Pointer, x2Pointer);
			if (check == 0)
			{
				cout << "Have no roots" << endl;
			}
			if (check == 1)
			{
				cout << "Real roots: x1 = x2: " << x1 << endl;
			}
			if (check == 2)
			{
				cout << "Real roots: x1: " << x1 << " x2: " << x2 << endl;
			}
			if (check == -1)
			{
				cout << "Complex roots: x1 = " << x1 << " + " << x2 << "i" << endl;
				cout << "x2 = " << x1 << "-" << x2 << "i" << endl;
			}
			break;

		case 4:
			cout << "Enter the coefficients: ax^2 + bx + c " << endl;
			cout << "Enter coefficient a: " << endl;
			cin >> a;
			cout << "Enter coefficient b: " << endl;
			cin >> b;
			cout << "Enter coefficient c: " << endl;
			cin >> c;
			x1 = 0;
			x2 = 0;
			check = AnotherGetRoots(a, b, c, x1Reference, x2Reference);
			if (check == 0)
			{
				cout << "Have no roots" << endl;
			}
			if (check == 1)
			{
				cout << "Real roots: x1 = x2: " << x1 << endl;
			}
			if (check == 2)
			{
				cout << "Real roots: x1: " << x1 << " x2: " << x2 << endl;
			}
			if (check == -1)
			{
				cout << "Complex roots: x1 = " << x1 << " + " << x2 << "i" << endl;
				cout << "x2 = " << x1 << "-" << x2 << "i" << endl;
			}
			break;

		case '5':

			break;

		case '6':

			break;

		case '7':

			break;

		case '8':

			break;

		case '9':

			break;

		case 'A':

			break;

		case 'B':

			break;

		case 'C':

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
