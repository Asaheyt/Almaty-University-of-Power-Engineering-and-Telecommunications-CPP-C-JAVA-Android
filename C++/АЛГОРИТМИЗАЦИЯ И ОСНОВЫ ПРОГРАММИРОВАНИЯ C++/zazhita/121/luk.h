#ifndef LUK_H_INCLUDED
#define LUK_H_INCLUDED
#define NMAX 10000
#include "string"
#include <iostream>
using namespace std;
struct DATA
{
    int day;
    int month;
    int year;
};
struct Rabotnik
{
    char Familiya[50];
    string Dolzhnost;
    DATA D1;
    int Srok;
    int Oklad;
};
void ShowOne(Rabotnik);
void zp(Rabotnik &,char *,string,int,int,int,int,int);
struct Node
{
    Rabotnik data;
    Node *next;
};
struct Stack
{
    Node *node;
    int NRab;
};
void InitStack(Stack &);
void Push(Stack &,Rabotnik);
void ShowStack(Stack,Rabotnik);
void Pop(Stack &,Rabotnik &);
struct Queue
{
    Node *head;
    Node *tail;
    int NRab;
};
void InitQueue(Queue &);
void enqueue(Queue &,Rabotnik);
void dequeue(Queue &,Rabotnik &);
void ShowQueue(Queue,Rabotnik);
#endif // LUK_H_INCLUDED
