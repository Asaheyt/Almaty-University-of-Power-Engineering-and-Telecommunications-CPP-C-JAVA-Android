// lab10(a).cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "fai.h"
#include <cstdlib>
#include <ctime>
#include <locale>
#include <fstream>
using namespace std;

int main()
{
	_wsetlocale(LC_CTYPE, L".1251");
	_wsetlocale(LC_CTYPE, L".866");
	srand(time(NULL));
	
	Organization *c;
	Organization_Ukaz a;
	Organization_Mas b;
	wcout << L"Работа с массивом указателей" << endl;
	c = &a;
	cnslCmd(c);
	wcout << endl << L"Работа с массивом объектов" << endl;
	c = &b;
	cnslCmd(c);

	system("pause");
	return 0;
}
