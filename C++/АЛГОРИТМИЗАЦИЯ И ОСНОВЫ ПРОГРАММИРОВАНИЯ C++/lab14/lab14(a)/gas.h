#ifndef GAS_H_INCLUDED
#define GAS_H_INCLUDED
#include <iostream>
using namespace std;
template <class one,class two,class three,class four,class five>
struct random
{
    one a;
    two b;
    three c;
    four h;
    five v;
};
template<class random>
struct Node
{
     Node *next;
     random data;

};
template<class B>
struct Stack
{
    Node<B> *node;
    int nmen;
};
template<class b>
void init(b &);
template <class random>
void show(random );
template <class v,class l>
void push(v &, l &);
template <typename v,typename l>
void pop(v &,l &);
//------------------------------------------
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
    int kmen;
};
template<class j>
void initque(j &);
template <class v,class l>
void equque(v &,l );
template <class v,class l>
void dequque(v &,l &);
//----------------------------------------
template <class random>
struct dinmassrandom
{
    random *p;
    int n;
};
template<class k>
void initdin(k &);
template<class k,class j>
void push_back(k &, j );
template<class h,class d>
void pop_back(h &,d &);
#endif // GAS_H_INCLUDED
