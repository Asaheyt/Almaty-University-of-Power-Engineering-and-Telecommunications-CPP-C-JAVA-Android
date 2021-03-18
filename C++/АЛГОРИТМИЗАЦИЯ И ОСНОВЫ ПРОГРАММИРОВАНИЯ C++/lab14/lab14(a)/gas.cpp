#include <iostream>
#include "gas.h"
#include <windows.h>
using namespace std;
template<class b>
void init(b &t)
{
    t.nmen = 0;
    t.node = NULL;
}
template <class random>
void show(random t)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << t.a <<" "<<t.b <<" "<<t.c <<" "<<t.v <<" "<<t.h<<endl;
}
template <class v,class l>
void push(v &t,l &y)
{
    Node<l> *s;
    s = new Node<l>;
    s->data = y;
    if(t.node != NULL){s->next = t.node;}
    t.node = s;
    t.nmen++;
}
template <class v,typename l>
void pop(v &t,l &y)
{
    Node<l> *s;
    s = t.node;
    y = s->data;
    t.node = s->next;
    delete s;
}
//---------------------------------------------//
template<class h,class n>
void equque(h &w,n x)
{
    Node1<n> *k;
    k = new Node1<n>;
    k->d1 = x;
    if(w.tail != NULL){w.tail->next = k;w.tail = k;}
    if(w.kmen == 0){w.tail = w.head = k;}
    if(w.kmen == 1){w.head->next = k;}
    w.kmen++;
}
template<class j,class i>
void dequque(j &k,i &t)
{
    Node1<i> *h;
    h = k.head;
    t = h->d1;
    k.head = k.head->next;
    delete h;
}
template<class j>
void initque(j &n)
{
    n.kmen = 0;
    n.head = NULL;
    n.tail = n.head;
}
template<class p>
void initdin(p &tu)
{
    tu.p = NULL;
    tu.n = 0;
}
template<class v,class d>
void push_back(v &tu,d p)
{
    d *temp = new d[tu.n];
    copy(tu.p,tu.p+tu.n,temp);
    delete[] tu.p;
    tu.p = new d[tu.n + 1];
    copy(temp,temp + tu.n,tu.p);
    tu.p[tu.n] = p;
    tu.n = tu.n + 1;
    delete[] temp;
}
template<class h,class d>
void pop_back(h &tu,d &s)
{
    if(tu.n > 0){
        d *temp = new d[tu.n];
        copy(tu.p,tu.p+tu.n-1,temp);
        delete[] tu.p;
        tu.p = new d[tu.n];
        copy(temp,temp+tu.n,tu.p);
        tu.n--;
        delete[] temp;
    }
}

