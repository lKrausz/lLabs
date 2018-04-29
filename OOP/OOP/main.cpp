#include <cstdlib>
#include "Labs.h"
#include <iostream>
#include <ctime>
//TODO: Удалить из проекта 1-4 лабораторные работы.//done
//TODO: Вместо папок Lab 5 создать папки Person, List, Demo//done
//TODO: В папку Person перенести person, sex, adult, child//done
//TODO: В папку List перенести List и personList//done
//TODO: В папку Demo перенести все файлы LaunchTask и demo//done
//TODO: В корне проекта должен остаться только main//done
//TODO: Подпапки в заголовочных файлах и файлах исходного кода ДОЛЖНЫ СОВПАДАТЬ!//done

using namespace std;

//Меню
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
	//TODO: Во всей программе не реализована проверка на вводимые значения!
	int key = Menu();
	cout << key << endl;
	system("pause");
	return(0);
}
