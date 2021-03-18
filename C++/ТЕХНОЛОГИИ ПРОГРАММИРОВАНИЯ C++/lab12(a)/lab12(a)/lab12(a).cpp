// lab12(a).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "dsp.h"
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

	Organization x;
	binary_func a(true);
	Emploee e(L"Адиль", 49, 01234567, L"Программист", 400500, 2);
	wcout << L"Динамический список" << endl;
	x.RANDOM_Fill(5);
	x.show();
	cout << endl;
	wcout << L"Сортировка по имени(по возрастанию) с помощью функтора" << endl;
	x.Sortname(a);
	x.show();
	cout << endl;
	wcout << L"Добавление елемента в начало списка" << endl;
	x.push_front(e);
	x.show();
	cout << endl;
	wcout << L"Сортировка по зар.плате(по убыванию) с помощью предиката" << endl;
	x.sorting(cmpWages);
	x.show();
	cout << endl;
	Organization y;
	wcout << L"Чтение из файла" << endl;
	y.readfromfile();
	y.show();
	cout << endl;
	wcout << L"Удаление последнего элемента" << endl;
	y.pop_back();
	y.show();
	cout << endl;
	wcout << L"Запись в файл" << endl;
	y.inputinfile();
	wcout << L"Ввод данных" << endl;
	e.input();
	wcout << L"Элмент" << endl;
	e.show();
	system("pause");
	return 0;
}

