#ifndef ZON_H_INCLUDED
#define ZON_H_INCLUDED
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
struct Organizacia
{
    int kol;
    Rabotnik *R;
};
void zp(Rabotnik &,char *,string,int,int);
void Init(Organizacia &);
void ShowOne(Rabotnik);
void Push_back(Organizacia &,Rabotnik);
void Pop_back(Organizacia &,Rabotnik &);
void Clear(Organizacia &);
void Show(Organizacia);
void Swapzn(Rabotnik &,Rabotnik &);
void SortSt(Organizacia &,int (*CmpSrav)(Rabotnik,Rabotnik));
int SravnFam(Rabotnik,Rabotnik);
int SravnDol(Rabotnik,Rabotnik);
int SravnData(Rabotnik,Rabotnik);
int SravnSrok(Rabotnik,Rabotnik);
int SravnOkl(Rabotnik,Rabotnik);
typedef (*CmpSrav)(Rabotnik,Rabotnik);
void MenuSort(Organizacia &);
#endif // ZON_H_INCLUDED
