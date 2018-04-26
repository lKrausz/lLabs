#include <iostream>
#include "Labs.h"
#include "AbstractPerson.h"
#include "AbstractPersonList.h"
#include "Child.h"
#include "Adult.h"


using namespace std;

//Μενώ
int Menu6()
{
	int key;
	APersonList* list = new APersonList();
	string surname;
	string name;
	int age = 0;
	int sex = 0;
	do
	{
		while (true)
		{
			cout << "\t Choose next step:" << endl << endl
				<< "1. Add Person;" << endl
				<< "2. Get Description;" << endl
				<< "3. Add Random Person;" << endl
				<< "4. Clear list;" << endl
				<< "5. Get Count;" << endl
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
				cout << "Enter surname: ";
				cin >> surname;
				cout << "Enter name: ";
				cin >> name;
				cout << "Enter sex: " << endl
					<< "0 for female " << endl
					<< "1 for male: " << endl;
				cin >> sex;
				cout << "Enter age: " << endl;
				cin >> age;
				if (age < 18)
				{
					string school;
					Child* child = new Child(name, surname, age, sex, school, nullptr, nullptr);
					cout << "Enter school. If child don't go to school press 0: " << endl;
					cin >> school;
					child->SetSchool(school);
					list->Add(child);
				}
				else
				{
					string workPlace;
					Adult* adult = new Adult(name, surname, age, sex, workPlace, nullptr);
					cout << "Enter workplace or 0 if you don't work" << endl;
					cin >> workPlace;
					adult->SetWorkPlace(workPlace);
					list->Add(adult);
				}

			list->ShowNewList(list);
				break;
			}

			case 2:
			{
				list->ShowNewList(list);
				int index;
				cout << "Enter index:" << endl;
				cin >> index;
				AbstractPerson* person = list->Find(index);
				if (person == nullptr)
				{
					cout << "Person not found." << endl;
				}
				else
				{
					cout << person->GetDescription();
				}
				break;
			}

			case 3:
			{
				int randomizer = rand() % 2;
				switch (randomizer)
				{
				case 1:
				{
					Adult* adult = GetRandomAdalt();
					list->Add(adult);
					break;
				}
				case 0:
				{
					Child* child = GetRandomChild();
					list->Add(child);
					break;
				}
				}
				list->ShowNewList(list);
				break;
			}

			case 4:
			{
				list->NewClear();
				cout << "List cleared" << endl;
				break;
			}

			case 5:
			{
				cout << "List size: " << list->GetNewCount() << endl;
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

	delete  list;
	return(key);

}


void LaunchTask6()
{
	int key = Menu6();
	cout << key << "\n";
}
