#pragma once
#include <iostream>


using namespace std;

//����� �� ����� ��������� �Hello, World!�.
void Hi()
{
	cout << "Hello, world!" << endl;
}
 // ���������� � ������������� ������������� ����������. 
 //����� �� �������� � ����� �� �����.
void Summ()
{
	int a = 5;
	int b = 3;
	cout << "Variable a equals " << a << endl;
	cout << "Variable a equals " << b << endl;
	cout << "a + b = " << a + b << endl;
}
// ����� �� ����� ���������� ������� ���� ������������� ���������� 
//�� ���������� 5 � 3 � ���� ������������ ���������� �� ���������� 5.0 � 3.0.
void Division()
{
	int a = 5;
	int b = 3;
	float x = 5.0;
	float y = 3.0;
	cout << "Float variables division: " << a / b << endl;
	cout << "Integer variables division: " << x / y << endl;
}

// ������ ���� ������������� ���������� � ���������� � ����� �� ����� �� �����.
void Summ2()
{
	int a;
	int b;
	cout << " Enter first and second integer value" << endl;
	cin >> a >> b;
	cout << "a + b = " << a + b << endl;
}

// ������������ ������ ���������, �������� ������������� � ������ ������. 
//����� �� ����� ������, ��������� � ��������� � ��������, ������� �������� �� ������� ������.
void Pointer()
{
	int value;
	int* pointer;
	int &reference = value;
	int anotherValue;
	value = 5;

	pointer = &value;
	anotherValue = *pointer; // �������� �������������	

	cout << "Value, stored in pointer: " << anotherValue << endl;
	cout << "Address in pointer: " << pointer << endl;
	cout << "Value in pointer: " << *pointer << endl;
	cout << "Reference: " << reference << endl;
}

// ����������� ��������/���������� �����. 
void EvenOdd()
{
	int a;
	cout << "Enter value for check on even/odd: " << endl;
	cin >> a;
	if (a % 2 == 0)
	{
		cout << "Value is even!" << endl;
	}
	else
	{
		cout << "Value is odd!" << endl;
	}
}

// ����������� ��������� ���������� ����� 5 ��� 2. 
void Multiples()
{
	int a;
	cout << "Enter value: " << endl;
	cin >> a;
	if (a % 5 == 0)
	{
		cout << "Value multiples 5!" << endl;
	}
	if (a % 2 == 0)
	{
		cout << "Value multiples 2!" << endl;
	}
	if ((a % 5 == 0) & (a % 5 == 0))
	{
		cout << "Value multiples 5 and 2!" << endl;
	}
	else
	{
		cout << "Value doesn`t multiply 5 or 2!" << endl;
	}
}

//���� � ����-��������.
void PredCondition()
{
	int a = 0;
	while (a < 5)
	{
		cout << "Value is now: " << a << endl;
		a++;
	}

}

//���� � ����-��������.
void PostCondition()
{
	int a = 0;
	do
	{
		cout << "Value is now: " << a << endl;
		a++;
	} while (a < 5);
}

//������������ ����.
void Iteration()
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		cout << "Iteration: " << i << endl;
	}
	for (int i = 0; i < a; i++)
	{
		a--;
		cout << "Iteration value is  " << i << "  " << a << endl;
	}
}

//�������� break.
void Break()
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		a--;
		if (i >= a)
		{
			cout << "I is more or equal A! Break of cycle" << endl;
			break;
		}
	}
	cout << "A is " << a << endl;

}

//����� � ������� �������������� �����.
void Float()
{
	int a = 5;
	int b = 3;
	float z;

	z = a;
	cout << "Value of z is " << z << endl;

	//a = z;

	a = (int)z;
	cout << "Value of a is " << a << endl;

	z = a / b;
	cout << "Value of z is " << z << endl;

	z = ((float)a) / b;
	cout << "Value of z is " << z << endl;
}