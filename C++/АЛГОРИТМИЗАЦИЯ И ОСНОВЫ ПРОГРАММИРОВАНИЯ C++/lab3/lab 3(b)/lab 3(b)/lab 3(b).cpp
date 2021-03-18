// lab 3(b).cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "iostream"
#include "cmath"
#include "cstdlib"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float a = 0, b = 1, c, z, x,y;
	int k, i,n;
	cout << "Введите Х(кроме 0):" << endl;
	cin >> x;
	cout << "Введите N:" << endl;
	cin >> n;
	
	for (k = 3; k <= n; k++)
	{for (i = 1; i < k + 7; i++)
		{
			if (i == 7 || i == 3) 
			{ 
				cout << "Знаменатель или числитель равен нулю" << endl; 
			}
			else 
			{
				"\n\n";
				b *= (pow(i, 3) - 27) / (i - 7);
				cout << "b=" << b << endl;
			}
		if(k==5 || x==0){ cout << "Знаменатель равен нулю" << endl; }
		else { a +=b*( pow(-2, k - 1) / ((k - 5)*pow(x, k))); }
	}
	
		}
	
	
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	

	system("pause");
	return 0;
}