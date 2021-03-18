#include "luk.h"
#include <iostream>
#include "cstring"
#include <fstream>
using namespace std;
void zp(Rabotnik &R,char *F,string Z,int D,int M,int Y,int S,int O)
{
    strcpy(R.Familiya,F);
    R.Dolzhnost=Z;
    R.D1.day=D;
    R.D1.month=M;
    R.D1.year=Y;
    R.Srok=S;
    R.Oklad=O;
}
void ShowOne(Rabotnik r)
{
    cout<<"Фамилия работника: "<<r.Familiya;
    cout<<" Должность: "<<r.Dolzhnost;
    cout<<" Дата подписания контракта: "<<r.D1.day<<"."<<r.D1.month<<"."<<r.D1.year;
    cout<<" Срок действия контракта: "<<r.Srok;
    cout<<" Оклад: "<<r.Oklad<<endl;
}
void InitStack(Stack &s2)
{
    s2.NRab=0;
    s2.node=NULL;
}
void Push(Stack &s2,Rabotnik R)
{
    Node *d;
    d = new Node;
    d->data = R;
    if((s2.node != NULL) || (s2.NRab != 0)){d->next = s2.node;}
    s2.node = d;
    s2.NRab++;
}
void Pop(Stack &s2,Rabotnik &R)
{
    if(s2.NRab==0){cout<<"В стеке пусто"<<endl;}
    else
    {
        Node *d;
        d = s2.node;
        R = d->data;
        s2.node = d->next;
        if(s2.NRab > 0){s2.NRab--;}
        delete d;
    }
}
void ShowStack(Stack b,Rabotnik R)
{
    if(b.NRab==0){cout<<"В стеке пусто"<<endl;}
    else
    {
        int k;
        k=b.NRab;
        for(int i = 0;i < k ;i++)
        {
            Pop(b,R);
            ShowOne(R);
        }
    }
}
void InitQueue(Queue &Q)
{
    Q.NRab=0;
    Q.head=NULL;
    Q.tail=Q.head;
}
void enqueue(Queue &Q,Rabotnik R)
{
    Node *d;
    d = new Node;
    d->data = R;
    d->next=NULL;
    if((Q.tail != NULL) || (Q.NRab != 0)){Q.tail->next=d;Q.tail = d;}
    if(Q.NRab==0){Q.tail=Q.head=d;}
    if(Q.NRab==1){Q.head->next=Q.tail;}
    Q.NRab++;
}
void dequeue(Queue &Q,Rabotnik &R)
{
    if(Q.NRab==0){cout<<"В очереди пусто"<<endl;}
    else
    {
        Node *d;
        d = Q.head;
        R = d->data;
        Q.head = Q.head->next;
        if(Q.NRab > 0){Q.NRab--;}
        delete d;
    }
}
void ShowQueue(Queue c,Rabotnik R)
{
    if(c.NRab==0){cout<<"В очереди пусто"<<endl;}
    else
    {
        int k;
        k=c.NRab;
        for(int i = 0;i < k ;i++)
        {
            dequeue(c,R);
            ShowOne(R);
        }
    }
}
