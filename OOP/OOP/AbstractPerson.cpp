#include "AbstractPerson.h"
#include <iostream>
#include <iomanip> // for satw 

using namespace std;
class IncorrectSexValue {};

AbstractPerson* ReadPerson(string surname, string name, int age, int sex)
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
}

void ShowPerson(AbstractPerson* person)
{
	cout << setw(20) << person->GetSurname()
		<< setw(15) << person->GetName();
	switch (person->GetSex())
	{
	case 0:
		cout << setw(8) << "female";
		break;
	case 1:
		cout << setw(8) << "male";
		break;
	}
	cout << setw(3) << person->GetAge() << endl;
}
