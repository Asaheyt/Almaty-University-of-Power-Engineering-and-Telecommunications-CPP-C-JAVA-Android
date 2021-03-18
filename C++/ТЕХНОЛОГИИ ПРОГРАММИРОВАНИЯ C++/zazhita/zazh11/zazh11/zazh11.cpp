// zazh11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "dmas.h"
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

int main()
{
	_wsetlocale(LC_CTYPE, L".866");
	binary_func o;
	int size = 10;
	int n = 0;
	Emploee *x;
	x = new Emploee[size];
	Emploee e(L"Виктор", L"Программист", 2,100500);
	fill(x, size, n, 12);
	Showall(x, n);
	wcout << L"Сортировка по убыванию" << endl;
	wcout << L"Сортировка по именам" << endl;
	o(false);
	Sortname(x, o, n);
	Showall(x, n);
	cout << endl;
	wcout << L"Сортировка по профессии" << endl;
	Sortjob(x, o, n);
	Showall(x, n);
	cout << endl;
	wcout << L"Сортировка по стажу" << endl;
	Sortseniority(x, o, n);
	Showall(x, n);
	cout << endl;
	wcout << L"Сортировка по зар.плате" << endl;
	Sortwages(x, o, n);
	Showall(x, n);
	wcout << endl;
	wcout << L"Сортировка по возрастанию" << endl;
	wcout << L"Сортировка по именам" << endl;
	o(true);
	Sortname(x, o, n);
	Showall(x, n);
	cout << endl;
	wcout << L"Сортировка по профессии" << endl;
	Sortjob(x, o, n);
	Showall(x, n);
	cout << endl;
	wcout << L"Сортировка по стажу" << endl;
	Sortseniority(x, o, n);
	Showall(x, n);
	cout << endl;
	wcout << L"Сортировка по зар.плате" << endl;
	Sortwages(x, o, n);
	Showall(x, n);
	wcout << endl;
	wcout << L"Вставка элементу перед индексом 7" << endl;
	indinsert(x, e, size, n, 4);
	Showall(x, n);
	wcout << endl;
	wcout << L"Вставка нескольких объектов по индексу" << endl;
	insert(x, n, e, size, 2, 4);
	Showall(x, n);
	wcout << endl;
	wcout << L"Перегурзка оператора по индексу" << endl;
	e = x[5];
	e.show();
	wcout << endl;
	system("pause");
	return 0;
}

