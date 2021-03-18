#ifndef KMKZ_H_INCLUDED
#define KMKZ_H_INCLUDED
#define NMAX 10000
#include "string"
#include <iostream>
using namespace std;
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
    string name;
    int Kol1;
    Rabotnik *e1[NMAX];
};
void Fileopread(ifstream &,Organizacia &,string);
void FileWrite(ofstream &,Rabotnik &,Organizacia,string);
void FileAddEl(ofstream &,Rabotnik &,Organizacia &,string);
void FileClean(ofstream &,Organizacia &,string);
void FileClean2(ofstream &,string);
void DelEl(ofstream &,Rabotnik &,Organizacia &,string);
void Close(ofstream &,ifstream &);
void New(ofstream &,Organizacia &,Rabotnik &,string);
bool Empty(ifstream &,string);
//-----------------------------------------------------
void MenuSort(Organizacia &);
void Init(Organizacia &);
void zp(Rabotnik &);
void Add(Organizacia &,Rabotnik);
void ShowAll(Organizacia);
void ShowOne(Rabotnik);
void Swapzn(Rabotnik &,Rabotnik &);
void SortSt(Organizacia &,int (*CmpSrav)(Rabotnik,Rabotnik));
int SravnFam(Rabotnik,Rabotnik);
int SravnDol(Rabotnik,Rabotnik);
int SravnData(Rabotnik,Rabotnik);
int SravnSrok(Rabotnik,Rabotnik);
int SravnOkl(Rabotnik,Rabotnik);
typedef (*CmpSrav)(Rabotnik,Rabotnik);

#endif
