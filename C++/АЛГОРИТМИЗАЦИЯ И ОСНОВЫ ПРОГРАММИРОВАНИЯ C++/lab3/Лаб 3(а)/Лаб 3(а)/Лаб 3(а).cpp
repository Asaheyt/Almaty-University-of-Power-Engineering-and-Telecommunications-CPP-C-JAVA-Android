// Лаб 3(а).cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "iostream"
#include "cstdlib"
#include "cmath"
using namespace std;
int main()
{ 
	setlocale(LC_ALL, "Russian");
	float x, c=0;
	int n;
	cout << "Введите Х:" << endl;
	cin >> x;
	cout << "Введите N:" << endl;
	cin >> n;
	if (x<1 && x>-1)
		{
			for (int i = 1; i <= n; i++)
			{
				c += pow(-1, i+1)*pow(x, i) / i ;
			}
			cout <<log(1 + x);
			cout <<"Ответ:"<< c << endl;
		}
	else
		{
			cout << "x неудовлетворяет условию" << endl;
		}
	system("pause");
    return 0;
}
