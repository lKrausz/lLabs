#include <iostream>
#include "Labs.h"
#include "ClassPerson.h"
#include "PersonList.h"
#include <conio.h> // for _getch in case 8.

using namespace std;

//Меню
int Menu5()
{
	int key;
	PersonList list;
	do
	{
		while (true)
		{
			cout << "\t Choose next step:" << endl << endl
				<< "1. Add Person;" << endl
				<< "2. Add Random Person;" << endl
				<< "3. Find Person with Index;" << endl
				<< "4. Get Person Index;" << endl
				<< "5. Remove Person;" << endl
				<< "6. Clear list;" << endl
				<< "7. Get Count;" << endl
				<< "8. Demonstration of the program;" << endl
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
			Person* person = ReadPerson();
			list.Add(person);
			list.ShowList(&list);
			delete person;
			break;
		}

		case 2:
		{
			Person *person = GetRandomPerson();
			list.Add(person);
			list.ShowList(&list);
			//remove
			delete person;
			break;
		}

		case 3:
		{
			int index;
			cout << "Enter index:" << endl;
			cin >> index;
			Person* person = list.Find(index);
				if (person == nullptr)
				{
					cout << "Person not found." << endl;
				}
				else
				{
					ShowPerson(person);
				}
			delete person;
			break;
		}

		case 4:
		{
			Person* person = ReadPerson();
			int index = list.IndexOf(person);
			if (index == -1)
			{
				cout << "Person not found." << endl;
			}
			else
			{
				cout << "Index: " << index << endl;
			}
			delete person;
			break;
		}

		case 5:
		{
			list.ShowList(&list);
			int index;
			cout << "Enter index:" << endl;
			cin >> index;
			Person* person = list.Find(index);
			if (person == nullptr)
			{
				cout << "Person not found." << endl;
			}
			else
			{
				list.RemoveAt(index);
				list.ShowList(&list);
			}
			delete person;
			break;
		}

		case 6:
		{
			list.Clear();
			cout << "List cleared" << endl;
			break;
		}

		case 7:
		{
			cout << "List size: " << list.GetCount() << endl;
			break;
		}

		case 8:
		{
			cout << "First step. Add 2 lists." << endl << endl;
			PersonList list1;
			PersonList list2;
			Person *person = GetRandomPerson();
			list1.Add(person);
			person = GetRandomPerson();
			list1.Add(person);
			person = GetRandomPerson();
			list1.Add(person);
			cout << "---list 1---" << endl;
			list1.ShowList(&list);

			person = GetRandomPerson();
			list2.Add(person);
			person = GetRandomPerson();
			list2.Add(person);
			person = GetRandomPerson();
			list2.Add(person);
			cout << "---list 2---" << endl;
			list2.ShowList(&list);

			cout << "Press any key" << endl << endl;
			key = _getch();
			cout << "Second step: copy person 2(list1) to list2 end" << endl << endl;
			person = list1.Find(2);
			list2.Add(person);
			cout << "---list 1---" << endl;
			list1.ShowList(&list);
			cout << "---list 2---" << endl;
			list2.ShowList(&list);

			cout << "Press any key" << endl << endl;
			key = _getch();
			cout << "Third step: delete person 2 from list1" << endl << endl;
			list1.RemoveAt(2);
			cout << "---list 1---" << endl;
			list1.ShowList(&list);
			cout << "---list 2---" << endl;
			list2.ShowList(&list);

			cout << "Press any key" << endl << endl;
			key = _getch();
			cout << "Last step: Clear list2" << endl << endl;
			list2.Clear();
			cout << "---list 1---" << endl;
			list1.ShowList(&list);
			cout << "---list 2---" << endl;
			list2.ShowList(&list);
			delete person;
			break;
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


void LaunchTask5()
{
	int key = Menu5();
	cout << key << "\n";
}
