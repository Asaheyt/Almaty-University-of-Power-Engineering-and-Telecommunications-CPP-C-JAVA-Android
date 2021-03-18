
#include "stdafx.h"
#include "cstdlib"
#include "iostream"
#include "cmath"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float a, b, c, d;
	cout << "Введите А:\t";
	cin >> a;
	cout << "Введите В:\t";
	cin >> b;
	c = a*a - b*b;
	d = pow(a - b, 2);
	if (c > d)  cout << "Разность квадратов больше" << endl;
	else if (c < d) cout << "Квадрат разности больше" << endl;
	else cout << "Они равны" << endl;

	system("pause");
    return 0;
}

