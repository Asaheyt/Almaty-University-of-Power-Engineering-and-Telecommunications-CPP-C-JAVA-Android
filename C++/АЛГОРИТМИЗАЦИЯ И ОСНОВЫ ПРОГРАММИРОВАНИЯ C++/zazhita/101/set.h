#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
#define NMAX 100
#include "string"
#include <iostream>
using namespace std;
struct Today
{
    int day;
    int month;
    int year;
};
struct Data
{
    int day;
    int month;
    int year;
};
struct Rabotnik
{
    char *Familiya;
    char *Dolzhnost;
    Data D1;
    int Srok;
    int Oklad;
};
struct Organizacia
{
    int Kol1;
    int Kol2;
    Rabotnik *e1[NMAX];
    Rabotnik *e2[NMAX];
};
void Init(Organizacia &);
void Add(Organizacia &,Rabotnik);
void Fill(Organizacia &,Rabotnik &);
void ShowAll(Organizacia);
void ShowOne(Rabotnik);
void fillTod(Today &);
void showTod(Today);
void Add2(Organizacia &,int);
void res(Organizacia &, Today);
void opred(Organizacia, Today, int &, int &, int);
void ShowAll2(Organizacia);
void Swapzn(Rabotnik &,Rabotnik &);
void SortFam(Organizacia &);
void SortDol(Organizacia &);
void SortData(Organizacia &);
void SortSrok(Organizacia &);
void SortOkl(Organizacia &);
int SravnFam(Rabotnik,Rabotnik);
int SravnDol(Rabotnik,Rabotnik);
int SravnData(Rabotnik,Rabotnik);
int SravnSrok(Rabotnik,Rabotnik);
int SravnOkl(Rabotnik,Rabotnik);
#endif // SET_H_INCLUDED
