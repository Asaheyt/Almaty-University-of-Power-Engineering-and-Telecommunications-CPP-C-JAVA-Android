#include "sup.h"
#include <iostream>
#include "cstring"
#include <fstream>
using namespace std;
void zp(Rabotnik &R,char *F,string D,int S,int O)
{
    strcpy(R.Familiya,F);
    R.Dolzhnost=D;
    R.Srok=S;
    R.Oklad=O;
}
void Init(Stack1 &s1)
{
    s1.nRab=0;
}
void ShowOne(Rabotnik r)
{
    cout<<"Фамилия работника: "<<r.Familiya;
    cout<<" Должность: "<<r.Dolzhnost;
    cout<<" Срок действия контракта: "<<r.Srok;
    cout<<" Оклад: "<<r.Oklad<<endl;
}
void Push1(Stack1 &s1,Rabotnik R)
{
    s1.a[s1.nRab] = R;
    s1.nRab++;
}
void Pop1(Stack1 &s1,Rabotnik &R)
{
        R = s1.a[s1.nRab-1];
        s1.nRab--;
}
//--------------------------------------------------------
void Init2(Stack2 &s2)
{
    s2.NRab=0;
    s2.node=NULL;
}
void Push2(Stack2 &s2,Rabotnik R)
{
    Node *d;
    d = new Node;
    d->data = R;
    if((s2.node != NULL) || (s2.NRab != 0)){d->next = s2.node;}
    s2.node = d;
    s2.NRab++;
}
void Pop2(Stack2 &s2,Rabotnik &R)
{
    Node *d;
    d = s2.node;
    R = d->data;
    s2.node = d->next;
    if(s2.NRab > 0){s2.NRab--;}
    delete d;
}
//-----------------------------------------------------------------
void enqueue(Stack2 &st3,Rabotnik R)
{
    Push2(st3,R);
}
void dequeue(Stack2 &st3,Rabotnik &R)
{
    Stack2 V;
    Init2(V);
    Rabotnik E;
    int k;
    k=st3.NRab;
    for(int i=0;i<k;i++)
    {
       Pop2(st3,E);Push2(V,E);
    }
    Pop2(V,R);
    k=V.NRab;
    for(int i=0;i<k;i++)
    {
       Pop2(V,E);Push2(st3,E);
    }
}
