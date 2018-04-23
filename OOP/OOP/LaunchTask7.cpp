#include <iostream>
#include "Labs.h"
#include "ClassPerson.h"
#include "PersonList.h"
#include "UniversalList.h"

using namespace std;

//Μενώ
int Menu7()
{
	int key;
	PersonList list;
	do
	{
		while (true)
		{
			cout << "\t Choose next step:" << endl << endl
				<< "1. Demonstrate on double" << endl
				<< "2. Demonstrate on *Person" << endl
				<< "3. Demonstrate on double[5]" << endl
				<< "4. Demonstrate on List<double>" << endl
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
			UniversalList<double> list;

			cout << "Add 5 elements" << endl;

			list.Add(3.1);
			list.Add(4.6);
			list.Add(-9.1);
			list.Add(0.17);
			list.Add(66.6);
			list.ShowList();

			cout << "Delete 3 element" << endl;
			list.RemoveAt(2);
			list.ShowList();

			cout << "Insert element into 4 place" << endl;
			list.Insert(50.0, 3);
			list.ShowList();
			system("pause");
			system("cls");
			break;
		}

		case 2:
		{
			UniversalList<Person*> list;

			cout << "Add 5 elements" << endl;

			list.Add(GetRandomPerson());
			list.Add(GetRandomPerson());
			list.Add(GetRandomPerson());
			list.Add(GetRandomPerson());
			list.Add(GetRandomPerson());
			list.ShowList();

			cout << "Delete 3 element" << endl;
			list.RemoveAt(2);
			list.ShowList();

			cout << "Insert element into 4 place" << endl;
			list.Insert(GetRandomPerson(), 3);
			list.ShowList();
			system("pause");
			system("cls");
			break;
		}

		case 3:
		{
			UniversalList<double*> list;

			double arr1[5] = { 12.55, -1.99, 0.19, 66.6, 20.17 };
			double arr2[5] = { 48.2, 14.3, -94.01, 36, 51.3 };
			double arr3[5] = { 18.35, 89.1, 3.048, -9.12, 5 };
			double arr4[5] = { 0, 0.95, 37.1, -8.196, -0.8 };
			double arr5[5] = { -94.01, 36, 51.3, 89.1, 3.048};
			double newArr[5] = { 0.19, 66.6, 20.17, 48.2, 14.3 };

			cout << "Add 5 elements" << endl;
			list.Add(arr1);
			list.Add(arr2);
			list.Add(arr3);
			list.Add(arr4);
			list.Add(arr5);
			list.ShowList();

			cout << "Delete 3 element" << endl;
			list.RemoveAt(2);
			list.ShowList();

			cout << "Insert element into 4 place" << endl;
			list.Insert(newArr, 3);
			list.ShowList();
			system("pause");
			system("cls");
			break;
		}

		case 4:
		{
			UniversalList<UniversalList<double>*> list;

			UniversalList<double> list1;
			list1.Add(12.55);
			list1.Add(-1.99);
			list1.Add(0.19);
			list1.Add(66.6);
			list1.Add(20.17);
			UniversalList<double> list2;
			list2.Add(48.2);
			list2.Add(7.9);
			list2.Add(49.02);
			list2.Add(-90.7);
			list2.Add(7.048);
			UniversalList<double> list3;
			list3.Add(5);
			list3.Add(5.98);
			list3.Add(9.0);
			list3.Add(34.58);
			list3.Add(-2.17);
			UniversalList<double> list4;
			list4.Add(66.6);
			list4.Add(-5.0);
			list4.Add(94.2);
			list4.Add(-4.7);
			list4.Add(1.4);
			UniversalList<double> list5;
			list5.Add(12.2);
			list5.Add(-1.8);
			list5.Add(51.2);
			list5.Add(4.88);
			list5.Add(-0.8);
			UniversalList<double> newList;
			newList.Add(2.9);
			newList.Add(9.8);
			newList.Add(-49.2);
			newList.Add(95.07);
			newList.Add(-234.6);

			cout << "Add 5 elements" << endl;
			list.Add(&list1);
			list.Add(&list2);
			list.Add(&list3);
			list.Add(&list4);
			list.Add(&list5);
			list.ShowList();

			cout << "Delete 3 element" << endl;
			list.RemoveAt(2);
			list.ShowList();

			cout << "Insert element into 4 place" << endl;
			list.Insert(&newList, 3);
			list.ShowList();
			system("pause");
			system("cls");
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


void LaunchTask7()
{
	int key = Menu7();
	cout << key << "\n";
}
