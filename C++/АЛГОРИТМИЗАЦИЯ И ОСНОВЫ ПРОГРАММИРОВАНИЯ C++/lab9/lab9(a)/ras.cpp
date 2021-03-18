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
    a.b = new Rabotnik[NMAX];
}
void AddEl(Organizacia &a)
{
    Fill(a);
    a.kolichestvo++;
}
void DelEl(Organizacia &a)
{
    Erase(a);
    a.kolichestvo--;
}
void Erase(Organizacia &a)
{
    int m=a.kolichestvo;
        a.b[m].zarplata=0;
        a.b[m].chasi=0;
        a.b[m].rang=" ";
        a.b[m].dolzhnost= " ";
        a.b[m].vremya=0;
}
void Fill(Organizacia &a)
{
    setlocale(LC_ALL,"Russian");
    if(a.kolichestvo==0)
    {
        a.b[0].zarplata=100000;
        a.b[0].chasi=35;
        a.b[0].rang="Средний";
        a.b[0].dolzhnost= "Консультант";
        a.b[0].vremya=0.5;
    }
    if(a.kolichestvo==1)
    {
        a.b[1].zarplata=200000;
        a.b[1].chasi=39;
        a.b[1].rang="Высший";
        a.b[1].dolzhnost= "IT";
        a.b[1].vremya=2;
    }
    if(a.kolichestvo==2)
    {
        a.b[2].zarplata=150000;
        a.b[2].chasi=40;
        a.b[2].rang="Младший";
        a.b[2].dolzhnost= "Инженер";
        a.b[2].vremya=2.5;
    }

}
void ShowYONKO(Organizacia a)
{
    setlocale(LC_ALL,"Russian");
    cout<<"Название: "<<a.name<<endl;
    cout<<"Количество работников: "<<a.kolichestvo<<endl;
    for(int i=0;i<a.kolichestvo;i++)
    {
        show(a.b[i]);
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
    string s1="Младший",s2="Средний",s3="Высший";
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
    string s1="Консультант",s2="Инженер",s3="IT";
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
    int q,w;
    string e,r;
    float t;

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
    int z;
    for(int i=0;i<a.kolichestvo;i++)
    {
        for(int j=i+1;j<a.kolichestvo;j++)
        {
            SravnZAR(a.b[i],a.b[j],z);
            if(z==1){Sort(a.b[i],a.b[j]);}
        }
    }
}
void OtsortChas(Organizacia &a)
{
    int z;
    for(int i=0;i<a.kolichestvo;i++)
    {
        for(int j=i+1;j<a.kolichestvo;j++)
        {
            SravnChas(a.b[i],a.b[j],z);
            if(z==1){Sort(a.b[i],a.b[j]);}
        }
    }
}
void OtsortRang(Organizacia &a)
{
    int z;
    for(int i=0;i<a.kolichestvo;i++)
    {
        for(int j=i+1;j<a.kolichestvo;j++)
        {
            SravnRang(a.b[i],a.b[j],z);
            if(z==1){Sort(a.b[i],a.b[j]);}
        }
    }
}
void OtsortDol(Organizacia &a)
{
    int z;
    for(int i=0;i<a.kolichestvo;i++)
    {
        for(int j=i+1;j<a.kolichestvo;j++)
        {
            SravnDol(a.b[i],a.b[j],z);
            if(z==1){Sort(a.b[i],a.b[j]);}
        }
    }
}
void OtsortVr(Organizacia &a)
{
    int z;
    for(int i=0;i<a.kolichestvo;i++)
    {
        for(int j=i+1;j<a.kolichestvo;j++)
        {
            SravnVr(a.b[i],a.b[j],z);
            if(z==1){Sort(a.b[i],a.b[j]);}
        }
    }
}
