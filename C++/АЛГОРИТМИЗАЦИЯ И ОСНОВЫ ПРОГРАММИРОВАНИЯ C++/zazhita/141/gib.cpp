#include <iostream>
#include "gib.h"
#include <windows.h>
#include "cstdlib"
#include "cstdio"
#include "fstream"
using namespace std;
template<class v>
void init(v &t)
{
    t.nkol = 0;
    t.node = NULL;
}
template <class l>
void show(l t)
{
    cout << t.a <<" "<<t.b <<" "<<t.c <<" "<<t.d <<" "<<t.e<<endl;
}
template <class v,class l>
void push(v &t,l y)
{
    Node<l> *s;
    s = new Node<l>;
    s->data = y;
    if(t.node != NULL){s->next = t.node;}
    t.node = s;
    t.nkol++;
}
template <class v,typename l>
void pop(v &t,l &y)
{
    Node<l> *s;
    s = t.node;
    y = s->data;
    t.node = s->next;
    t.nkol--;
    delete s;
}
template <class v,class l>
void showallstack(v t,l y)
{
    int k=t.nkol;
    for(int i=0;i<k;i++)
    {
        pop(t,y);
        show(y);
    }
    cout<<endl;
}

template<class v,class l>
void equque(v &w,l x)
{
    Node1<l> *k;
    k = new Node1<l>;
    k->d1 = x;
    if(w.tail != NULL){w.tail->next = k;w.tail = k;}
    if(w.nkol == 0){w.tail = w.head = k;}
    if(w.nkol == 1){w.head->next = k;}
    w.nkol++;
}
template<class v,class l>
void dequque(v &k,l &t)
{
    Node1<l> *h;
    h = k.head;
    t = h->d1;
    k.head = k.head->next;
    delete h;
    k.nkol--;
}
template<class v>
void initque(v &n)
{
    n.nkol = 0;
    n.head = NULL;
    n.tail = n.head;
}
template <class v,class l>
void showallqueue(v t,l y)
{
    int k=t.nkol;
    for(int i=0;i<k;i++)
    {
        dequque(t,y);
        show(y);
    }
    cout<<endl;
}

template<class k>
void initdin(k &tu)
{
    tu.p = NULL;
    tu.nkol = 0;
}
template<class k,class j>
void Push_back(k &tu,j p)
{
    j *temp = new j[tu.nkol+1];
    copy(tu.p,tu.p+tu.nkol,temp);
    delete tu.p;
    tu.p = new j[tu.nkol + 1];
    copy(temp,temp + tu.nkol,tu.p);
    tu.p[tu.nkol] = p;
    tu.nkol++;
    delete temp;
}
template<class k,class j>
void Pop_back(k &tu,j &s)
{
    if(tu.nkol > 0)
    {
        s=tu.p[tu.nkol-1];
        j *temp = new j[tu.nkol];
        copy(tu.p,tu.p+tu.nkol-1,temp);
        delete tu.p;
        tu.p = new j[tu.nkol];
        copy(temp,temp+tu.nkol-1,tu.p);
        delete temp;
        tu.nkol--;
    }
}
template <class k,class j>
void showalldinmas(k t,j y)
{
    int l=t.nkol;
    for(int i = 0;i < l;i++)
    {
        show(t.p[i]);
    }
    cout<<endl;
}
template<class g,class h>
int cmpnum0(g d, h s)
{
 int ind;
    if(d.a > s.a)
    {
        ind = -1;
    }
    else if(d.a < s.a)
    {
        ind =  1;
    }
    return ind;
}
template<class g,class h>
int cmpnum1(g d, h s)
{
 int ind;
    if(d.b > s.b)
    {
        ind = -1;
    }
    else if(d.b < s.b)
    {
        ind =  1;
    }
    return ind;
}
template<class g,class h>
int cmpnum2(g d, h s)
{
 int ind;
    if(d.c > s.c)
    {
        ind = -1;
    }
    else if(d.c < s.c)
    {
        ind =  1;
    }
    return ind;
}
template<class g,class h>
int cmpnum3(g d, h s)
{
 int ind;
    if(d.d > s.d)
    {
        ind = -1;
    }
    else if(d.d < s.d)
    {
        ind =  1;
    }
    return ind;
}
template<class g,class h>
int cmpnum4(g d, h s)
{
 int ind;
    if(d.e > s.e)
    {
        ind = -1;
    }
    else if(d.e < s.e)
    {
        ind =  1;
    }
    return ind;
}
template<class v,class k,class r>
void sorten(v &tu,int (*cmp)(k , r))
{
    for(int i = 0;i < tu.nkol-1;i++)
    {
        for(int j = i + 1;j < tu.nkol;j++)
        {

            if(cmp(tu.p[i],tu.p[j]) < 0)
            {
                swap(tu.p[i],tu.p[j]);
            }
        }
    }
}

