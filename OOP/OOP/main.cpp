#include <cstdlib>
#include "Labs.h"
#include <iostream>

using namespace std;

//Μενώ
int Menu()
{
	char key;
	int element;
	int index;

	do
	{
		cout << "\t Choose laboratory work:" << endl << endl
			<< "1. Task 1;" << endl
			<< "0. Exit." << endl;

		cin >> key;
		cin.ignore(1);
		system("cls");
		switch (key)
		{
		case '1':

			LaunchTask1();
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


int main()
{
	int key = Menu();
	cout << key << endl;
	system("pause");
	return(0);
}
