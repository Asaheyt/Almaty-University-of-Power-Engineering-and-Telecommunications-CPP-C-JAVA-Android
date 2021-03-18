#include <iostream>
#include "zon.h"
#include "windows.h"
#include "cstdlib"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Organizacia b;
    Rabotnik R;
    Init(b);
    zp(R,"Гордон","Механик",24,400000);Push_back(b,R);
    zp(R,"Пушкин","Инженер",55,200100);Push_back(b,R);
    zp(R,"Ердаулетов","IT",20,4010200);Push_back(b,R);
    zp(R,"Ли","Консультант",7,100100);Push_back(b,R);
    zp(R,"Хаджиме","Хирург",20,3020100);Push_back(b,R);
    Show(b);
    cout<<endl;
    Pop_back(b,R);
    Show(b);
    cout<<endl;
    MenuSort(b);
    Show(b);
    cout<<endl;
    Clear(b);
    Show(b);
    cout<<endl;
    return 0;
}
