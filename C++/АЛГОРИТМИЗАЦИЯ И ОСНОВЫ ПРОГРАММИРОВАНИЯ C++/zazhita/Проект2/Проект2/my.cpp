#include "my.h"
#include <iostream>
#include "cmath"
float sum(float a)
	{
	float x = ((a - pow(a, 8)) / (pow(a, 6) + a*a)) / ((pow(a, 9) - a*a) / (pow(a, 5) + a));
		return x ;
	}
void bir(float h, float &j)
{
	j = ((h*h - 25) / (h + 3))*(1 / (h*h + 5 * h)) - (h + 5) / (h*h - 3 * h);
}
	