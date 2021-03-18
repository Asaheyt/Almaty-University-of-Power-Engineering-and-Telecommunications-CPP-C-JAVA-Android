#include <iostream>
#include <math.h>
#include "cicle.h"
using namespace std;
int main()
{
    setlocale(LC_ALL,"Russian");
    float x,y1,y2;
    cout << "Введите X [-0.5;0)&&(0;0.5]:\t";
    cin>>x;
    if(x>=-0.5 && x<=0.5 && x!=0)
    {
        y1=asin(2*x)*asin(2*x)*asin(2*x)*(cos(7*x*x*x*x)/sin(7*x*x*x*x));
        cout<<"y1=\t"<<y1<<endl<<endl;
        y2=Arcsin(2*x)*Arcsin(2*x)*Arcsin(2*x)*(Ctg(7*x*x*x*x));
        cout<<"y2=\t"<<y2<<endl<<endl;
    }
    else cout<<"Не соответствует ОДЗ"<<endl;
    return 0;
}
