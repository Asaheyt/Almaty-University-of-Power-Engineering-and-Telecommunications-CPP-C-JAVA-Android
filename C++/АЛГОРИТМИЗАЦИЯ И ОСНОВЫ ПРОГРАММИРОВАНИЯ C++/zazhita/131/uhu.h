#ifndef UHU_H_INCLUDED
#define UHU_H_INCLUDED
#include <iostream>
using namespace std;
struct Plastina
{
    char Ispolnitel[50];
    string Zhanr;
    char Albom[50];
    int Tirazh;
};
struct Spisok
{
    Plastina *P;
    int Nkol;
};
void zp(Plastina &,char *,string,char *,int);
void Init(Spisok &);
void ShowOne(Plastina);
void Push_back(Spisok &,Plastina);
void Pop_back(Spisok &,Plastina &);
void Show(Spisok);
void MenuSort(Spisok &);
void Swapzn(Plastina &,Plastina &);
int SravnIsp(Plastina,Plastina);
int SravnZha(Plastina,Plastina);
int SravnAlb(Plastina,Plastina);
int SravnTir(Plastina,Plastina);
typedef (*CmpSrav)(Plastina, Plastina);
void Fileopread(Plastina &,Spisok &,string);
void FileWrite(Plastina &,Spisok,string);

#endif // UHU_H_INCLUDED
