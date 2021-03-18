#ifndef RAS_H_INCLUDED
#define RAS_H_INCLUDED
#include <iostream>
using namespace std;
#define NMAX 100
typedef int in;
typedef float fl;
typedef string st;
struct Rabotnik
{
    in zarplata;
    in chasi;        //kolichestvo rabochih chasov v nedelu
    st rang;
    st dolzhnost;
    fl vremya;         //raboti c nachala

};
struct Organizacia
{
    st name;
    in kolichestvo;    //rabotnikov
    Rabotnik *b[NMAX];

};
void AddEl(Organizacia &,Rabotnik &,in &);
void DelEl(Organizacia &);
void show(Rabotnik);
void init(Organizacia &);
void zp(Rabotnik &,in &);
void ShowYONKO(Organizacia);
void SravnZAR(Rabotnik,Rabotnik,in &);
void SravnChas(Rabotnik,Rabotnik,in &);
void SravnRang(Rabotnik,Rabotnik,in &);
void SravnDol(Rabotnik,Rabotnik,in &);
void SravnVr(Rabotnik,Rabotnik,in &);
void Sort(Rabotnik &, Rabotnik &);
void OtsortZar(Organizacia &);
void OtsortChas(Organizacia &);
void OtsortRang(Organizacia &);
void OtsortDol(Organizacia &);
void OtsortVr(Organizacia &);
#endif // RAS_H_INCLUDED
