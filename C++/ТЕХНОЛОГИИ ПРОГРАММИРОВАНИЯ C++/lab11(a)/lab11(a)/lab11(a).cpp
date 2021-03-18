// lab11(a).cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include <iostream>
#include "din.h"
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

int main()
{
	_wsetlocale(LC_CTYPE, L".1251");
	_wsetlocale(LC_CTYPE, L".866");
	srand(time(NULL));

	Organization c;
	cnslCmd(c);

	
	system("pause");
	return 0;
}

