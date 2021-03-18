#include <iostream>
#include "pr4.h"
#include "cstdlib"
using namespace std;
int main()
{
    const int n=8;
    int a[n], b[n] , d[n],z=n-1;
	zap(a, n);
	zap(b, n);
	showmas(a, n);
	showmas(b, n);
	mass(a, b, d, n);
	showmas(d,z );

	system("pause");
	return 0;
}