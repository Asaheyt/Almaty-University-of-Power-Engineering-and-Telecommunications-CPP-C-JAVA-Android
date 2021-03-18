// zazh9.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "rel.h"
#include <cstdlib>
#include <ctime>
#include <locale>
using namespace std;

int main()
{
	_wsetlocale(LC_CTYPE, L".1251");
	_wsetlocale(LC_CTYPE, L".866");
	srand(time(NULL));
	/*
	Organization *c;
	Organization_Ukaz a;
	Organization_Mas b;
	wcout << L"Работа с массивом указателей" << endl;
	c = &a;
	cnslCmd(c);
	wcout << endl << L"Работа с массивом объектов" << endl;
	c = &b;
	cnslCmd(c);

	wcout << endl << L"Использование конструктора копирования" << endl;
	Organization_Ukaz x;
	x.RANDOM_Fill(5);
	*/
	Organization_Mas z, d;
	z.RANDOM_Fill(5);
	d.RANDOM_Fill(6);
	wcout << L"A:" << endl;
	z.show();
	wcout << endl;
	wcout << L"B:" << endl;
	d.show();
	wcout << endl;
	wcout << L" Без использование оператора присваивания" << endl;
	d = z;
	wcout << L"A:" << endl;
	d.show();
	wcout << endl;
	wcout << L"B:" << endl;
	z.show();
	wcout << endl;
	
	system("pause");
	return 0;
}
