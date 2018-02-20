#include <iostream>
#include "LaunchTask1Functions.h"
#include "Labs.h"

using namespace std;

//Ìåíþ
int Menu1()
{
	char key;
	int element;
	int index;

	do
	{
		cout << "\t Choose next step:" << endl << endl
			<< "1. ""Hello, World!"";" << endl
			<< "2. a+b;" << endl
			<< "3. Division;" << endl
			<< "4. a+b(enter it using the keyboard);" << endl
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
		cin.ignore(1);
		system("cls");
		switch (key)
		{
		case '1':

			Hi();
			break;

		case '2':

			Summ();
			break;

		case '3':

			Division();
			break;

		case '4':

			Summ2();
			break;

		case '5':
			Pointer();
			break;

		case '6':

			EvenOdd();
			break;

		case '7':

			Multiples();
			break;

		case '8':

			PredÑondition();
			break;

		case '9':

			PostÑondition();
			break;

		case 'A':

			Iteration();
			break;

		case 'B':

			Break();
			break;

		case 'C':

			Float();
			break;

		case '0':
			cout << " Welcome back." << endl;
			break;
		default:
			cout << " Mistake. Try again." << endl;
			break;
		}
	} while (key != '0');

	int k = atoi(&key);
	return(k);

};

void LaunchTask1()
{
	int key = Menu1();
	cout << key << endl;
}