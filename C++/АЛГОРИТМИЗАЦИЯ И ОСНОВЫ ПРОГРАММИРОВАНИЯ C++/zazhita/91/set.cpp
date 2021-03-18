#include "set.h"
#include <iostream>
using namespace std;
void Fill(Rabotnik *R)
{
    setlocale(LC_ALL,"Russian");
    R[0].Familiya="Гордон    ";
    R[0].Dolzhnost="Консультант   ";
    R[0].D1.day=20;R[0].D1.month=10;R[0].D1.year=2016;
    R[0].Srok=24;
    R[0].Oklad=400000;

    R[1].Familiya="Пушкин    ";
    R[1].Dolzhnost="Инженер       ";
    R[1].D1.day=20;R[1].D1.month=9;R[1].D1.year=2016;
    R[1].Srok=55;
    R[1].Oklad=200000;

    R[2].Familiya="Ердаулетов";
    R[2].Dolzhnost="IT-специалист ";
    R[2].D1.day=2;R[2].D1.month=11;R[2].D1.year=2016;
    R[2].Srok=15;
    R[2].Oklad=4000000;

    R[3].Familiya="Ли        ";
    R[3].Dolzhnost="Механик       ";
    R[3].D1.day=6;R[3].D1.month=11;R[3].D1.year=2016;
    R[3].Srok=6;
    R[3].Oklad=100000;

    R[4].Familiya="Хаджимэ   ";
    R[4].Dolzhnost="Хирург        ";
    R[4].D1.day=5;R[4].D1.month=11;R[4].D1.year=2016;
    R[4].Srok=40;
    R[4].Oklad=3000000;
}
void ShowAll(Rabotnik *r, int N)
{
    setlocale(LC_ALL,"Russian");
    for(int i=0; i<N; i++)
    {
        ShowOne(r,i);
    }
}
void ShowOne(Rabotnik *r, int j)
{
    setlocale(LC_ALL,"Russian");
    cout<<"Фамилия работника: "<<r[j].Familiya;
    cout<<" Должность: "<<r[j].Dolzhnost;
    cout<<" Дата подписания контракта: "<<r[j].D1.day<<"."<<r[j].D1.month<<"."<<r[j].D1.year;
    cout<<" Срок действия контракта: "<<r[j].Srok;
    cout<<" Оклад: "<<r[j].Oklad<<endl;

}
void fillTod(Today &b)
{
    b.day=11;
    b.month=11;
    b.year=2016;
}
void showTod(Today b)
{
    cout<<b.day<<"."<<b.month<<"."<<b.year<<endl;
}
void res(Rabotnik *r, Today w, int N)
{
    int g,h,k;

    for(int i=0;i<N;i++)
    {
        opred(r,w,g,h,i);
        k=h+5;
        if(g>h&&g<=k)
        {
            ShowOne(r,i);
        }
    }
}
void opred(Rabotnik *r,Today w,int &o,int &p,int i)
{
    o=r[i].D1.day+(r[i].D1.month-1)*30+(r[i].D1.year-1)*365+r[i].Srok;
    int f;
    f=r[i].D1.month-1;
    if(f<=7&&f%2==0){o+=f/2;}
    if(f<=7&&f%2!=0){o+=f/2+1;}
    if(f>7){o+=f/2+1;}
    p=w.day+((w.month-1)*30)+((w.year-1)*365);
    int s;
    s=w.month-1;
    if(s<=7&&s%2==0){p+=s/2;}
    if(s<=7&&s%2!=0){p+=s/2+1;}
    if(s>7){p+=s/2+1;}

}
