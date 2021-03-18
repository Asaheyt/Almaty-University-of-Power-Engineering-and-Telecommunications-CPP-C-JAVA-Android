#include "ras.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
void show(Rabotnik b)
{
    setlocale(LC_ALL,"Russian");
    cout<<"Зарплата: "<<b.zarplata<<" ";
    cout<<"Часы в неделю: "<<b.chasi<<" ";
    cout<<"Ранг: "<<b.rang<<" ";
    cout<<"Должность: "<<b.dolzhnost<<" ";
    cout<<"Время работы(год): "<<b.vremya<<endl;
}
void init(Organizacia &a)
{
    a.name="ZEVS";
    a.kolichestvo = 0;
}
void AddEl(Organizacia &a,Rabotnik &s,in &v)
{

    zp(s,v);
    a.b[a.kolichestvo]=new Rabotnik;
    *(a.b[a.kolichestvo])=s;
    a.kolichestvo++;
}
void DelEl(Organizacia &a)
{
    a.kolichestvo--;
}
void zp(Rabotnik &b,in &a)
{
 setlocale(LC_ALL,"Russian");
    if(a==0)
    {

        b.zarplata=100000;
        b.chasi=35;
        b.rang="Средний";
        b.dolzhnost= "Консультант";
        b.vremya=0.5;
    }
    if(a==1)
    {

        b.zarplata=200000;
        b.chasi=39;
        b.rang="Высший";
        b.dolzhnost= "IT";
        b.vremya=2;
    }
    if(a==2)
    {
        b.zarplata=150000;
        b.chasi=40;
        b.rang="Младший";
        b.dolzhnost= "Инженер";
        b.vremya=2.5;
    }
    a++;
}
void ShowYONKO(Organizacia a)
{
    setlocale(LC_ALL,"Russian");
    cout<<"Название: "<<a.name<<endl;
    cout<<"Количество работников: "<<a.kolichestvo<<endl;
    for(in i=0;i<a.kolichestvo;i++)
    {
        show(*(a.b[i]));
    }
}
void SravnZAR(Rabotnik s,Rabotnik d, int &z)
{
    if(s.zarplata>d.zarplata){z=1;}
    if(s.zarplata<d.zarplata){z=-1;}
    if(s.zarplata==d.zarplata){z=0;}
}
void SravnChas(Rabotnik s, Rabotnik d, int &z)
{
    if(s.chasi>d.chasi){z=1;}
    if(s.chasi<d.chasi){z=-1;}
    if(s.chasi==d.chasi){z=0;}
}
void SravnRang(Rabotnik s, Rabotnik d, int &z)
{
    setlocale(LC_ALL,"Russian");
    st s1="Младший",s2="Средний",s3="Высший";
    int l,k;
    if(s.rang==s1){l=1;}
    if(s.rang==s2){l=2;}
    if(s.rang==s3){l=3;}

    if(d.rang==s1){k=1;}
    if(d.rang==s2){k=2;}
    if(d.rang==s3){k=3;}

    if(l>k){z=1;}
    if(l<k){z=-1;}
    if(l==k){z=0;}
}
void SravnDol(Rabotnik s, Rabotnik d, int &z)
{
    setlocale(LC_ALL,"Russian");
    st s1="Консультант",s2="Инженер",s3="IT";
    int l,k;
    if(s.dolzhnost==s1){l=1;}
    if(s.dolzhnost==s2){l=2;}
    if(s.dolzhnost==s3){l=3;}

    if(d.dolzhnost==s1){k=1;}
    if(d.dolzhnost==s2){k=2;}
    if(d.dolzhnost==s3){k=3;}

    if(l>k){z=1;}
    if(l<k){z=-1;}
    if(l==k){z=0;}
}
void SravnVr(Rabotnik s, Rabotnik d, int &z)
{
    setlocale(LC_ALL,"Russian");
    if(s.vremya>d.vremya){z=1;}
    if(s.vremya<d.vremya){z=-1;}
    if(s.vremya==d.vremya){z=0;}
}
void Sort(Rabotnik &s, Rabotnik &d)
{
    in q,w;
    st e,r;
    fl t;

    q=s.chasi;
    s.chasi=d.chasi;
    d.chasi=q;

    w=s.zarplata;
    s.zarplata=d.zarplata;
    d.zarplata=w;

    t=s.vremya;
    s.vremya=d.vremya;
    d.vremya=t;

    e=s.dolzhnost;
    s.dolzhnost=d.dolzhnost;
    d.dolzhnost=e;

    r=s.rang;
    s.rang=d.rang;
    d.rang=r;
}
void OtsortZar(Organizacia &a)
{
    in z;
    for(in i=0;i<a.kolichestvo;i++)
    {
        for(in j=i+1;j<a.kolichestvo;j++)
        {
            SravnZAR(*(a.b[i]),*(a.b[j]),z);
            if(z==1){Sort(*(a.b[i]),*(a.b[j]));}
        }
    }
}
void OtsortChas(Organizacia &a)
{
    in z;
    for(in i=0;i<a.kolichestvo;i++)
    {
        for(in j=i+1;j<a.kolichestvo;j++)
        {
            SravnChas(*(a.b[i]),*(a.b[j]),z);
            if(z==1){Sort(*(a.b[i]),*(a.b[j]));}
        }
    }
}
void OtsortRang(Organizacia &a)
{
    in z;
    for(in i=0;i<a.kolichestvo;i++)
    {
        for(in j=i+1;j<a.kolichestvo;j++)
        {
            SravnRang(*(a.b[i]),*(a.b[j]),z);
            if(z==1){Sort(*(a.b[i]),*(a.b[j]));}
        }
    }
}
void OtsortDol(Organizacia &a)
{
    in z;
    for(in i=0;i<a.kolichestvo;i++)
    {
        for(in j=i+1;j<a.kolichestvo;j++)
        {
            SravnDol(*(a.b[i]),*(a.b[j]),z);
            if(z==1){Sort(*(a.b[i]),*(a.b[j]));}
        }
    }
}
void OtsortVr(Organizacia &a)
{
    in z;
    for(in i=0;i<a.kolichestvo;i++)
    {
        for(in j=i+1;j<a.kolichestvo;j++)
        {
            SravnVr(*(a.b[i]),*(a.b[j]),z);
            if(z==1){Sort(*(a.b[i]),*(a.b[j]));}
        }
    }
}


