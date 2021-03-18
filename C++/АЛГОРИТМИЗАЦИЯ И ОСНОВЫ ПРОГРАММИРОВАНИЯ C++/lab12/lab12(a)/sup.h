#ifndef SUP_H_INCLUDED
#define SUP_H_INCLUDED
#define NMAX 10000
#include "string"
#include <iostream>
using namespace std;
struct Rabotnik
{
    char Familiya[50];
    string Dolzhnost;
    int Srok;
    int Oklad;
};
void ShowOne(Rabotnik);
void zp(Rabotnik &,char *,string,int,int);
//------------------------------------------
struct Stack1
{
    Rabotnik a[NMAX];
    int nRab;
};
void Init(Stack1 &);
void Push1(Stack1 &,Rabotnik);
void Pop1(Stack1 &,Rabotnik &);
//------------------------------------------
struct Node
{
    Rabotnik data;
    Node *next;
};
struct Stack2
{
    Node *node;
    int NRab;
};
void Init2(Stack2 &);
void Push2(Stack2 &,Rabotnik);
void Pop2(Stack2 &,Rabotnik &);
//--------------------------------------------
void enqueue(Stack2 &,Rabotnik);
void dequeue(Stack2 &,Rabotnik &);
#endif // SUP_H_INCLUDED
