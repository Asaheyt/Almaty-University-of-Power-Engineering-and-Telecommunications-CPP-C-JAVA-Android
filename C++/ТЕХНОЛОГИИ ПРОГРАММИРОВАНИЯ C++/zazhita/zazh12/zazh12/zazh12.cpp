// zazh12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "dlist.h"
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

	List x;
	wcout << L"Динамический список" << endl;
	x.RANDOM_Fill(5);
	x.show();
	cout << endl;
	wcout << L"Сортировка по имени" << endl;
	x.sorting(cmpName);
	x.show();
	cout << endl;
	wcout << L"Сортировка по возрасту" << endl;
	x.sorting(cmpAge);
	x.show();
	cout << endl;
	wcout << L"Сортировка по породе" << endl;
	x.sorting(cmpType);
	x.show();
	cout << endl;

	system("pause");
	return 0;
}

