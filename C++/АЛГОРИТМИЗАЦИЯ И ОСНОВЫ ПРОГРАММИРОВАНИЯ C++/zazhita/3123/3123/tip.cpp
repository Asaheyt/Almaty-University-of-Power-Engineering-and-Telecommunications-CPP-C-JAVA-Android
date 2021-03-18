#include "tip.h"
#include "stdafx.h"
#include <iostream>
using namespace std;
float sq(float x,float n)
{
	float a = 0, b = 2, z, v, d = -1, f = 1, g = 1, j;
	v = x + 3;
	for (int i = 2; i <= n; i++)
{
	a += (d* f*v) / (b*g);
	j = 2 * i - 1;
	f = f*j;
	g = g*i;
	v = v*(x + 3);
	b = b + b;
	z = 1 + a;
	d = d*-1;

}
return z;
}