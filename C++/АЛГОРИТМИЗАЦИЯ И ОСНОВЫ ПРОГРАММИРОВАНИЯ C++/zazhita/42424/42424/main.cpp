#include <iostream>
#include "cstdlib"
using namespace std;

int main()
{
	const int n = 100;
	int a[n];
	for (int i = 0; i<n; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout <<'\n'<< endl;
	int f,k=0;
	for (int i = 0; i<n; i++)
	{
		f = 0;
		for (int j = 2; j<a[i]; j++)
		{
			if (a[i] % j == 0){ f = 1; break; }
		}
		if ((f == 0) && (a[i] != 0) && (a[i] != 1)){ a[k] = a[i]; k++; }
	}
	cout << endl;
	for (int i = 0; i<k; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
