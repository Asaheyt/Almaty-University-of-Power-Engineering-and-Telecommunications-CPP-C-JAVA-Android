// 3123.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include "cmath"
#include "cstdlib"
#include "tip.h" 
using namespace  std;
int main()
{
	float n, c,x;
	cin >>x >> n;
	cout << sq(x,n) <<endl;
	c = 1/sqrt(4+x);
	cout << c << endl;
	system("pause");
    return 0;
}