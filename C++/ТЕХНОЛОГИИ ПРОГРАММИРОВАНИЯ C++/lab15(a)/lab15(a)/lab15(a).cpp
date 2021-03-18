// lab15(a).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "wab.h"
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

	Func t(1, false);
	OrganizationMyVect<Emploee> x;
	Emploee y;
	y.RANDOM(); x.push_back(y);
	y.RANDOM(); x.push_back(y);
	y.RANDOM(); x.push_back(y);
	y.RANDOM(); x.push_back(y);
	y.RANDOM(); x.push_back(y);
	y.RANDOM(); x.push_back(y);
	x.list_shops();
	wcout << endl;
	x.Sort(t);
	x.list_shops();


	system("pause");
	return 0;
}

