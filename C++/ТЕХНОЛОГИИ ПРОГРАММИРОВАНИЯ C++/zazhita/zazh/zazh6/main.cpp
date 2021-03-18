#include <iostream>
#include "vir.h"
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
using namespace std;

int main()
{
    srand(time(NULL));
    cout<<"Bit String: "<<endl;
    BitString a(100), b(7),c(100);
    a.random();
    //b.random();
    cout<<"Do sdviga: "<<endl;
    a.show();
    cout<<"Posle sdviga <<5: "<<endl;
    c=a<<5;
    c.show();
    /*cout<<"B: "<<endl;
    b.show();
    c=a&b;
    cout<<"C=A&B: "<<endl;
    c.show();
    c=a|b;
    cout<<"C=A|B: "<<endl;
    c.show();
    c=a^b;
    cout<<"C=A^B: "<<endl;
    c.show();
    c=~a;
    cout<<"C=~A: "<<endl;
    c.show();
    c=a&b;
    cout<<"C=A&B: "<<endl;
    c.show();
    c=a>>2;
    cout<<"C=A>>2: "<<endl;
    c.show();
    c=a<<2;
    cout<<"C=A<<2: "<<endl;
    c.show();
    cout<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Hex"<<endl;
    Hex a1(3),b1(3),c1;
    a1.random();
    cout<<"A1: "<<endl;
    a1.show();
    b1.random();
    cout<<"B1: "<<endl;
    b1.show();
    c1=a1*b1;
    cout<<"C1=A1*B1"<<endl;
    c1.show();
    c1=a1/b1;
    cout<<"C1=A1/B1"<<endl;
    c1.show();
    c1=a1-b1;
    cout<<"C1=|A1-B1|"<<endl;
    c1.show();
    c1=Compare(a1,b1);
    cout<<"C1=Compare(A1,B1)"<<endl;
    c1.show();
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Virtual function: "<<endl;
    Array *y[5];
    y[0]=&a;
    cout<<"BitString: "<<endl;
    cout<<y[0]->sum(b.getBS())<<endl;
    y[1]=&a1;
    cout<<"Hex: "<<endl;
    c1.setH(y[1]->sum(b1.getH()));
    c1.show();*/
    return 0;
}
