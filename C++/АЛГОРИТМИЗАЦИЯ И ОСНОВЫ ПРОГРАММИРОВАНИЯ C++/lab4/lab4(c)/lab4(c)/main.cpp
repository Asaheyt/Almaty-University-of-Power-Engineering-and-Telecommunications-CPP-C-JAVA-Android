#include <iostream>
#include "cstdlib"
using namespace std;
int main()
{
	const int n = 10;
	int a[n], z = 0, g=0;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%100;
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[z]){ z = i; }
		if (a[i]>a[g]){ g = i; }
	}
	swap (a[g], a[z]);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}