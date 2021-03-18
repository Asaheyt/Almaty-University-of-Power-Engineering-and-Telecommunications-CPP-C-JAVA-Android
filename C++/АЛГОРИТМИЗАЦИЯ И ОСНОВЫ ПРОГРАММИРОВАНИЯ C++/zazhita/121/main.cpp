#include <iostream>
#include "luk.h"
#include "windows.h"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Stack b;
    InitStack(b);
    Rabotnik R;

    zp(R,"Гордон","Механик",20,10,2016,24,400000);Push(b,R);
    zp(R,"Пушкин","Инженер",15,9,2016,55,200100);Push(b,R);
    zp(R,"Ердаулетов","IT",15,11,2016,20,4010200);Push(b,R);
    zp(R,"Ли","Консультант",1,8,2016,7,100100);Push(b,R);
    zp(R,"Хаджиме","Хирург",3,11,2016,20,3020100);Push(b,R);
    cout<<"Стек:"<<endl;
    ShowStack(b,R);
    cout<<endl<<endl;


    Queue c;
    InitQueue(c);

    zp(R,"Гордон","Механик",20,10,2016,24,400000);enqueue(c,R);
    zp(R,"Пушкин","Инженер",15,9,2016,55,200100);enqueue(c,R);
    zp(R,"Ердаулетов","IT",15,11,2016,20,4010200);enqueue(c,R);
    zp(R,"Ли","Консультант",1,8,2016,7,100100);enqueue(c,R);
    zp(R,"Хаджиме","Хирург",3,11,2016,20,3020100);enqueue(c,R);
    cout<<"Очередь:"<<endl;
    ShowQueue(c,R);
    cout<<endl<<endl;
    return 0;
}
