#include <iostream>
#include "log.h"
#include <windows.h>
#include <math.h>
#include <complex>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   /* Complex x;
    cin>>x;



    cout<<Log(Tg(Sh(x))+1)<<endl;*/

    complex<double> x(5,1);
    cout<<sin(x)<<endl;
    Complex y(5,1);
    cout<<Sincompl(y)<<endl;
    return 0;
}
