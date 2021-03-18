// lab3(d).cpp: определ€ет точку входа дл€ консольного приложени€.
//
#include "stdafx.h"
#include <iostream>
#include "cstdlib"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int m, n, i = 0, a, b, c;
	cout << "¬ведите M:" << endl;
	cin >> m;
	while (i < 1000)
	{   
		n = i++;
		for (a = -101,b = 0; a <= 799, b < 1000;a = a + 200,b = b + 200)
		{
			if (n > a && n < b)
			{
				n += 0;
			}
		}
	} c = n / m;
				cout << c << "  ";
	system("pause");
	return 0;
}


