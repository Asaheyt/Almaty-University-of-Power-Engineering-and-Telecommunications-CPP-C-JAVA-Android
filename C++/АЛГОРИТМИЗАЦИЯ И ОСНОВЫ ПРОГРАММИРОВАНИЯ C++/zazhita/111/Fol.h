#ifndef FOL_H_INCLUDED
#define FOL_H_INCLUDED
#define NMAX 10000
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
    char Familiya[50];
    string Dolzhnost;
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
void Proverka(Organizacia);
void SravMas(Organizacia &,int (*CmpSrav)(Rabotnik, Rabotnik),int &);
void Fill(Organizacia &,Rabotnik &);
void Fileopread(ifstream &,Rabotnik &,Organizacia &,string);
void FileWrite(ofstream &,Rabotnik &,Organizacia,string);
void Init(Organizacia &);
void Add(Organizacia &,Rabotnik);
void Add2(Organizacia &,Rabotnik);
void ShowAll(Organizacia);
void ShowAll2(Organizacia);
void ShowOne(Rabotnik);
void Swapzn(Rabotnik &,Rabotnik &);
void SortSt(Organizacia &,int (*CmpSrav)(Rabotnik,Rabotnik));
int SravnFam(Rabotnik,Rabotnik);
int SravnDol(Rabotnik,Rabotnik);
int SravnData(Rabotnik,Rabotnik);
int SravnSrok(Rabotnik,Rabotnik);
int SravnOkl(Rabotnik,Rabotnik);
void Konec(Organizacia &);
void fillTod(Today &);
void showTod(Today);
void res(Organizacia &, Today);
void opred(Organizacia, Today, int &, int &, int);
typedef (*CmpSrav)(Rabotnik,Rabotnik);
#endif // FOL_H_INCLUDED
