
#include "stdafx.h"
#include "iostream"
#include "cstdlib"
#include "cmath"


using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	
	float x, x3=2.2, x4=0.3, x5=-0.8;
	int y1, y2, y, y3 = -6, y4 = 3, y5 = -4, y6, y7, y8, y9, y10, y11;
	
    cout << "Введите X:\t ";
	cin >> x;
	cout << "Введите Y:\t ";
	cin >> y;
	
	y1 = pow(sin(pow(x, 3)), 2);
	y2 = sqrt(6 * asin(pow(x, 7)) + 4.5*pow(x, 6) + 4 * x*x + 2);
	y6 = pow(sin(pow(x3, 3)), 2);
	y7 = sqrt(6 * asin(pow(x3, 7)) + 4.5*pow(x3, 6) + 4 * x3*x3 + 2); 
	y8 = pow(sin(pow(x4, 3)), 2);
	y9 = sqrt(6 * asin(pow(x4, 7)) + 4.5*pow(x4, 6) + 4 * x4*x4 + 2); 
	y10 = pow(sin(pow(x5, 3)), 2);
	y11 = sqrt(6 * asin(pow(x5, 7)) + 4.5*pow(x5, 6) + 4 * x5*x5 + 2);

	if (x>1 || x<-1 ) { cout << y1 << endl;}
	else { cout <<  y2 << endl;}

	if (x3>1 || x3<-1) { cout << y1 << endl; }
	else { cout << y2 << endl; }

	if (x4>1 || x4<-1) { cout << y8 << endl; }
	else { cout << y9 << endl; }

	if (x5>1 || x5<-1) { cout << y10 << endl; }
	else { cout << y11 << endl; }
	
	if(y==y1 || y == y2){cout << "лежит" << endl;}
	else {cout << "Не лежит" << endl;}

	if (y3 == y6 || y3 == y7) { cout << "лежит" << endl; }
	else { cout << "Не лежит" << endl; }

	if (y4 == y8 || y4 == y9) { cout << "лежит" << endl; }
	else { cout << "Не лежит" << endl; }

	if (y5 == y10 || y5 == y11) { cout << "лежит" << endl; }
	else { cout << "Не лежит" << endl; }

	system("pause");
    return 0;
}

