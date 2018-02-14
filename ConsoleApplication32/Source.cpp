#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>

using namespace std;

int q;
int rFunc(int count, int z, int fn);
int rFuncSum(int count, int z, int fn, int sum = 0);
int myPow(int n, int number, int *rNumber);

void Arr(int(*p)[2]);

void main()

{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int nz;

	do
	{
		cout << "Введите номер задания: ";
		cin >> nz;
		switch (nz)
		{
		case 1:
		{
			//16.	Даны первый член и разность арифметической прогрессии.Написать рекурсивную функцию для нахождения :
			//a.n - го члена прогрессии
			//b.суммы n первых членов прогрессии
			cout << "начало рекурсии: \n";
			rFunc(5, 3, 1);

			rFuncSum(5, 3, 1);

			cout << "сумма функции: \n" << rFuncSum(5, 3, 1) << endl;
		}break;

		case 2:
		{
			//14.	В некоторых языках программирования(например, в Паскале) не предусмотрена операция возведения в степень.
			//Написать рекурсивную функцию для расчета степени n вещественного числа a(n — натуральное число).
			int number = 2;
			int n = 3;
			int result = myPow(n, number, &number);
			myPow(n, number, &number);
			cout << result << endl;
		}break;

		case 3:
		{
			int mas[4][2] = { {2,4},{ 22,34 },{ 24,56 },{ 8,33 } };
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << mas[i][j] << "\t";
				}
				cout << endl;
			}

			//mas = mas [0][0]
			//[int][int]
			//mas - 

			printf("mas %p == &mas [0] = %p\n", mas, &mas[0]);
			printf("mas %p == &mas [0][0] = %p\n", mas, &mas[0][0]);

			//int *pri;
			//pri = *(mas + 1);

			mas + 1; //mas[0][1]


			//mas
			printf("\n mas [1][2] = %p / mas+3 = %p\n", &mas[1][2], mas + 2);

			//pri = &mas[0][0]		1-строка, 1 элемент
			//pri+1 = &mas[0][1]	1 - строка, 2 элемент
			//pri+2 = &mas[1][0]	1 - строка, 2 элемент
			cout << "\n-----------------------------------------------\n";

			printf("\n mas [0] = %d, *(mas) = %d\n\n", mas[0], *(mas));
			printf("\n mas [0][0] = %d, **mas = %d\n\n", mas[0][0], **mas);

		}break;

		case 4:
		{
		}break;
		}


		cout << "Хотите продолжить 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
		{
			cout << "ошибка" << endl;
		}
		}
	} while (nz > 0);


}


int rFunc(int count, int z, int fn)
{
	if (count <= 1)
		return fn;

	fn += z;//fn=fn+3
	count--;

	cout << count << " - count, fn = " << fn << endl;

	rFunc(count, z, fn);

	return fn;
}

int rFuncSum(int count, int z, int fn, int sum)
{
	sum += fn;
	if (count <= 1)
		return sum;

	count--;
	fn += z;
	cout << count << " - count, fn = " << fn << endl;

	sum = rFuncSum(count, z, fn, sum);

	return sum;
}

int myPow(int n, int number, int *rNumber)
{
	if (n <= 1)
		return number;

	n--;
	number *= *rNumber;

	//cout << n << ", число: " << number << endl;

	number = myPow(n, number, rNumber);
	return number;
}

void Arr(int(*p)[2]) // указывает на массив из 2-х значений типа int 
{
	/*int *ref;
	ref = &p[0][0];

	int f[2];
	int*pax[2];
	pax = &p;*/

	int(*pz)[2];
	pz = p;
	printf("pz %p,pz+1 = %p \n", pz, pz + 1);
}