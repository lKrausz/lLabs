#include "Child.h"
#include "Adult.h"


Child* GetRandomChild()
{
	string surname;
	string name;
	string school;
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
	const char *RandomSchool[] = { "Liceum #1", "State school #13", "State school #13", "State school #2", "0"};
	school = RandomSchool[rand() % 5];
	Child* person = new Child(name, surname, age, sex, school, GetRandomAdalt(), GetRandomAdalt());
	return person;
}
