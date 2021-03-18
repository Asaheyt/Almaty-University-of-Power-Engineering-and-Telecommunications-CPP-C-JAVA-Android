#include "tys.h"

#include <iostream>
using namespace std;
float sq(float x, float n)
{
	float a = 0, g = 1, h=1, j=1;
	for (int i = 1; i <= n; i++)
	{
		a += g*h / j;
		g = g*x;
		h = h*log(5);
		j = j*i;
	}
	return a;
}