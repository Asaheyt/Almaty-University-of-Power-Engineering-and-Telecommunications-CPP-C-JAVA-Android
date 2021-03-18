#include <iostream>
#include "cmath"
#include "cstdlib"
#include "tys.h" 
using namespace  std;
int main()
{
	int n, c, x;
	cin >> x >> n;
	cout << sq(x, n) << endl;
	c = pow(5,x);
	cout << c << endl;
	system("pause");
	return 0;
}