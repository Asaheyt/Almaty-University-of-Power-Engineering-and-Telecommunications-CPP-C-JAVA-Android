#include <iostream>
#include "Com.h"
#include <windows.h>
#include <math.h>
#include <complex>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    complex<double> a(1,2);
    //cout<<asin(a)<<endl;
    Complex b(1,2), c, d;
    c=Th_Com(b*5);
    d=Arcsin_Com(b+1);
    cout<<Pow_Com(c,d)<<endl;
    return 0;
}
