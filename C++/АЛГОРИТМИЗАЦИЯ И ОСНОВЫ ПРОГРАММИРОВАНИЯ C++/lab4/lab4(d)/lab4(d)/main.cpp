#include <iostream>
#include "cstdlib"
using namespace std;
int main()
{
	const int n = 10;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%20;
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != a[i + 1]){ cout << a[i]<<" "; };
	}
	cout << endl;
	system("pause");
	return 0;
}