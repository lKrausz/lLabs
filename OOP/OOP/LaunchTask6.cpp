#include <iostream>
#include "Labs.h"
#include "BasePerson.h"
#include "PersonList.h"
#include "Child.h"
#include "Adult.h"


using namespace std;

//Меню
int Menu6()
{
	int key;
	PersonList* list = new PersonList();
	string surname;
	string name;
	int age = 0;
	int sexCheck = 0;
	Sex sex;
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
				cin >> sexCheck;
				switch (sexCheck)
				{
				case 1:
				{
					sex = male;
					break;
				}
				case 0:
				{
					sex = female;
					break;
				}
				//default: break;
				}
				cout << "Enter age: " << endl;
				cin >> age;
				if (age < 18)
				{
					string school;
					Child* child = new Child(name, surname, age, sex, school, nullptr, nullptr);
					cout << "Enter school or 'None', if child don't have to go to school: " << endl;
					cin >> school;
					child->SetSchool(school);
					list->Add(child);
				}
				else
				{
					string workPlace;
					Adult* adult = new Adult(name, surname, age, sex, workPlace, nullptr);
					cout << "Enter workplace or 'Unemployee' if you don't work" << endl;
					cin >> workPlace;
					adult->SetWorkPlace(workPlace);
					list->Add(adult);
				}

			list->Show(list);
				break;
			}

			case 2:
			{
				list->Show(list);
				int index;
				//TODO: в таких случаях надо выкидывать исключение, а не возвращать пустой указатель//done
				//TODO: добавить проверку на отрицательное значение//done
				try
				{
					cout << "Enter index:" << endl;
					cin >> index;
					if (index < 0 || index > list->GetCount()) throw index;
				}
				catch(int)
				{
					if (index < 0)
						cout << "Incorrect value." << endl;
					else 
						cout << "Index more then list size." << endl;
				}

				BasePerson* person = list->Find(index);
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
					Adult* adult = GetRandomAdult();
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
				list->Show(list);
				break;
			}

			case 4:
			{
				list->Clear();
				cout << "List cleared" << endl;
				break;
			}

			case 5:
			{
				cout << "List size: " << list->GetCount() << endl;
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
