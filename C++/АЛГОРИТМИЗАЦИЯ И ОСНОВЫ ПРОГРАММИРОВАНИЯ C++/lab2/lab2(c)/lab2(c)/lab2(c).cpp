
#include "stdafx.h"
#include "iostream"
#include "cstdlib"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float a, b, c;
	cout << "Введите А:\t";
	cin >> a;
	cout << "Введите B:\t";
	cin >> b;
	cout << "Введите C:\t";
	cin >> c;

	if (a < b && a < c) cout << "Число А=" << a << " наименьшее" << endl;
	else if (b < a && b < c) cout << "Число B=" << b << " наименьшее" << endl;
	else if (c < a && c < b) cout << "Число C=" << c << " наименьшее" << endl;

	system("pause");
    return 0;
}

