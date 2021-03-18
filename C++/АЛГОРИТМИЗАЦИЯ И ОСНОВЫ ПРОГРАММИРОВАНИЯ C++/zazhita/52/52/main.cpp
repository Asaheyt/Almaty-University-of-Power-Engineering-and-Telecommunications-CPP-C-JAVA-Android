#include <iostream>
#include "raf.h"
#include "cstdlib"
using namespace std;

int main()
{
	int *a, n, m;
	a = new int[100];
	n = 5;
	m = 6;
	fillmass(a, n, m);
	showmass(a, n, m);
	cout << endl;
	geer(a, n, m);
	showmass(a, n, m);
	system("pause");
	return 0;
}
