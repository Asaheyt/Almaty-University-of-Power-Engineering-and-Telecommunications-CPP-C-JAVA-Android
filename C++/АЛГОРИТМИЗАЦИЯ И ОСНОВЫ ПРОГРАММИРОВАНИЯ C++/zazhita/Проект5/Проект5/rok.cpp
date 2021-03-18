#include "rok.h"
#include <iostream>
using namespace std;
bool simple(int a)
{
	bool x;
	x = true;
	for (int i = 2; i <= a / 2; i++)
	{
		if (a%i == 0) { x = false; return x; }
	}
	return x;
}