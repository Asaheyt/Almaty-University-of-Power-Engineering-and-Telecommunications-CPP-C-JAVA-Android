#include <iostream>
#include "cstdlib"
using namespace std;
int main()
{
	const int n = 5;
	int a[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[j][i] = rand() % 100;
			cout << a[j][i] << "  ";
		}cout << endl;
	}
	cout << endl;
	for (int j = 0, x=1; j < n,x<=n; j++,x++)
	{
		for (int i = 0; i < n - j; i++)
		{
			cout << a[j][i] << "  ";
		}
		cout << endl;
		for (int i = j+1; i < n; i++)
		{
			cout << a[i][n -x] << "  ";
		}cout << endl;
	}
	system("pause");
	return 0;
}