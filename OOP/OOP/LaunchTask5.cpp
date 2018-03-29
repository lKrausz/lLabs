#include <iostream>
#include "Labs.h"
#include "ClassPerson.h"
#include "PersonList.h"

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
				<< "1. Add Random Person;" << endl
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
			break;
		}

		case 2:
		{
			Person* person = person->GetRandomPerson();
			list.Add(person);
			list.ShowList(&list);
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
			PersonList list1;
			PersonList list2;
			Person* person = person->GetRandomPerson();
			list1.Add(person);
			person = person->GetRandomPerson();

			list1.Add(person);
			person = person->GetRandomPerson();
			list1.Add(person);
			cout << "list 1:" << endl;
			list1.ShowList(&list);

			person = person->GetRandomPerson();
			list2.Add(person);
			person = person->GetRandomPerson();
			list2.Add(person);
			person = person->GetRandomPerson();
			list2.Add(person);
			cout << "list 2:" << endl;
			list2.ShowList(&list);
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
