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
	double x1;
	double x2;
	int value1 = 0;
	int value2 = 0;
	double z = 0;


	int check;


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
			{
			char operationKey;
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
			}

		case 3:
		{
			x1 = 0;
			x2 = 0;
			double* x1Pointer = &x1;
			double* x2Pointer = &x2;
			check = GetRoots(1, 3, 2, x1Pointer, x2Pointer);
			DisplayRootsValues(check, x1Pointer, x2Pointer);
			check = GetRoots(1, 4, 0, x1Pointer, x2Pointer);
			DisplayRootsValues(check, x1Pointer, x2Pointer);
			check = GetRoots(0, 1, 2, x1Pointer, x2Pointer);
			DisplayRootsValues(check, x1Pointer, x2Pointer);
			check = GetRoots(0, 0, 3, x1Pointer, x2Pointer);
			DisplayRootsValues(check, x1Pointer, x2Pointer);
			check = GetRoots(0, 1, 0, x1Pointer, x2Pointer);
			DisplayRootsValues(check, x1Pointer, x2Pointer);
			check = GetRoots(4, 1, 4, x1Pointer, x2Pointer);
			DisplayRootsValues(check, x1Pointer, x2Pointer);
			break;
		}

		case 4:
		{
			x1 = 0;
			x2 = 0;
			double& x1Reference = x1;
			double& x2Reference = x2;
			check = AnotherGetRoots(1, 3, 2, x1Reference, x2Reference);
			AnotherDisplayRootsValues(check, x1Reference, x2Reference);
			check = AnotherGetRoots(1, 4, 0, x1Reference, x2Reference);
			AnotherDisplayRootsValues(check, x1Reference, x2Reference);
			check = AnotherGetRoots(0, 1, 2, x1Reference, x2Reference);
			AnotherDisplayRootsValues(check, x1Reference, x2Reference);
			check = AnotherGetRoots(0, 0, 3, x1Reference, x2Reference);
			AnotherDisplayRootsValues(check, x1Reference, x2Reference);
			check = AnotherGetRoots(0, 1, 0, x1Reference, x2Reference);
			AnotherDisplayRootsValues(check, x1Reference, x2Reference);
			check = AnotherGetRoots(4, 1, 4, x1Reference, x2Reference);
			AnotherDisplayRootsValues(check, x1Reference, x2Reference);
			break;
		}

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
