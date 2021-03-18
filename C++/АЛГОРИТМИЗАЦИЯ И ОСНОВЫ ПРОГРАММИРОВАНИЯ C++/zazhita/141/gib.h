#ifndef GIB_H_INCLUDED
#define GIB_H_INCLUDED
#include <iostream>
using namespace std;
template <class one,class two,class three,class four,class five>
struct base
{
    one a;
    two b;
    three c;
    four d;
    five e;
};
template<class info>
struct Node
{
    info data;
    Node *next;
};
template<class B>
struct Stack
{
    Node<B> *node;
    int nkol;
};
template<class v>
void init(v &);
template <class l>
void show(l);
template <class v,class l>
void push(v &, l);
template <class v,class l>
void pop(v &,l &);
template <class v,class l>
void showallstack(v,l);

template <class data>
struct Node1
{
    Node1 *next;
    data d1;
};
template<class A>
struct Queue
{
    Node1<A> *head;
    Node1<A> *tail;
    int nkol;
};
template<class v>
void initque(v &);
template <class v,class l>
void equque(v &,l );
template <class v,class l>
void dequque(v &,l &);
template <class v,class l>
void showallqueue(v,l);

template <class dbase>
struct dinmass
{
    dbase *p;
    int nkol;
};
template<class k>
void initdin(k &);
template<class k,class j>
void Push_back(k &, j );
template<class k,class j>
void Pop_back(k &,j &);
template <class k,class j>
void showalldinmas(k,j);

template<class m,class men>
int cmpnum0(m, men);
template<class m,class men>
int cmpnum1(m, men);
template<class m,class men>
int cmpnum2(m, men);
template<class m,class men>
int cmpnum3(m, men);
template<class m,class men>
int cmpnum4(m, men);
template<class v,class k,class g>
void sorten(v &, int (*cmp)(k, g));

template<class v,class l,class st>
void Fileopread(l &,v &,st);
template<class v,class l,class st>
void FileWrite(l &,v,st);
#endif // GIB_H_INCLUDED
