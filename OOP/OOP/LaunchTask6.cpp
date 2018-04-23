#include <iostream>
#include "Labs.h"
#include "AbstractPerson.h"
#include "PersonList.h"
#include "Child.h"
#include "Adult.h"


using namespace std;

//Μενώ
int Menu6()
{
	int key;
	PersonList list;
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
					Child* child = new Child(name, surname, age, sex);
					cout << "Enter school. If child don't go to school press 0: " << endl;
					cin >> school;
					child->SetSchool(school);
					
				}
				else
				{
					Adult* adult = ReadAdult(name, surname, age, sex);;
				}

				break;
			}

			case 2:
			{

				break;
			}

			case 3:
			{

				break;
			}

			case 4:
			{

				break;
			}

			case 5:
			{

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

}


void LaunchTask6()
{
	int key = Menu6();
	cout << key << "\n";
}
