#include <cstdlib>
#include "Labs.h"
#include <iostream>
#include <ctime>
//TODO: ������� �� ������� 1-4 ������������ ������.//done
//TODO: ������ ����� Lab 5 ������� ����� Person, List, Demo//done
//TODO: � ����� Person ��������� person, sex, adult, child//done
//TODO: � ����� List ��������� List � personList//done
//TODO: � ����� Demo ��������� ��� ����� LaunchTask � demo//done
//TODO: � ����� ������� ������ �������� ������ main//done
//TODO: �������� � ������������ ������ � ������ ��������� ���� ������ ���������!//done

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
				
				<< "1. Task 6;" << endl
				<< "2. Task 7;" << endl
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

			LaunchTask6();
			break;

		case 2:

			LaunchTask7();
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
	srand(time(NULL));
	//TODO: �� ���� ��������� �� ����������� �������� �� �������� ��������!
	int key = Menu();
	cout << key << endl;
	system("pause");
	return(0);
}
