#include <iostream>
#include "Labs.h"
#include "LaunchTask3Functions.h"
#include "StructPersonFunctions.h"


using namespace std;

//ћеню
int Menu3()
{
	int key;
	do
	{
		while (true)
		{
			cout << "\t Choose next step:" << endl << endl
				<< "1. String length;" << endl
				<< "2. Concatenate two strings;" << endl
				<< "3. Get Substring;" << endl
				<< "4. Find Substring;" << endl
				<< "5. Convert to uppercase;" << endl
				<< "6. Convert to lowercase;" << endl
				<< "7. Divide the source into parts;" << endl
				<< "8. Replace tabs on spaces;" << endl
				<< "9. Replace spaces on tabs;" << endl
				<< "10. Person data;" << endl << endl
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
			char* str = CreateLength();
			int size = GetLength(str);
			cout << "String size: " << size << endl;
			delete[] str;
			break;
		}

		case 2:
		{
			
			char* str1 = new char[6]{ '1', '2', '3', '4', '5', '\0' };
			cout << "First string: " << str1 <<endl;
			char* str2 = new char[6]{ 'a', 'b', 'c', 'd', 'e', '\0' };
			cout << "Second string: " << str2 << endl;
			char* result = Concatenate(str1, str2);
			cout << "Your string: " << result << endl;
			delete[] str2;
			delete[] str1;
			delete[] result;
			break;
		}

		case 3:
		{
			char* str = new char[12]{ 'H', 'a', 'l', 'l', '0', ',', 'W', 'o', 'r', 'l', 'd', '\0' };
			GetSubstring(str, 2, 4);
			GetSubstring(str, -3, 3);
			GetSubstring(str, 2, -4);
			GetSubstring(str, 7, 8);
			delete[] str;
			break;
		}

		case 4:
		{
			
			char mainString[25] = "Lorem ipsum aset ametsum";
			char * string = mainString;
			char* subString = new char[100];
			char testSubstring1[10] = "ipsum a";
			TestSubstringFind(string, subString, testSubstring1);
			char testSubstring2[10] = "Arom";
			TestSubstringFind(string, subString, testSubstring2);
			char testSubstring3[10] = "sum";
			TestSubstringFind(string, subString, testSubstring3);
			delete[] subString;
			break;
		}

		case 5:
		{
			char* string = CreateLength();
			cout << "Uppercase string: " << Uppercase(string) << endl;
			delete[] string;
			//TODO: ”течка пам€ти
			break;
		}


		case 6:
		{
			char* string = CreateLength();
			cout << "Lowercase string: " << Lowercase(string) << endl;
			delete[] string;
			//TODO: ”течка пам€ти
			break;
		}

		case 7:
		{
			char* source = CreateLength();
			char* path = new char[20];
			char* name = new char[20];
			char* extension = new char[10];
			SplitFilename(source, path, name, extension);
			delete[] source;
			delete[] name;
			delete[] extension;
			break;
		}

		case 8:
		{
			char* string = (char*)"Cake\tis\ta lie!";
			// ƒобавил вывод исходной строки, иначе при работе программы нельз€ пон€ть, правильно ли она отработала
			cout << string << endl;
			cout << ReplaceTabsOnSpaces(string) << endl;
			char* string1 = (char*)"Cake\t\tis a lie!";
			// ƒобавил вывод исходной строки, иначе при работе программы нельз€ пон€ть, правильно ли она отработала
			cout << string1 << endl;
			cout << ReplaceTabsOnSpaces(string1) << endl;
			//TODO: утечка пам€ти
			break;
		}

		case 9:
		{
			char* string = (char*)"Cake::::is::a:lie!";
			// ƒобавил вывод исходной строки, иначе при работе программы нельз€ пон€ть, правильно ли она отработала
			cout << string << endl;
			cout << ReplaceSpacesOnTabs(string) << endl;
			char* string1 = (char*)"Cake::::is::::a:lie! ";
			// ƒобавил вывод исходной строки, иначе при работе программы нельз€ пон€ть, правильно ли она отработала
			cout << string1 << endl;
			cout << ReplaceSpacesOnTabs(string1) << endl;
			break;
			//TODO: ”течка пам€ти
		}

		case 10:
		{
			Person person = ReadPerson();
			ShowPerson(person);
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


void LaunchTask3()
{
	int key = Menu3();
	cout << key << "\n";
}
