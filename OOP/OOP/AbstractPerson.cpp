#include "AbstractPerson.h"
#include <iostream>
#include <iomanip> // for satw 

using namespace std;

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

