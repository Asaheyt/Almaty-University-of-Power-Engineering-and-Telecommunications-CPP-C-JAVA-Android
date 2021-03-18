#include <iostream>
#include "cstdlib"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 6;
	int a[n][n], k=3;
	for (int i = 0; i < n-1; i++)
	{
		cout << "Строка №" << i + 1 << "\t";
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10;
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	for (int i = n-1; i >k-1; i--)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = a[i - 1][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		a[k - 1][i] = 0;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Строка №" << i + 1 << "\t";
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}