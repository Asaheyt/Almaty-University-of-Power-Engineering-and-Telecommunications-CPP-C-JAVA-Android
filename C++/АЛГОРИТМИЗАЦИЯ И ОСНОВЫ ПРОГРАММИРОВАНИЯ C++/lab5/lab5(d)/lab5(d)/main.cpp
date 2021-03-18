#include <iostream>
#include "cstdlib"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 6;
	int a[n][n];
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10;
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "\n\n";
	/*for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			a[j][i] = 0;
		}
	}*/
	for (int i = n - 1, j = 0; i < -1, j < n; i--, j++)
	{
		for (int g = j; g < n; g++)
		{
			a[i][g] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}