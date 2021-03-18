#include <iostream>
#include <cstdlib>
#include "my3.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	float c, a, b;

	cout << "Введите A:\t";
	cin >> a;
	c = 16 / (9-a*a);
	cout << "Ответ C:\t\n" << c << endl;
	
	bir(a, b);
	cout << b << endl;

	system("pause");


	return 0;
}