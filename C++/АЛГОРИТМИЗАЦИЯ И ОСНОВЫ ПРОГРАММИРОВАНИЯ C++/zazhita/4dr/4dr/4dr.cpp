#include <iostream>
#include "cstdlib"
#include "hit.h"
using namespace std;
int main()
{
	const int n = 5;
	int a[n],b[n],c[n],d[n],e[n],f[n],g[n];
	sum(a, b, e, n);
	cout << "\n";
	min(c, d, f, n);
	cout << "\n";
	umn(e, f, g, n);
	cout << "\n";

	system("pause");
	return 0;
}