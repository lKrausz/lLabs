#include <cstdlib>
#include "Labs.h"
#include <iostream>


using namespace std;

//����
int Menu()
{
	int key;

	do
	{
		while (true)
		{
			cout << "\t Choose laboratory work:" << endl << endl
				<< "1. Task 1;" << endl
				<< "2. Task 2;" << endl
				<< "3. Task 3;" << endl
				<< "4. Task 4;" << endl
				<< "0. Exit." << endl;

			cin >> key;
			if (!cin)
			{
				system("cls");
				cout << "Incorrect value. Try again\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break; 
		}
		cin.ignore(1);
		system("cls");
		switch (key)
		{
		case 1:

			LaunchTask1();
			break;

		case 2:

			LaunchTask2();
			break;

		case 3:

			LaunchTask3();
			break;

		case 4:

			LaunchTask4();
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


int main()
{
	//TODO: �� ���� ��������� �� ����������� �������� �� �������� ��������!
	int key = Menu();
	cout << key << endl;
	system("pause");
	return(0);
}
