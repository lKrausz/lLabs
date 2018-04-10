#include "Adult.h"
#include <iostream>

Adult* ReadAdult(string name, string surname, int age, int sex)
{
	string workPlace;
	int marriedCheck;
	Adult* adult = new Adult(name, surname, age, sex);
	cout << "Enter workplace or 0 if you don't work" << endl;
	cin >> workPlace;
	adult->SetWorkPlace(workPlace);
	do
	{
		cout << "Do you married? 1 - Yes, 2 - No" << endl;
		cin >> marriedCheck;
		switch (marriedCheck)
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
			Adult* newAdult = new Adult(name, surname, age, sex);
			cout << "Enter workplace: " << endl;
			cin >> workPlace;
			newAdult->SetWorkPlace(workPlace);
			adult->MarriedOn = newAdult;
			newAdult->MarriedOn = adult;
		}
		case 2:
		{
			adult->MarriedOn = nullptr;
		}
		default:
		{
			cout << "Incorrect value. Try again." << endl;
		}
		}
	} while (marriedCheck < 1 || marriedCheck > 2);
	return adult;
}