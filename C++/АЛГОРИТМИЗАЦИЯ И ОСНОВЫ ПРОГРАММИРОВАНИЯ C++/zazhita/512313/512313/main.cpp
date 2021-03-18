#include <iostream>
#include "cstdlib"
using namespace std;
int main()
{
	const int n = 5;
	int a[n][n],c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10;
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		c = 0;
		for (int j = 0; j < n; j++)
		{
			c += a[i][j]; a[i][j] = 0;
		}
		a[i][n - 1 - i] = c;
	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	


	system("pause");
	return 0;
}