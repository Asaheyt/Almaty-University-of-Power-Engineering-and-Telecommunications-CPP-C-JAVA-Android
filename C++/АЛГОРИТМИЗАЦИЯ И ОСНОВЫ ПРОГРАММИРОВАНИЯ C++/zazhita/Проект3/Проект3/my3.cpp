#include "my3.h"
#include <iostream>
using namespace std;
void bir(float a, float &b)
{
	b = ((a*a - 25) / (a + 3))*(1 / (a*a + 5 * a)) - (a + 5) / (a*a - 3 * a);
}