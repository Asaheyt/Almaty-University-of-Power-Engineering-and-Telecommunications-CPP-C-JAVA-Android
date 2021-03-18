#include <iostream>
#include "cstdlib"
#include "cmath"
#include "H12.h"
using namespace std;
int main()
{ 
	float x,z;
	setlocale( LC_ALL, "Russian");
	cout << "Введите Х:" << endl;
	cin >> x;
	cout << usl(x) << endl;
	pie(x, z);
	cout << z << endl;
	system("pause");
}