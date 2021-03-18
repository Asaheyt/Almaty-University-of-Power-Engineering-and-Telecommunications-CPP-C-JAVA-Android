// lab3(c).cpp: определ€ет точку входа дл€ консольного приложени€.
//
#include "stdafx.h"
#include <iostream>
#include "cstdlib"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, a=-1;
	cout << "¬ведите N[100;800):" << endl;
	cin >> n;
	do { a++; n++; } while (n >= 100 && n < 800);
	cout << a << endl;
	system("pause");
    return 0;
}

