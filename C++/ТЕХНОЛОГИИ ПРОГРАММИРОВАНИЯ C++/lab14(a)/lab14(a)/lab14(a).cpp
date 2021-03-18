// lab14(a).cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "alg.h"
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

	/*Organization *x;
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
	cnslCmd(x);*/

	Func a(true);
	wcout << L"Динамический лист" << endl;
	Organization_DinList f;
	f.RANDOM_Fill(5);
	f.show();
	wcout << endl;
	f.SortName(a);
	f.show();
	wcout << endl;
	a(false);
	f.SortName(a);
	f.show();
	wcout << endl;

	/*wcout << L"Вектор" << endl;
	Func y(2);
	Organization_Vect x;
	x.RANDOM_Fill(5);
	x.show();
	wcout << endl;
	x.SortName(y);
	x.show();
	wcout << endl;
	y(-1);
	x.SortName(y);
	x.show();
	wcout << endl;*/
	

	system("pause");
	return 0;
}
