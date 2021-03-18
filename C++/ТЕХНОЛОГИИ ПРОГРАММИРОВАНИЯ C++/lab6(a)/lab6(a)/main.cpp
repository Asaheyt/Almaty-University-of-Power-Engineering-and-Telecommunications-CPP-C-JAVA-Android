#include"poli.h"
#include<iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Real_Number x(6), z, y;
	cin >> z;
	y = x*z;
	cout << "X: " << x << endl << "Z: " << z << endl << "Y: " << y << endl;
	cout << "Модуль: " << y.Modul() << endl << endl;
	
	Complex a(2, 2), b(4, 5), c;
	cout << "1.) " << a << endl << "2.) " << b << endl;
	c = a*b;
	cout << "3.) " << c << endl;
	cout << "Модуль: " << c.Modul() << endl;
	cin >> c;
	cout << c << endl;


	system("pause");
	return 0;
}