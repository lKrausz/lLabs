#include <iostream>
#include "LaunchTask1Functions.h"
#include "Labs.h"

using namespace std;

//Μενώ
int Menu1()
{
	int key;

	do
	{
		cout << "\t Choose next step:" << endl << endl
			<< "1. ""Hello, World!"";" << endl
			<< "2. a+b;" << endl
			<< "3. Division;" << endl
			<< "4. a+b(enter it using the keyboard);" << endl
			<< "5. Pointer;" << endl
			<< "6. Even or Odd;" << endl
			<< "7. Multiplicity of number (5 and 2);" << endl
			<< "8. PredCondition;" << endl
			<< "9. PostCondition;" << endl
			<< "10. Iteration;" << endl
			<< "11. Break;" << endl
			<< "12. Float <--> Int;" << endl << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore();
		system("cls");
		switch (key)
		{
		case 1:

			Hi();
			break;

		case 2:

			Summ();
			break;

		case 3:

			Division();
			break;

		case 4:

			Summ2();
			break;

		case 5:
			Pointer();
			break;

		case 6:

			EvenOdd();
			break;

		case 7:

			Multiples();
			break;

		case 8:

			PredCondition();
			break;

		case 9:

			PostCondition();
			break;

		case 10:

			Iteration();
			break;

		case 11:

			Break();
			break;

		case 12:

			Float();
			break;

		case 0:
			cout << " Welcome back." << endl;
			break;
		default:
			cout << " Mistake. Try again." << endl;
			break;
		}
	} while (key != 0);

	return(key);

};

void LaunchTask1()
{

	int key = Menu1();
	cout << key << endl;
}