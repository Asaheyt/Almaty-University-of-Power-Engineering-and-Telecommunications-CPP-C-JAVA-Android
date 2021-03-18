// lab13(a).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stl.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

int main()
{
	_wsetlocale(LC_CTYPE, L".1251");
	_wsetlocale(LC_CTYPE, L".866");
	srand(time(NULL));

	Organization *x;
	Organization_Mas a;
	x = &a;
	cnslCmd(x);
	Organization_Ukaz b;
	x = &b;
	cnslCmd(x);
	Organization_DinMas c;
	x = &c;
	cnslCmd(x);
	Organization_DinList d;
	x = &d;
	cnslCmd(x);
	Organization_Vect e;
	x = &e;
	cnslCmd(x);

	system("pause");
	return 0;
}
