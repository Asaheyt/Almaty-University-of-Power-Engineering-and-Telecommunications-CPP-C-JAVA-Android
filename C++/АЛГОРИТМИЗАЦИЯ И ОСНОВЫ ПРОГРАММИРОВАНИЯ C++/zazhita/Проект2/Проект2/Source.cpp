#include <iostream>
#include <cstdlib>
#include "my.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float y, a,b;
	cout << "Введите A:\t";
	cin >> a;
	y = -1/(a*a);
	cout << "Ответ:\n" << y << endl;
	cout << sum(a)<< endl;
	
	float c, h, j;

	cout << "Введите A:\t";
	cin >> h;
	c = 16 / (9 - h*h);
	cout << "Ответ C:\t\n" << c << endl;

	bir(h, j);
	cout << j << endl;

	system("pause");
	return 0;
}