#ifndef RAS_H_INCLUDED
#define RAS_H_INCLUDED
#include <iostream>
using namespace std;
#define NMAX 100
struct Rabotnik
{
    int zarplata;
    int chasi;        //kolichestvo rabochih chasov v nedelu
    string rang;
    string dolzhnost;
    float vremya;         //raboti c nachala

};
struct Organizacia
{
    string name;
    int kolichestvo;    //rabotnikov
    Rabotnik *b;

};
void AddEl(Organizacia &);
void DelEl(Organizacia &);
void show(Rabotnik);
void init(Organizacia &);
void Fill(Organizacia &);
void Erase(Organizacia &);
void ShowYONKO(Organizacia);
void SravnZAR(Rabotnik,Rabotnik,int &);
void SravnChas(Rabotnik,Rabotnik,int &);
void SravnRang(Rabotnik,Rabotnik,int &);
void SravnDol(Rabotnik,Rabotnik,int &);
void SravnVr(Rabotnik,Rabotnik,int &);
void Sort(Rabotnik &, Rabotnik &);
void OtsortZar(Organizacia &);
void OtsortChas(Organizacia &);
void OtsortRang(Organizacia &);
void OtsortDol(Organizacia &);
void OtsortVr(Organizacia &);
#endif // RAS_H_INCLUDED
