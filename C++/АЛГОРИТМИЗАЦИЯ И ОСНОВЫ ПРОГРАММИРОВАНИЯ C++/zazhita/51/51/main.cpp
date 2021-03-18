#include <iostream>
#include "cstdlib"
#include "gin.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 4, m = 4;
	int *a, *b, *c, *d, *e, *f, *g;
	a = new int[100];
	b = new int[100];
	c = new int[100];
	d = new int[100];
	e = new int[100];
	f = new int[100];
	g = new int[100];
	zap(a, n, m);
	cout << "Массив А" << endl;
	show(a, n, m);
	zap(b, n, m);
	cout << "Массив B" << endl;
	show(b, n, m);
	zap(c, n, m);
	cout << "Массив C" << endl;
	show(c, n, m);
	zap(d, n, m);
	cout << "Массив D" << endl;
	show(d, n, m);

	umn(b, c, e, n, m);
	cout << "Умножение (B*C)(Вывод в E)" << endl;
	show(e, n, m);
	umn(e, d, f, n, m);
	cout << "Умножение (E*D)(Вывод в F)" << endl;
	show(f, n, m);
	sum(a, f, g, n, m);
	cout << "Сумма (F+A)" << endl;
	show(g, n, m);
	system("pause");
	return 0;
}
