#include "AbstractPerson.h"
#include <iostream>
#include <iomanip> // for satw 

using namespace std;
//TODO: реализация функции должна быть либо перегрузкой оператора << (раз ты её уже используешь), либо методом GetDescription() в классе Person
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

