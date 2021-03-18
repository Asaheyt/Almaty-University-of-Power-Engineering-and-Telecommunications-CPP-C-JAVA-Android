#include <iostream>
#include "hit.h"
using namespace std;
int sum(int *a, int *b, int *e, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		b[i] = rand() % 100;
	}
	cout << "a=  \t";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "b=  \t";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	cout << "Summa=  ";
	for (int i = 0; i < n; i++)
	{
		e[i] = a[i] + b[i];
		cout << e[i] << " ";
	}
	cout << endl;
	return 0;
}
int min(int *c, int *d, int *f, int n)
{
	for (int i = 0; i < n; i++)
	{
		c[i] = rand() % 100;
		d[i] = rand() % 100;
	}
	cout << "c=  \t";
	for (int i = 0; i < n; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	cout << "d=  \t";
	for (int i = 0; i < n; i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
	cout << "Raznost=  ";
	for (int i = 0; i < n; i++)
	{
		f[i] = c[i] - d[i];
		cout << f[i] << " ";
	}
	cout << endl;
	return 0;
}
int umn(int *e, int *f, int *g, int n)
{
	cout << "Proizvedenie=  ";
	for (int i = 0; i < n; i++)
	{
		g[i] = e[i] * f[i];
		cout << g[i] << " ";
	}
	cout << endl;
	return 0;
}