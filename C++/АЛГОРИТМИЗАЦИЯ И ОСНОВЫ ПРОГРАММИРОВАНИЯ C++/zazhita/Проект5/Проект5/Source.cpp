#include <iostream>
#include "cstdlib"
#include "rok.h"
using namespace std;
int main()
{
	int n1, n2;
	n1 = 5;
	n2 = 6;
	int s;
	s = 0;
	for (int i = n1; i <= n2; i++)
	{
		if (simple(i)) { s++; }
	}
	cout << s << endl;
	cout << simple(3) << endl;
	system("pause");
	return 0;
}