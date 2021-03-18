#include "H12.h"
#include <iostream>
using namespace std;
float usl(float x)
{
	float y;
	if (x< 0) { y = x+1; }
	else if (x < 1) { y = x*x-1; }
	else { y = -x; }
	return y;
}
void pie(float x, float &h)
{
	if (x< 0) { h = x + 1; }
	else if (x < 1) { h = x*x - 1; }
	else { h = -x; }
}