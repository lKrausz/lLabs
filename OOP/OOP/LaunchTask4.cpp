#include <iostream>
#include "Labs.h"
#include "LaunchTask4Functions.h"
#include "Stack.h"


using namespace std;

//Μενώ
int Menu4(List* list)
{
	int key;
	int index;
	Person person;

	do
	{
		while (true)
		{
			cout << "\t Choose next step:" << endl << endl
				<< "1. Add new person;" << endl
				<< "2. Insert random person;" << endl
				<< "3. Insert list;" << endl
				<< "4. Remove person;" << endl
				<< "5. Stack;" << endl
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
		cin.ignore();
		system("cls");
		switch (key)
		{
		case 1:
		{
			person = ReadPerson();
			AddElement(list, person);
			ListShow(list);
			break;
		}

		case 2:
		{
			person = ReadRandomPerson();
			AddElement(list, person);
			ListShow(list);
			break;
		}

		case 3:
		{
			ListShow(list);
			cout << "Enter the index of element:\n";
			cin >> index;
			person = ReadPerson();
			InsertElement(list, person, index);
			ListShow(list);
			break;
		}

		case 4:
		{
			cout << "Enter the index of element:\n";
			cin >> index;
			DeleteElement(list, index);
			ListShow(list);
			break;
		}

		case 5:
		{
			int size = 0;
			cout << endl << "Enter stack size:" << endl;
			cin >> size;
			Stack* stack = InitStack(size);
			cout << "Stack:\n";
			int key1 = MenuStack(stack);
			cout << key1 << "\n";
			system("pause");
			Delete(stack);

		}

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


void LaunchTask4()
{
	List* list = new List();
	list->head = NULL;
	list->tail = NULL;

	int key = Menu4(list);
	cout << key << "\n";
	system("pause");
	delete list;
}
