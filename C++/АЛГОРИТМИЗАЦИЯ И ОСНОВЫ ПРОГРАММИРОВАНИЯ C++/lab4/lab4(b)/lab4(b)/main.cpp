#include <iostream>
#include "cstdlib"
using namespace std;
int main()
{
	const int n = 20;
	int c, k;
	int a[n],b=0;
	for (int i = 0; i<n; i++)
	{
		a[i] = rand()%100;
		cout << a[i]<<"  ";
	}
	cout << endl;
	for (int i = 0; i<n-1; i++)
	{
		if ((a[i] + a[i + 1]) > b){ b = (a[i] + a[i + 1]); k = i; }
	}
	cout << a[k] << " " << a[k + 1] << endl;
	system("pause");
	return 0;
}
