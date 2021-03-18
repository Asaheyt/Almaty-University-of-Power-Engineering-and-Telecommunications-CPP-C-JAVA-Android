#include <iostream>
#include "sup.h"
#include "windows.h"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Stack1 a;
    Rabotnik R;
    int k;
    Init(a);
    zp(R,"Гордон","Механик",24,400000);Push1(a,R);
    zp(R,"Пушкин","Инженер",55,200100);Push1(a,R);
    zp(R,"Ердаулетов","IT",20,4010200);Push1(a,R);
    zp(R,"Ли","Консультант",7,100100);Push1(a,R);
    zp(R,"Хаджиме","Хирург",20,3020100);Push1(a,R);
    k=a.nRab;
    for(int i = 0;i < k ;i++)
    {
        Pop1(a,R);
        ShowOne(R);
    }
    cout<<endl<<endl;
    //----------------------------------------------
    Stack2 b;
    Init2(b);
    zp(R,"Гордон","Механик",24,400000);Push2(b,R);
    zp(R,"Пушкин","Инженер",55,200100);Push2(b,R);
    zp(R,"Ердаулетов","IT",20,4010200);Push2(b,R);
    zp(R,"Ли","Консультант",7,100100);Push2(b,R);
    zp(R,"Хаджиме","Хирург",20,3020100);Push2(b,R);
    k=b.NRab;
    for(int i = 0;i < k ;i++)
    {
        Pop2(b,R);
        ShowOne(R);
    }
    cout<<endl<<endl;
    //----------------------------------------------
    Stack2 c;
    Init2(c);
    zp(R,"Гордон","Механик",24,400000);enqueue(c,R);
    zp(R,"Пушкин","Инженер",55,200100);enqueue(c,R);
    zp(R,"Ердаулетов","IT",20,4010200);enqueue(c,R);
    zp(R,"Ли","Консультант",7,100100);enqueue(c,R);
    zp(R,"Хаджиме","Хирург",20,3020100);enqueue(c,R);
    k=c.NRab;
    for(int i = 0;i < k ;i++)
    {
        dequeue(c,R);
        ShowOne(R);
    }
    cout<<endl<<endl;
    return 0;
}
