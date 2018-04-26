#include "Adult.h"
#include <iostream>


Adult* GetRandomAdalt()
{
	string surname;
	string name;
	string workPlace;
	enum Sex sex;
	int age = 1 + rand() % 100;
	int initSex = rand() % 2;
	switch (initSex)
	{
	case 1:
	{
		sex = male;
		const char *maleSurname[] = { "Walter", "Krause", "Zimmer", "Regenherz", "Von-Webber" };
		surname = maleSurname[rand() % 5];
		const char *maleName[] = { "Johann", "Walter", "Ludwig", "Karl", "Ulrich" };
		name = maleName[rand() % 5];
		break;
	}
	case 0:
	{
		sex = female;
		const char *femaleSurname[] = { "Marinelli", "Alfieri", "Bellini", "Ferrario", "Cortese" };
		surname = femaleSurname[rand() % 5];
		const char *femaleName[] = { "Annabella", "Ottavia", "Laura", "Alessia", "Chiara" };
		name = femaleName[rand() % 5];
		break;
	}
	}
	const char *RandomWorkPlace[] = { "Google", "0", "Microsoft", "Facebook", "Valve" };
	workPlace = RandomWorkPlace[rand() % 5];
	Adult* person = new Adult(name, surname, age, sex, workPlace, nullptr);
	return person;
}