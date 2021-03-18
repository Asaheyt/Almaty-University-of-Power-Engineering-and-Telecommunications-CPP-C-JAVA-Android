#include "uhu.h"
#include <iostream>
#include "cstring"
#include "stdio.h"
#include "fstream"
using namespace std;
void zp(Plastina &P,char *I,string Z,char *A,int T)
{
    strcpy(P.Ispolnitel,I);
    P.Zhanr=Z;
    strcpy(P.Albom,A);
    P.Tirazh=T;
}
void Init(Spisok &S)
{
    S.Nkol=0;
    S.P=NULL;
}
void ShowOne(Plastina P)
{
    cout<<"Исполнитель: "<<P.Ispolnitel;
    cout<<" Жанр: "<<P.Zhanr;
    cout<<" Альбом: "<<P.Albom;
    cout<<" Тираж: "<<P.Tirazh<<endl;
}
void Push_back(Spisok &S,Plastina p)
{
    Plastina *temp=new Plastina[S.Nkol+1];
    copy(S.P,S.P+S.Nkol,temp);
    delete S.P;
    S.P=new Plastina[S.Nkol+1];
    copy(temp,temp+S.Nkol,S.P);
    S.P[S.Nkol] = p;
    S.Nkol++;
    delete temp;
}
void Pop_back(Spisok &S,Plastina &p)
{
    if(S.Nkol>0)
    {
        Plastina *temp=new Plastina[S.Nkol];
        copy(S.P,S.P+S.Nkol-1,temp);
        delete S.P;
        S.P=new Plastina[S.Nkol];
        copy(temp,temp+S.Nkol-1,S.P);
        S.Nkol--;
        delete temp;
    }
    else {cout<<"Массив пуст."<<endl;}
}
void Show(Spisok S)
{
    if(S.Nkol>0)
    {
        for(int i=0;i<S.Nkol;i++)
        {
            ShowOne(S.P[i]);
        }
    }
    else {cout<<"Массив пуст."<<endl;}
    cout<<endl;
}
void Swapzn(Plastina &c,Plastina &v)
{
    Plastina t;
    t=c;
    c=v;
    v=t;
}
int SravnIsp(Plastina c,Plastina v)
{
    int z;
    z=strcmp(c.Ispolnitel,v.Ispolnitel);
    return z;
}
int SravnZha(Plastina c,Plastina v)
{
    int w,x,z;
    string a,b,e,d,f,g;
    a="New_age";
    b="Pop";
    e="Reggy";
    d="Rock-n-Roll";
    f=c.Zhanr;
    g=v.Zhanr;
    if(f==a){w=1;}
    if(f==b){w=2;}
    if(f==e){w=3;}
    if(f==d){w=4;}

    if(g==a){x=1;}
    if(g==b){x=2;}
    if(g==e){x=3;}
    if(g==d){x=4;}

    if(w>x){z=1;}
    if(w<x){z=-1;}
    if(w==x){z=-2;}
    return z;
}
int SravnAlb(Plastina c,Plastina v)
{
    int z;
    z=strcmp(c.Albom,v.Albom);
    return z;
}
int SravnTir(Plastina c,Plastina v)
{
    int z;
    if(c.Tirazh<v.Tirazh){z=-1;}
    if(c.Tirazh>v.Tirazh){z=1;}
    if(c.Tirazh==v.Tirazh){z=-2;}
    return z;
}
void Sort(Spisok &S,int (*CmpSrav)(Plastina, Plastina))
{
    for(int i=0;i<S.Nkol-1;i++)
    {
        for(int j=i+1;j<S.Nkol;j++)
        {
            if(CmpSrav(S.P[i],S.P[j])>0){Swapzn(S.P[i],S.P[j]);}
        }
    }
}
void MenuSort(Spisok &S)
{
    CmpSrav a;
    cout<<" Сортировка по исполнителю;"<<endl;
    a=SravnIsp;Sort(S,a);Show(S);
    cout<<" Сортировка по жанру;"<<endl;
    a=SravnZha;Sort(S,a);Show(S);
    cout<<" Сортировка по альбому;"<<endl;
    a=SravnAlb;Sort(S,a);Show(S);
    cout<<" Сортировка по тиражу."<<endl;
    a=SravnTir;Sort(S,a);Show(S);
}
//------------------------------------------------------------
void Fileopread(Plastina &p,Spisok &S,string s)
{
    ifstream rfile(s.c_str());
    while(!(rfile.eof()))
    {
        rfile>>p.Ispolnitel>>p.Zhanr>>p.Albom>>p.Tirazh;
        Push_back(S,p);
    }
    rfile.close();
}
void FileWrite(Plastina &p,Spisok S,string s)
{
    ofstream wfile(s.c_str());
    for(int i=0;i<S.Nkol;i++)
    {
        p=S.P[i];
        wfile<<p.Ispolnitel<<" "<<p.Zhanr<<" "<<p.Albom<<" "<<p.Tirazh;
        if(i<S.Nkol-1){wfile<<endl;}
    }
    wfile.close();
}











